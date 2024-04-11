#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  int n;
  scanf("%d",&n);
  int *c=(int *)malloc(sizeof(int)*(n+1));
  int i;
  for(i=1;i<=n;i++) scanf("%d",c+i);
  int *a=(int *)malloc(sizeof(int)*(n+1));
  for(i=1;i<=n;i++) scanf("%d",a+i);
  int sum=0;
  int *dp=(int *)calloc(n+1,sizeof(int));
  for(i=1;i<=n;i++){
    if(dp[i]!=0) continue;
    int x=i;
    while(dp[x]==0){
      dp[x]=i;
      x=a[x];
    }
    if(dp[x]!=i) continue;
    int min=10001;
    while(dp[x]==i){
      min=MIN(min,c[x]);
      dp[x]=-i;
      x=a[x];
    }
    sum+=min;
  }
  printf("%d\n",sum);
}

int main(void){
  run();
  return 0;
}