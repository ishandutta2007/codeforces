#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  int w,l
    ;
  scanf("%d%d",&w,&l);
  int a[100000];
  int i;
  for(i=1;i<w;i++) scanf("%d",a+i);
  int s=0;
  for(i=1;i<=l;i++) s+=a[i];
  int min=s;
  for(i=l+1;i<w;i++){
    s=s-a[i-l]+a[i];
    min=MIN(min,s);
  }
  printf("%d\n",min);
}

int main(void){
  run();
  return 0;
}