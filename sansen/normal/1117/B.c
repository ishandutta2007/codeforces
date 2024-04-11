#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

typedef long long int int64;

static void printInt(int64 n){
  if(n<0){putchar('-');n=-n;}
  if(n==0){putchar('0');return;}
  int s[20];int len=0;
  while(n>0){s[len++]=n%10+'0';n/=10;}
  while(len>0){putchar(s[--len]);}
}
static int64 readInt(void){
  int prev='\0';int c=getchar();
  while(!('0'<=c && c<='9')){prev=c;c=getchar();}
  int64 res=0;
  while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}
  return prev=='-'?-res:res;
}

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

int cmp(const void *a,const void *b){
  return *(int *)a-*(int *)b;
}

void run(void){
  int n=readInt();
  int m=readInt();
  int k=readInt();
  int *a=(int *)calloc(n,sizeof(int));
  int i;
  for(i=0;i<n;i++) a[i]=readInt();
  qsort(a,n,sizeof(int),cmp);
  int b=m/(k+1);
  int64 ans=b*((int64)a[n-1]*k+a[n-2])+(int64)(m%(k+1))*a[n-1];
  printInt(ans);
  puts("");
}

int main(void){
  run();
  return 0;
}