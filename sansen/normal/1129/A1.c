#include<stdio.h>
#include<stdlib.h>

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
  int m=readInt();
  int *cnt=(int *)calloc(n,sizeof(int));
  int *min=(int *)calloc(n,sizeof(int));
  for(int i=0;i<n;i++) min[i]=n+1;
  while(m--){
    int a=readInt()-1;
    int b=readInt()-1;
    cnt[a]++;
    min[a]=MIN(min[a],(b+n-a)%n);
  }
  for(int i=0;i<n;i++){
    int ans=0;
    for(int j=0;j<n;j++){
      int k=(i+j)%n;
      if(cnt[k]>0){
	int d=n*(cnt[k]-1)+min[k]+j;
	ans=MAX(ans,d);
      }
    }
    printInt(ans);
    if(i<n) putchar(' ');
  }
  puts("");
}

int main(void){
  run();
  return 0;
}