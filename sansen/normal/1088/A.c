#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  int x;
  scanf("%d",&x);
  int a,b;
  for(a=1;a<=x;a++){
    for(b=1;b<=x;b++){
      if(a%b==0 && a*b>x && a<x*b){
	printf("%d %d\n",a,b);
	return;
      }
    }
  }
  printf("-1\n");
}

int main(void){
  run();
  return 0;
}