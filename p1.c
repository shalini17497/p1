#include<stdio.h> 
 
int main() 
{ 
 
  int count,j,n,time,remain,flag=0,quantum; 
  int wait,turnaround=0,a[10],b[10],r[10]; 
  printf("Enter Total Process:\t "); 
  scanf("%d",&n); 
  remain=n; 
  for(count=0;count<n;count++) 
  { 
    printf("Enter Arrival Time and Burst Time for Process Process Number %d :",count+1); 
    scanf("%d",&a[count]); 
    scanf("%d",&b[count]); 
    r[count]=b[count]; 
  } 
  printf("Enter Time Quantum:\t"); 
  scanf("%d",&quantum); 
  printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n"); 
  for(time=0,count=0;remain!=0;) 
  { 
    if(r[count]<=quantum && r[count]>0) 
    { 
      time+=r[count]; 
      r[count]=0; 
      flag=1; 
    } 
    else if(r[count]>0) 
    { 
      r[count]-=quantum; 
      time+=quantum; 
    } 
    if(r[count]==0 && flag==1) 
    { 
      remain--; 
      printf("P[%d]\t|\t%d\t|\t%d\n",count+1,time-a[count],time-a[count]-b[count]); 
      wait+=time-a[count]-b[count]; 
      turnaround+=time-a[count]; 
      flag=0; 
    } 
    if(count==n-1) 
      count=0; 
    else if(a[count+1]<=time) 
      count++; 
    else 
      count=0; 
  } 
  printf("\nAverage Waiting Time= %f\n",wait*1.0/n); 
  printf("Avg Turnaround Time = %f",turnaround*1.0/n); 
  
  return 0; 
}
