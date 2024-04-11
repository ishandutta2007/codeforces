#include<stdio.h>

typedef long long int int64;

void run(void){
  int64 n,k;
  scanf("%lld%lld",&n,&k);
  int64 ans=(k+n-1)/n;
  printf("%lld\n",ans);
}

int main(void){
  run();
  return 0;
}