#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

const char yes[]="Possible";
const char no[]="Impossible";

int getColor(void){
  static int c=1;
  return c++;
}

void run(void){
  int n;
  scanf("%d",&n);
  int *a=(int *)calloc(n,sizeof(int));
  int i;
  for(i=0;i<n;i++) scanf("%d",a+i);
  int *cnt=(int *)calloc(n+1,sizeof(int));
  for(i=0;i<n;i++){
    cnt[n-a[i]]++;
  }
  for(i=1;i<=n;i++){
    if(cnt[i]>0 && cnt[i]%i!=0){
      printf("%s\n",no);
      return;
    }
  }
  int *b=(int *)calloc(n+1,sizeof(int));
  printf("%s\n",yes);
  for(i=0;i<n;i++){
    int k=n-a[i];
    if(cnt[k]%k==0){
      b[k]=getColor();
    }
    printf("%d ",b[k]);
    cnt[k]--;
  }
  printf("\n");
}

int main(void){
  run();
  return 0;
}