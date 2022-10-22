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
  int h,w;
  scanf("%d%d",&h,&w);
  int before=MAX(h,w);
  int i;
  for(i=1;i<n;i++){
    scanf("%d%d",&h,&w);
    int a=MAX(h,w);
    int b=MIN(h,w);
    if(before>=a){
      before=a;
    } else if(before>=b){
      before=b;
    } else {
      printf("NO\n");
      return;
    }
  }
  printf("YES\n");
  return;
}

int main(void){
  run();
  return 0;
}