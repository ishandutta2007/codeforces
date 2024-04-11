#include<stdio.h>

typedef long long int int64;

void run(void){
  int64 l,r;
  scanf("%lld%lld",&l,&r);
  printf("YES\n");
  int64 i;
  for(i=l;i<r;i+=2){
    printf("%lld %lld\n",i,i+1);
  }
}

int main(void){
  run();
  return 0;
}