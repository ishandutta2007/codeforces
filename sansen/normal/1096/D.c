#include<stdio.h>
#include<stdlib.h>

#define MIN(a,b) ((a)<(b)?(a):(b))

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

void run(void){
  int n=readInt();
  char *s=(char *)calloc(n+1,sizeof(char));
  scanf("%s",s);
  int64 dp[5]={0,0,0,0,1000000000LL*n};
  char hard[]="drah";
  int i,j;
  for(i=0;i<n;i++){
    int a=readInt();
    for(j=0;j<4;j++){
      if(s[i]==hard[j]){
	dp[j]=MIN(dp[j]+a,dp[j+1]);
      }
    }
  }
  printInt(dp[0]);
  putchar('\n');
}

int main(void){
  run();
  return 0;
}