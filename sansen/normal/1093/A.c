#include<stdio.h>

void run(void){
  int t;
  scanf("%d",&t);
  while(t--){
    int x;
    scanf("%d",&x);
    printf("%d\n",x/2);
  }
}

int main(void){
  run();
  return 0;
}