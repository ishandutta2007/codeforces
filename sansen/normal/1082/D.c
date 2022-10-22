#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

int can(int *a,int n){
  int c1=0;
  int c2=0;
  int sum=0;
  int i;
  for(i=1;i<=n;i++){
    if(a[i]==1){
      c1++;
    } else {
      c2++;
      sum+=a[i];
    }
  }
  return c1<=sum-2*(c2-1);
}

void run(void){
  int n;
  scanf("%d",&n);
  int a[501];
  int i;
  for(i=1;i<=n;i++) scanf("%d",a+i);
  if(!can(a,n)){
    printf("NO\n");
    return;
  }
  int b[501];
  int c[501];
  int len=0;
  for(i=1;i<=n;i++){
    if(a[i]>1){
      b[len]=i;
      c[len]=a[i];
      len++;
    }
  }
  printf("YES %d\n",len>=n-2?n-1:len-1+2);
  printf("%d\n",n-1);
  for(i=0;i+1<len;i++){
    printf("%d %d\n",b[i],b[i+1]);
    c[i]--;
    c[i+1]--;
  }
  int j=0;
  for(i=1;i<=n;i++){
    if(a[i]==1){
      while(c[j]==0) j++;
      printf("%d %d\n",i,b[j]);
      c[j]--;
      break;
    }
  }
  j=len-1;
  for(i=i+1;i<=n;i++){
    if(a[i]==1){
      while(c[j]==0) j--;
      printf("%d %d\n",i,b[j]);
      c[j]--;
      break;
    }
  }
  j=0;
  for(i=i+1;i<=n;i++){
    if(a[i]==1){
      while(c[j]==0) j++;
      printf("%d %d\n",i,b[j]);
      c[j]--;
    }
  }
}

int main(void){
  run();
  return 0;
}