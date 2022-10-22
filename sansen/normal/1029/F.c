#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void factorize(int64 n,int64 *f,int *resLen){
  f[0]=1;
  int len=1;
  int64 k;
  for(k=2;k*k<=n;k++){
    if(n%k==0){
      int c=0;
      while(n%k==0){
	c++;
	n/=k;
      }
      int64 mul;
      int i;
      for(i=1,mul=k;i<=c;i++,mul*=k){
	int j;
	for(j=0;j<len;j++){
	  f[i*len+j]=f[j]*mul;
	}
      }
      len*=c+1;
    }
  }
  if(n>1){
    int i;
    for(i=0;i<len;i++){
      f[len+i]=f[i]*n;
    }
    len*=2;
  }
  *resLen=len;
  return;
}

int cmp(const void *a,const void *b){
  int64 p=*(int64 *)a;
  int64 q=*(int64 *)b;
  return p==q?0:p-q<0?-1:1;
}

void run(void){
  int64 a,b;
  scanf("%lld%lld",&a,&b);
  int64 factorA[20000];
  int lenA=0;
  factorize(a,factorA,&lenA);
  int64 factorB[20000];
  int lenB=0;
  factorize(b,factorB,&lenB);
  int64 s=a+b;
  int64 factorS[40000];
  int lenS=0;
  factorize(s,factorS,&lenS);
  qsort(factorA,lenA,sizeof(int64),cmp);
  qsort(factorB,lenB,sizeof(int64),cmp);
  qsort(factorS,lenS,sizeof(int64),cmp);
  /*
  {
  int i;
  printf("%lld : ",a);for(i=0;i<lenA;i++) printf("%lld ",factorA[i]);printf("\n");
  printf("%lld : ",b);for(i=0;i<lenB;i++) printf("%lld ",factorB[i]);printf("\n");
  printf("%lld : ",s);for(i=0;i<lenS;i++) printf("%lld ",factorS[i]);printf("\n");
  }
  */
  int ai=0;
  int bi=0;
  int64 min=2*a+2*b+2;
  int i;
  for(i=0;i<=(lenS+1)/2 && factorS[i]*factorS[i]<=s;i++){
    int64 r=factorS[i];
    while(ai<lenA && factorA[ai]<=r) ai++;
    while(bi<lenB && factorB[bi]<=r) bi++;
    if(s/r>=a/factorA[ai-1] || s/r>=b/factorB[bi-1]){
      min=2*(r+s/r);
    }
  }
  printf("%lld\n",min);
}

int main(void){
  run();
  return 0;
}