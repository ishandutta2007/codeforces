#include<stdio.h>

#define MIN(a,b) ((a)<(b)?(a):(b))

void run(void){
  int n,a,b;
  scanf("%d%d%d",&n,&a,&b);
  int c[20];
  int i;
  for(i=0;i<n;i++) scanf("%d",c+i);
  int sum=0;
  for(i=0;i<n-1-i;i++){
    if(c[i]==c[n-1-i]){
      if(c[i]==2) sum+=2*MIN(a,b);
    } else if(c[i]==2){
      sum+=c[n-1-i]==0?a:b;
    } else if(c[n-1-i]==2){
      sum+=c[i]==0?a:b;
    } else {
      printf("-1\n");
      return;
    }
  }
  if(n%2==1 && c[n/2]==2) sum+=MIN(a,b);
  printf("%d\n",sum);
}

int main(void){
  run();
  return 0;
}