#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  int n;
  scanf("%d",&n);
  int *l=(int *)malloc(sizeof(int)*n);
  int *r=(int *)malloc(sizeof(int)*n);
  int i;
  for(i=0;i<n;i++) scanf("%d%d",l+i,r+i);
  int *ll=(int *)malloc(sizeof(int)*n);
  int *lr=(int *)malloc(sizeof(int)*n);
  ll[0]=l[0];
  lr[0]=r[0];
  for(i=1;i<n;i++){
    ll[i]=MAX(ll[i-1],l[i]);
    lr[i]=MIN(lr[i-1],r[i]);
  }
  int *rl=(int *)malloc(sizeof(int)*n);
  int *rr=(int *)malloc(sizeof(int)*n);
  rl[n-1]=l[n-1];
  rr[n-1]=r[n-1];
  for(i=n-2;i>=0;i--){
    rl[i]=MAX(rl[i+1],l[i]);
    rr[i]=MIN(rr[i+1],r[i]);
  }
  int max=0;
  if(ll[n-2]<=lr[n-2]) max=MAX(max,lr[n-2]-ll[n-2]);
  if(rl[1]<=rr[1]) max=MAX(max,rr[1]-rl[1]);
  for(i=1;i<n-1;i++){
    int x=MAX(ll[i-1],rl[i+1]);
    int y=MIN(lr[i-1],rr[i+1]);
    if(x<=y) max=MAX(max,y-x);
  }
  printf("%d\n",max);
}

int main(void){
  run();
  return 0;
}