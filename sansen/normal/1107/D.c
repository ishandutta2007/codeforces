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

int gcd(int a,int b){
  int r=a%b;
  while(r>0){
    a=b;b=r;r=a%b;
  }
  return b;
}

void convert(int *bit,char *s,int n){
  for(int i=0;i<n/4;i++){
    int b=s[i]-'0';
    if(!(0<=b && b<=9)){
      b=b+'0'-'A'+10;
    }
    for(int j=0;j<4;j++){
      bit[4*i+3-j]=(b>>j)&1;
    }
  }
}

void run(void){
  const int n=readInt();
  char *s=(char *)calloc(n,sizeof(char));
  scanf("%s",s);
  int *bit=(int *)calloc(n,sizeof(int));
  convert(bit,s,n);
  int g=n;
  int i,j;
  for(i=1;i<n;i++){
    if(bit[i]!=bit[i-1]){
      g=gcd(g,i);
    }
  }
  int *next=(int *)calloc(n,sizeof(int));
  for(i=1;i<n;i++){
    scanf("%s",s);
    convert(next,s,n);
    for(j=0;j<n;j++){
      if(next[j]!=bit[j]){
	g=gcd(g,i);
      }
    }
    memcpy(bit,next,sizeof(int)*n);
    for(j=1;j<n;j++){
      if(bit[j]!=bit[j-1]){
	g=gcd(g,j);
      }
    }
  }
  printInt(g);
  puts("");
}

int main(void){
  run();
  return 0;
}