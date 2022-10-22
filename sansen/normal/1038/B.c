#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  int n;
  scanf("%d",&n);
  if(n<=2){
    printf("No\n");
    return;
  }
  printf("Yes\n");
  int g=n%2==0?n/2:(n/2+1);
  printf("%d %d\n",1,g);
  printf("%d ",n-1);
  int i;
  for(i=1;i<=n;i++) if(i!=g) printf("%d ",i);
  printf("\n");
}

int main(void){
  run();
  return 0;
}