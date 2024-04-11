#include<stdio.h>

typedef long long int int64;

void run(void){
  int n,k;
  scanf("%d%d",&n,&k);
  int ans=(2*n+k-1)/k+(5*n+k-1)/k+(8*n+k-1)/k;
  printf("%d\n",ans);
}

int main(void){
  run();
  return 0;
}