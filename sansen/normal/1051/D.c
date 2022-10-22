#include<stdio.h>
#include<stdlib.h>

#define POS(i,j,k) (((i)*(2*n+1)+(j))*2+(k))

const int mod=998244353;
void add(int *x,int *a){
  *x+=*a;
  *x%=mod;
  return;
}

void run(void){
  int n,k;
  scanf("%d%d",&n,&k);
  int *dp=(int *)calloc(2*(2*n+1)*2,sizeof(int));
  int now=0;
  dp[POS(now,1,0)]=2;
  dp[POS(now,2,1)]=2;
  int i,j;
  for(i=2;i<=n;i++){
    int next=now^1;
    for(j=0;j<=2*i;j++) dp[POS(next,j,0)]=dp[POS(next,j,1)]=0;
    for(j=1;j<=2*(i-1);j++){
      add(dp+POS(next,j  ,0),dp+POS(now,j,0));
      add(dp+POS(next,j+1,0),dp+POS(now,j,0));
      add(dp+POS(next,j+1,1),dp+POS(now,j,0));
      add(dp+POS(next,j+1,1),dp+POS(now,j,0));
      add(dp+POS(next,j  ,0),dp+POS(now,j,1));
      add(dp+POS(next,j  ,0),dp+POS(now,j,1));
      add(dp+POS(next,j  ,1),dp+POS(now,j,1));
      add(dp+POS(next,j+2,1),dp+POS(now,j,1));
    }
    now=next;
  }
  printf("%d\n",(dp[POS(now,k,0)]+dp[POS(now,k,1)])%mod);
}

int main(void){
  run();
  return 0;
}