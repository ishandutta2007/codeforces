#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  int64 n,m;
  scanf("%lld%lld",&n,&m);
  int64 k=1;
  while(k*(k+1)/2<=m) k++;
  int64 min=n>2*m?n-2*m:0;
  int64 max=m==0?n:(m==(k-1)*k/2?n-k:n-k-1);
  printf("%lld %lld\n",min,max);
}

int main(void){
  run();
  return 0;
}