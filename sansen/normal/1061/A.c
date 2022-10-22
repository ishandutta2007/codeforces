#include<stdio.h>

void run(void){
  int n,s;
  scanf("%d%d",&n,&s);
  printf("%d\n",(s+n-1)/n);
}

int main(void){
  run();
  return 0;
}