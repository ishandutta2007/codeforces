#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  int n,L,a;
  scanf("%d%d%d",&n,&L,&a);
  int *t=(int *)malloc(sizeof(int)*(n+1));
  int *l=(int *)malloc(sizeof(int)*(n+1));
  t[0]=l[0]=0;
  int i;
  for(i=1;i<=n;i++) scanf("%d%d",t+i,l+i);
  int ans=0;
  for(i=0;i<n;i++) ans+=(t[i+1]-(t[i]+l[i]))/a;
  ans+=(L-(t[n]+l[n]))/a;
  printf("%d\n",ans);
}

int main(void){
  run();
  return 0;
}