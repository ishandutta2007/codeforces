#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  int n,r;
  scanf("%d%d",&n,&r);
  int a[1001];
  int i,j;
  for(i=1;i<=n;i++) scanf("%d",a+i);
  int heat[1001]={};
  int ansL=0;
  for(i=1;i<=n;i++){
    if(heat[i]) continue;
    for(j=MIN(i+r-1,n);j>=MAX(1,i-r+1);j--) if(a[j]) break;
    if(j<MAX(1,i-r+1)){
      printf("-1\n");
      return;
    }
    int k;
    for(k=MAX(j-r+1,0);k<=MIN(j+r-1,n);k++) heat[k]=1;
    ansL++;
  }
  for(i=0;i<=n;i++) heat[i]=0;
  int ansR=0;
  for(i=n;i>=1;i--){
    if(heat[i]) continue;
    for(j=MAX(i-r+1,1);j<=MIN(n,i+r+1);j++) if(a[j]) break;
    int k;
    for(k=MAX(j-r+1,1);k<=MIN(n,i+r+1);k++) heat[k]=1;
    ansR++;
  }
  printf("%d\n",MIN(ansL,ansR));
}

int main(void){
  run();
  return 0;
}