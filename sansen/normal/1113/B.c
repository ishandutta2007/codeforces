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

void run(void){
  int n=readInt();
  const int m=100;
  int *cnt=(int *)calloc(m+1,sizeof(int));
  int sum=0;
  while(n--){
    int a=readInt();
    cnt[a]++;
    sum+=a;
  }
  int min=sum;
  int i,j;
  for(i=1;i<=m;i++){
    if(cnt[i]==0) continue;
    for(j=i+1;j<=m;j++){
      if(cnt[j]==0) continue;
      for(int x=2;x<=j;x++){
	if(j%x!=0) continue;
	min=MIN(min,sum-i-j+i*x+j/x);
      }
    }
  }
  printInt(min);
  puts("");
}

int main(void){
  run();
  return 0;
}