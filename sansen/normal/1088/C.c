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
  int *a=(int *)calloc(n,sizeof(int));
  int i;
  for(i=0;i<n;i++) scanf("%d",a+i);
  printf("%d\n",n);
  printf("1 %d 800000\n",n);
  for(i=0;i<n;i++) a[i]+=800000;
  for(i=0;i<n-1;i++){
    printf("2 %d %d\n",i+1,a[i]-i);
  }
  return;
}

int main(void){
  run();
  return 0;
}