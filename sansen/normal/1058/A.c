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
  int c[100];
  int i;
  for(i=0;i<n;i++) scanf("%d",c+i);
  for(i=0;i<n;i++){
    if(c[i]==1){
      printf("HARD\n");
      return;
    }
  }
  printf("EASY\n");
}

int main(void){
  run();
  return 0;
}