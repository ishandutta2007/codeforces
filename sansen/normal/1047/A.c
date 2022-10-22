#include<stdio.h>

void run(void){
  int n;
  scanf("%d",&n);
  if((n-2)%3!=0){
    printf("%d %d %d\n",1,1,n-2);
  } else {
    printf("%d %d %d\n",1,2,n-3);
  }
}

int main(void){
  run();
  return 0;
}