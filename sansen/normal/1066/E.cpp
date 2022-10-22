#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))

const int mod=998244353;
int modPow(int r,int n){
  int t=1;
  int s=r;
  while(n>0){
    if(n&1) t=(int64)t*s%mod;
    s=(int64)s*s%mod;
    n>>=1;
  }
  return t;
}

void run(void){
  int n,m;
  scanf("%d%d",&n,&m);
  char *a=(char *)malloc(sizeof(char)*(n+1));
  char *b=(char *)malloc(sizeof(char)*(m+1));
  scanf("%s%s",a,b);
  int *cnt=(int *)calloc(m+1,sizeof(int));
  cnt[0]=0;
  int i;
  for(i=1;i<=m;i++) cnt[i]=cnt[i-1]+(b[i-1]=='1'?1:0);
  int ans=0;
  for(i=n-1;i>=0;i--){
    if(a[i]=='1'){
      ans=(ans+(int64)modPow(2,n-1-i)*cnt[MAX(m-(n-1-i),0)])%mod;
    }
  }
  printf("%d\n",ans);
}

int main(void){
  run();
  return 0;
}