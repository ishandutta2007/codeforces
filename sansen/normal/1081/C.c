#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

const int mod=998244353;

int64 comb(int n,int k){
  int64 nu=1;
  int64 de=1;
  int i;
  for(i=1;i<=k;i++){
    nu=nu*(n+1-i)%mod;
    de=de*i%mod;
  }
  int64 t=1;
  int64 a=de;
  while(a>1){
    t=t*(mod-mod/a)%mod;
    a=mod%a;
  }
  return nu*t%mod;
}

void run(void){
  int n,m,k;
  scanf("%d%d%d",&n,&m,&k);
  int64 ans=(int64)comb(n-1,k)*m%mod;
  for(int i=1;i<=k;i++) ans=ans*(m-1)%mod;
  printf("%lld\n",ans);
}

int main(void){
  run();
  return 0;
}