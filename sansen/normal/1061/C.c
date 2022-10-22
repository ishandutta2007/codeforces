#include<stdio.h>
#include<stdlib.h>

int *factor=NULL;
void init(void){
  const int n=1000000;
  factor=(int *)calloc(n+1,sizeof(int));
  int i,j;
  for(i=0;i<=n;i++) factor[i]=i;
  for(i=2;i*i<=n;i++) if(factor[i]==i) for(j=i*i;j<=n;j+=i) factor[j]=i;
}

int cmp(const void *a,const void *b){
  return *(int *)a-*(int *)b;
}

int factorize(int a,int *f,int max){
  int len=1;
  f[0]=1;
  while(a>1){
    int p=factor[a];
    int c=0;
    do{
      a/=p;
      c++;
    }while(a%p==0);
    int i,j;
    int mul;
    for(i=1,mul=p;i<=c;i++,mul*=p){
      for(j=0;j<len;j++){
	f[i*len+j]=mul*f[j];
      }
    }
    len*=c+1;
  }
  int i,j;
  i=j=0;
  while(i<len){
    f[j++]=f[i++];
    while(i<len && f[i]>max) i++;
  }
  qsort(f,j,sizeof(int),cmp);
  return j;
}

void run(void){
  init();
  int n;
  scanf("%d",&n);
  const int mod=1000000007;
  int *dp=(int *)calloc(n+1,sizeof(int));
  int *f=(int *)calloc(100000,sizeof(int));
  dp[0]=1;
  int max=1;
  int i,j;
  for(i=0;i<n;i++){
    int a;
    scanf("%d",&a);
    int len=factorize(a,f,max);
    for(j=len-1;j>=0;j--){
      int d=f[j];
      if(d>max) continue;
      if(d==max) max++;
      dp[d]=(dp[d]+dp[d-1])%mod;
    }
  }
  int ans=0;
  for(i=1;i<=n;i++) ans=(ans+dp[i])%mod;
  printf("%d\n",ans);
}

int main(void){
  run();
  return 0;
}