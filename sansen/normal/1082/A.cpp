#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

int gcd(int a,int b){
  int r=a%b;
  while(r>0){
    a=b;b=r;r=a%b;
  }
  return b;
}

int calc(int n,int x,int y,int d){
  if(ABS(x-y)%d==0) return ABS(x-y)/d;
  int min=2*n;
  if((y-1)%d==0) min=(x-1+d-1)/d+(y-1)/d;
  if((n-y)%d==0) min=MIN(min,(n-x+d-1)/d+(n-y)/d);
  return min==2*n?-1:min;
}

void run(void){
  int t;
  scanf("%d",&t);
  while(t--){
    int n,x,y,d;
    scanf("%d%d%d%d",&n,&x,&y,&d);
    printf("%d\n",calc(n,x,y,d));
  }
}

int main(void){
  run();
  return 0;
}