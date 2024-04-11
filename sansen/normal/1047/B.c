#include<stdio.h>

void run(void){
  int n;
  scanf("%d",&n);
  int max=0;
  while(n--){
    int x,y;
    scanf("%d%d",&x,&y);
    if(x+y>max) max=x+y;
  }
  printf("%d\n",max);
}

int main(void){
  run();
  return 0;
}