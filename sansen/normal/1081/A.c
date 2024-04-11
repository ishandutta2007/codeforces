#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  int v;
  scanf("%d",&v);
  if(v==2){
    printf("2\n");
  } else {
    printf("1\n");
  }
}

int main(void){
  run();
  return 0;
}