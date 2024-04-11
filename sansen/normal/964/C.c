#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

int64 modPow(int64 r,int64 n,int64 p){
  int64 t=1;
  int64 s=r;
  while(n>0){
    if(n&0x01) t=t*s%p;
    s=s*s%p;
    n>>=1;
  }
  return t;
}

int64 inv(int64 a,int64 p){
  return modPow(a,p-2,p);
}

void run(void){
  int n,a,b,k;
  scanf("%d%d%d%d",&n,&a,&b,&k);
  char *s=(char *)malloc(sizeof(char)*(k+1));
  scanf("%s",s);
  const int p=1000000009;
  int64 sec=0;
  int i;
  for(i=0;i<k;i++){
    int64 d=(s[i]=='+'?1:-1);
    int64 add=(modPow(a,n-i,p)*modPow(b,i,p)%p*d+p)%p;
    sec=(sec+add)%p;
  }
  int64 r=modPow(inv(a,p),k,p)*modPow(b,k,p)%p;
  if(r==1){
    printf("%d\n",(int)(sec*((n+1)/k)%p));
    return;
  }
  int64 ans=sec*(modPow(r,(n+1)/k,p)-1)%p*inv(r-1,p)%p;
  printf("%d\n",(int)ans);
  return;
}

int main(void){
  run();
  return 0;
}