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
  int *a=(int *)malloc(sizeof(int)*n);
  int i;
  for(i=0;i<n;i++) scanf("%d",a+i);
  if(n==1){
    printf("%d\n",a[0]);
    return;
  }
  int p=0;
  int z=0;
  int m=0;
  for(i=0;i<n;i++){
    if(a[i]==0) z=1;
    else if(a[i]>0) p=1;
    else m=1;
  }
  if(z || (p&&m)){
    int64 ans=0;
    for(i=0;i<n;i++){
      ans+=ABS(a[i]);
    }
    printf("%lld\n",ans);
  } else {
    int64 ans=0;
    int min=1000000001;
    for(i=0;i<n;i++){
      min=MIN(min,ABS(a[i]));
      ans+=ABS(a[i]);
    }
    printf("%lld\n",ans-2*min);
  }
}

int main(void){
  run();
  return 0;
}