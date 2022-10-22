#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

int cmp(const void *a,const void *b){
  return *(int *)a-*(int *)b;
}

void run(void){
  int n,k;
  scanf("%d%d",&n,&k);
  int *h=(int *)malloc(sizeof(int)*n);
  int i;
  for(i=0;i<n;i++) scanf("%d",h+i);
  srand((unsigned)time(NULL));
  for(i=1;i<n;i++){
    int p=rand()%i;
    int t=h[p];
    h[p]=h[i];
    h[i]=t;
  }
  qsort(h,n,sizeof(int),cmp);
  int *cnt=(int *)calloc(2*100000+1,sizeof(int));
  for(i=0;i<n;i++) cnt[h[i]]++;
  for(i=200000-1;i>=0;i--) cnt[i]+=cnt[i+1];
  int64 ans=0;
  int64 used=0;
  for(i=200000;cnt[i]<n;i--){
    if(used+cnt[i]<=k){
      used+=cnt[i];
    } else {
      ans++;
      used=cnt[i];
    }
  }
  if(used>0) ans++;
  printf("%lld\n",ans);
}

int main(void){
  run();
  return 0;
}