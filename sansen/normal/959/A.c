#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

int calc(int n){
  if(n%2==0) return 1;
  return 0;
}

void run(void){
  int n;
  scanf("%d",&n);
  printf("%s\n",calc(n)?"Mahmoud":"Ehab");
  return;
}

int main(void){
  run();
  return 0;
}