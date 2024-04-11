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

int64 func(int64 n,int64 b){
  int64 res=0;
  while(n>0){
    res+=n/b;
    n/=b;
  }
  return res;
}

void run(void){
  int64 n=readInt();
  int64 b=readInt();
  int64 ans=n;
  for(int64 k=2;k*k<=b;k++){
    if(b%k!=0) continue;
    int cnt=0;
    do{
      b/=k;
      cnt++;
    } while(b%k==0);
    int64 f=func(n,k)/cnt;
    ans=MIN(ans,f);
  }
  if(b>1){
    ans=MIN(ans,func(n,b));
  }
  printInt(ans);
  putchar('\n');
}

int main(void){
  run();
  return 0;
}