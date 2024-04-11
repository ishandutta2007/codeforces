#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  int n;
  int64 t;
  scanf("%d%lld",&n,&t);
  int *a=(int *)calloc(n,sizeof(int));
  int i;
  for(i=0;i<n;i++) scanf("%d",a+i);
  int64 ans=0;
  while(1){
    int64 sum=0;
    int cnt=0;
    for(i=0;i<n;i++){
      if(a[i]<=t){
	sum+=a[i];
	cnt++;
	t-=a[i];
      }
    }
    if(cnt==0) break;
    ans+=cnt+(t/sum)*cnt;
    t%=sum;
  }
  printf("%lld\n",ans);
}

int main(void){
  run();
  return 0;
}