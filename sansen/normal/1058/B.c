#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  int n,d;
  scanf("%d%d",&n,&d);
  int m;
  scanf("%d",&m);
  while(m--){
    int x,y;
    scanf("%d%d",&x,&y);
    if(y<=x+d && y>=x-d && y>=-x+d && y<=-x+2*n-d){
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
}

int main(void){
  run();
  return 0;
}