#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

int64 scanUnsigned64(void){
  char s[22];
  scanf("%s",s);
  int64 res=0;
  int i=0;
  while(s[i]!='\0'){
    res=10*res+s[i]-'0';
    i++;
  }
  return res;
}

void run(void){
  int n,m;
  scanf("%d%d",&n,&m);
  int64 k=scanUnsigned64();
  if(k<=n-1){
    printf("%d %d\n",(int)(1+k),1);
    return;
  }
  k-=n-1;
  int x=n-((k-1)/(m-1));
  int t=(k-1)%(2*(m-1));
  int y=(t<=(m-2))?2+t:(m-(t-m+1));
  printf("%d %d\n",x,y);
  return;  
}

int main(void){
  run();
  return 0;
}