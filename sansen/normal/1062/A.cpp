#include<stdio.h>

#define MAX(a,b) ((a)>(b)?(a):(b))

void run(void){
  int n;
  scanf("%d",&n);
  int a[100];
  int i;
  for(i=0;i<n;i++) scanf("%d",a+i);
  int ans=0;
  i=0;
  while(i<n && a[n-1-i]==1000-i) i++;
  ans=MAX(ans,i-1);
  i=0;
  while(i<n && a[i]==i+1) i++;
  ans=MAX(ans,i-1);
  while(i<n){
    int j=1;
    while(i+j<n && a[i+j]==a[i]+j) j++;
    ans=MAX(ans,j-2);
    i+=j;
  }
  printf("%d\n",ans);
}

int main(void){
  run();
  return 0;
}