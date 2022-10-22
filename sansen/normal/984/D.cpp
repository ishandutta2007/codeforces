#include<stdio.h>
#include<stdlib.h>

#define MAX(a,b) ((a)>(b)?(a):(b))
#define POS(i,j) ((i)*n+(j))

void run(void){
  int n;
  scanf("%d",&n);
  int *dp=(int *)calloc(n*n,sizeof(int));
  int i,j;
  for(i=0;i<n;i++) scanf("%d",dp+POS(i,i));
  for(i=1;i<n;i++){
    for(j=i;j<n;j++){
      dp[POS(j-i,j)]=dp[POS(j-i,j-1)]^dp[POS(j-i+1,j)];
    }
  }
  for(i=1;i<n;i++){
    for(j=i;j<n;j++){
      dp[POS(j-i,j)]=MAX(dp[POS(j-i,j)],MAX(dp[POS(j-i,j-1)],dp[POS(j-i+1,j)]));
    }
  }
  int q;
  scanf("%d",&q);
  while(q--){
    int l,r;
    scanf("%d%d",&l,&r);
    l--;r--;
    printf("%d\n",dp[POS(l,r)]);
  }
}

int main(void){
  run();
  return 0;
}