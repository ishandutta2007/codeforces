#include<stdio.h>
#include<stdlib.h>

void run(void){
  int n,s;
  scanf("%d%d",&n,&s);
  int *cnt=(int *)calloc(n+1,sizeof(int));
  int i;
  for(i=0;i<n-1;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    cnt[a]++;
    cnt[b]++;
  }
  int leaf=0;
  for(i=1;i<=n;i++){
    if(cnt[i]==1) leaf++;
  }
  double ans=((double)s)/leaf*2;
  printf("%.7f\n",ans);
  return;
}

int main(void){
  run();
  return 0;
}