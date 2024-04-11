#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void calc(int *c,int d,int k){
  if(c[MAX(d-k+1,0)]==-1){
    int m=MAX(d-k+1,0);
    int i;
    for(i=m;i<=d;i++) c[i]=m;
    return;
  }

  int i=d;
  while(i>=0 && c[i]==-1) i--;

  int len=0;
  while(i-len>=0 && c[i-len]==c[i]) len++;
  
  if(k-len+i>=d){
    int j;
    for(j=i+1;j<=d;j++){
      c[j]=c[i];
    }
    return;
  }

  int m=i+1;
  int j;
  for(j=i+1;j<=d;j++){
    c[j]=m;
  }
  
  return;
}

void run(void){
  int n,k;
  scanf("%d%d",&n,&k);
  int *p=(int *)malloc(sizeof(int)*n);
  int i;
  for(i=0;i<n;i++) scanf("%d",p+i);

  int c[256];
  for(i=0;i<256;i++) c[i]=-1;

  for(i=0;i<n;i++){
    int d=p[i];
    if(c[d]!=-1){
      printf("%d ",c[d]);
      continue;
    }
    calc(c,d,k);
    printf("%d ",c[d]);
  }
  printf("\n");
  return;
}

int main(void){
  run();
  return 0;
}