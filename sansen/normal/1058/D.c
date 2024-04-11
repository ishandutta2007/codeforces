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
    a=b;
    b=r;
    r=a%b;
  }
  return b;
}

void run(void){
  int n,m,k;
  scanf("%d%d%d",&n,&m,&k);
  int x=n;
  int y=m;
  int g=gcd(x,k);
  x/=g;
  k/=g;
  g=gcd(y,k);
  y/=g;
  k/=g;
  if(k!=1 && k!=2){
    printf("NO\n");
    return;
  }
  printf("YES\n");
  if(k==1){
    if(x*2<=n){
      x*=2;
    } else {
      y*=2;
    }
  }
  printf("0 0\n");
  printf("%d 0\n",x);
  printf("0 %d\n",y);
}

int main(void){
  run();
  return 0;
}