#include<stdio.h>

void run(void){
  int t;
  scanf("%d",&t);
  while(t--){
    int len,v,l,r;
    scanf("%d%d%d%d",&len,&v,&l,&r);
    int ans=len/v-r/v+(l-1)/v;
    printf("%d\n",ans);
  }
}

int main(void){
  run();
  return 0;
}