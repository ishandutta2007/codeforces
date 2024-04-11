#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  int n,k;
  scanf("%d%d",&n,&k);
  int i;
  for(i=0;i<k;i++){
    if(n%10>0){
      n--;
    } else {
      n/=10;
    }
  }
  printf("%d\n",n);
}

int main(void){
  run();
  return 0;
}