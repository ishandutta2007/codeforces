#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

int gcd(int a,int b){
  int r=a%b;
  while(r>0){
    a=b;b=r;r=a%b;
  }
  return b;
}

int isPrime(int n){
  if(n<=1) return 0;
  if(n<=3) return 1;
  if(n%2==0 || n%3==0) return 0;
  int k=7;
  while(k*k<=n){
    if(n%k==0 || n%(k-2)==0) return 0;
    k+=6;
  }
  if((k-2)*(k-2)<=n && n%(k-2)==0) return 0;
  return 1;
}

#define ADD(i,j) do{u[len]=i;v[len]=j;len++;}while(0)

void run(void){
  int n,m;
  scanf("%d%d",&n,&m);
  if(n-1>m){
    printf("Impossible\n");
    return;
  }
  int *u=(int *)malloc(sizeof(int)*m);
  int *v=(int *)malloc(sizeof(int)*m);
  int len=0;
  int i;
  for(i=2;i<=n;i++){
    ADD(1,i);
  }
  int j;
  for(i=2;i<=n && len<m;i++){
    for(j=i+1;j<=n && len<m;j++){
      if(gcd(i,j)>1) continue;
      ADD(i,j);
    }
  }
  printf("%s\n",len<m?"Impossible":"Possible");
  if(len>=m){
    for(i=0;i<m;i++){
      printf("%d %d\n",u[i],v[i]);
    }
  }
}

int main(void){
  run();
  return 0;
}