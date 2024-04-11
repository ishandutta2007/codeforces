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

#define POS(i,j) ((i)*(n+1)+(j))

void run(void){
  int n=readInt();
  int *c=(int *)calloc(n,sizeof(int));
  int i;
  for(i=0;i<n;i++) c[i]=readInt();
  int len=0;
  i=0;
  while(i<n){
    c[len]=c[i];
    while(i<n && c[i]==c[len]) i++;
    len++;
  }
  n=len;
  int *d=(int *)calloc(n,sizeof(int));
  for(i=0;i<len;i++) d[i]=c[n-1-i];
  int *dp=(int *)calloc((n+1)*(n+1),sizeof(int));
  for(i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      int a=c[i-1];
      int b=d[j-1];
      if(a==b){
	dp[POS(i,j)]=dp[POS(i-1,j-1)]+1;
      } else {
	dp[POS(i,j)]=MAX(dp[POS(i-1,j)],dp[POS(i,j-1)]);
      }
    }
  }
  int max=0;
  for(i=0;i<=n;i++) max=MAX(max,dp[POS(n-i,i)]);
  printInt(n-max-1);
  putchar('\n');
}

int main(void){
  run();
  return 0;
}