#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  int n,m;
  scanf("%d%d",&n,&m);
  int64 e=0;
  int i;
  for(i=0;i<m;i++){
    int x,d;
    scanf("%d%d",&x,&d);
    e+=n*x;
    if(d>0){
      e+=(int64)d*(n-1)*n/2;
    } else {
      int mid=(n+1)/2;
      e+=(int64)d*(mid-1)*mid/2+(int64)d*(n-mid)*(n-mid+1)/2;
    }
  }
  printf("%.9lf\n",(double)e/n);
}

int main(void){
  run();
  return 0;
}