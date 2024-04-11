#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  int k,n,s,p;
  scanf("%d%d%d%d",&k,&n,&s,&p);
  int64 sheet=(int64)(n+s-1)/s;
  int64 ans=(sheet*k+p-1)/p;
  printf("%lld\n",ans);
  return;
}

int main(void){
  run();
  return 0;
}