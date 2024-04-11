#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

void run(void){
  const int mod=998244353;
  int n;
  scanf("%d",&n);
  int *a=(int *)malloc(sizeof(int)*(n+1));
  int i;
  for(i=1;i<=n;i++) scanf("%d",a+i);
  for(i=2;i<=n;i++) a[i]=(a[i]+a[i-1])%mod;
  int ans=0;
  int mul;
  for(i=n-2,mul=1;i>=1;i--){
    ans=(ans+(int64)(n-1-i)*mul%mod*a[i])%mod;
    mul=mul*2%mod;
  }
  ans=(ans+a[n])%mod;
  for(i=n-1,mul=2;i>=1;i--){
    ans=(ans+(int64)mul*a[i])%mod;
    mul=2*mul%mod;
  }
  printf("%d\n",ans);
}

int main(void){
  run();
  return 0;
}