#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

void run(void){
  int n;
  scanf("%d",&n);
  int64 *x=(int64 *)calloc(n,sizeof(int64));
  int i;
  for(i=1;i<n;i+=2){
    scanf("%lld",x+i);
  }
  const int64 inf=10000000000000LL;
  int64 b=1;
  int64 a=2;
  int64 c=0;
  for(i=1;i<n;i+=2){
    while(a*a<=inf){
      if(a*a-b*b==x[i]) break;
      if(a*a-b*b<x[i]){
	a++;
      } else {
	b++;
      }
    }
    if(a*a>inf){
      printf("No\n");
      return;
    }
    x[i-1]=b*b-c*c;
    c=a;
    b=a+1;
  }
  printf("Yes\n");
  for(i=0;i<n;i++) printf("%lld ",x[i]);
  printf("\n");
}

int main(void){
  run();
  return 0;
}