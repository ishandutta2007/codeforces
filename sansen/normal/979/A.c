#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  int64 n;
  scanf("%lld",&n);
  if(n==0){
    printf("0\n");
    return;
  }
  int64 m=n+1;
  printf("%lld\n",m%2==0?m/2:m);
  return;
}

int main(void){
  run();
  return 0;
}