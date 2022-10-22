#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

int64 calc(int x,int y,int n){
  if((x+y)%2==0){
    int64 res=0;
    res+=(int64)n*((x-1)/2);
    res+=(x%2==1?0:(n+1)/2);
    res+=(y+1)/2;
    return res;
  } else {
    int64 res=((int64)n*n+1)/2;
    res+=(int64)n*((x-1)/2);
    res+=(x%2==1?0:n/2);
    res+=(y+1)/2;
    return res;
  }
}

//n>0
void print64(int64 n){
  int d[20];
  int i=0;
  while(n>0){
    d[i++]=n%10;
    n/=10;
  }
  i--;
  while(i>=0){
    putchar('0'+d[i]);
    i--;
  }
  return;
}

void run(void){
  int n,q;
  scanf("%d%d",&n,&q);
  while(q--){
    int x,y;
    scanf("%d%d",&x,&y);
    printf("%lld\n",calc(x,y,n));
  }
}

int main(void){
  run();
  return 0;
}