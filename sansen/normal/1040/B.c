#include<stdio.h>

void run(void){
  int n,k;
  scanf("%d%d",&n,&k);
  int d=2*k+1;
  int c=(n+d-1)/d;
  printf("%d\n",c);
  int i;
  if((c-1)*d+k+1<=n){
    for(i=1;i<=c;i++){
      printf("%d ",(i-1)*d+k+1);
    }
  } else {
    for(i=1;i<=c;i++){
      printf("%d ",(i-1)*d+1);
    }
  }
  printf("\n");
}

int main(void){
  run();
  return 0;
}