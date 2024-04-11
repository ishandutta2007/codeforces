#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void fill(int *factor,int n,int *len){
  int k=2;
  while(k*k<=n){
    if(n%k==0){
      factor[(*len)++]=k;
      while(n%k==0) n/=k;
    }
    k++;
  }
  if(n>1) factor[(*len)++]=n;
  return;
}

void run(void){
  int n;  
  scanf("%d",&n);
  int a,b;
  scanf("%d%d",&a,&b);
  int factor[128];
  int len=0;
  fill(factor,a,&len);
  fill(factor,b,&len);
  int i;
  for(i=1;i<n;i++){
    scanf("%d%d",&a,&b);
    int j;
    for(j=0;j<len;j++){
      if(a%factor[j]!=0 && b%factor[j]!=0){
	factor[j]=1;
      }
    }
  }
  for(i=0;i<len;i++){
    if(factor[i]>1){
      printf("%d\n",factor[i]);
      return;
    }
  }
  printf("-1\n");
  return;
}

int main(void){
  run();
  return 0;
}