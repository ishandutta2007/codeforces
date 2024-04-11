#include<stdio.h>

int sum(int n){
  if(n<=0) return 0;
  return n%2==0?n/2:-(n+1)/2;
}

void run(void){
  int q;
  scanf("%d",&q);
  while(q--){
    int l,r;
    scanf("%d%d",&l,&r);
    printf("%d\n",sum(r)-sum(l-1));
  }
}

int main(void){
  run();
  return 0;
}