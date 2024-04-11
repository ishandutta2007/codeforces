#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  int n,s;
  scanf("%d%d",&n,&s);
  int h[100];
  int m[100];
  int i;
  for(i=0;i<n;i++) scanf("%d%d",h+i,m+i);
  int mm[100];
  for(i=0;i<n;i++) mm[i]=h[i]*60+m[i];

  if(0+s+1<=mm[0]){
    printf("0 0\n");
    return;
  }
  for(i=0;i+1<n;i++){
    if(mm[i+1]-mm[i]>=2*s+2){
      int t=mm[i]+s+1;
      int a=t/60;
      int b=t%60;
      printf("%d %d\n",a,b);
      return;
    }
  }
  int t=mm[n-1]+s+1;
  int a=t/60;
  int b=t%60;
  printf("%d %d\n",a,b);
  return;
}

int main(void){
  run();
  return 0;
}