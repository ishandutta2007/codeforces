#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  int n,a,b,c,tt;
  scanf("%d%d%d%d%d",&n,&a,&b,&c,&tt);
  int *t=(int *)malloc(sizeof(int)*n);
  int i;
  for(i=0;i<n;i++) scanf("%d",t+i);
  if(b>c){
    printf("%d\n",n*a);
  } else {
    int sum=0;
    for(i=0;i<n;i++){
      sum+=a+(c-b)*(tt-t[i]);
    }
    printf("%d\n",sum);
  }
  return;
}

int main(void){
  run();
  return 0;
}