#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  int t;
  scanf("%d",&t);
  while(t--){
    int s,a,b,c;
    scanf("%d%d%d%d",&s,&a,&b,&c);
    int64 cnt=s/c;
    int64 ans=cnt+(cnt/a)*b;
    printf("%lld\n",ans);
  }
}

int main(void){
  run();
  return 0;
}