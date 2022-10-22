#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

int calc(int k,int *p){
  if(p[k]<0) return k;
  int n=p[k];
  p[k]=-n;;
  int res=calc(n,p);
  p[k]=n;
  return res;
}

void run(void){
  int n;
  scanf("%d",&n);
  int *p=(int *)malloc(sizeof(int)*(n+1));
  int i;
  for(i=1;i<=n;i++) scanf("%d",p+i);
  printf("%d",calc(1,p));
  for(i=2;i<=n;i++){
    printf(" %d",calc(i,p));
  }
  printf("\n");
}

int main(void){
  run();
  return 0;
}