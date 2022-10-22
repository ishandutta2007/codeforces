#include<stdio.h>

typedef long long int int64;

static void printInt(int64 n){
  if(n<0){
    putchar('-');
    n=-n;
  }
  if(n==0){
    putchar('0');
    return;
  }
  int s[20];
  int len=0;
  while(n>0){
    s[len++]=n%10+'0';
    n/=10;
  }
  while(len>0){
    putchar(s[--len]);
  }
}

void run(void){
  int n;
  scanf("%d",&n);
  int m=1;
  while(n>3){
    int i;
    for(i=0;i<(n+1)/2;i++){
      printInt(m);putchar(' ');
      //printf("%d ",m);
    }
    n-=(n+1)/2;
    m*=2;
  }
  if(n==3){
    printf("%d %d %d\n",m,m,3*m);
  } else if(n==2){
    printf("%d %d\n",m,2*m);
  } else {
    printf("%d\n",m);
  }
}

int main(void){
  run();
  return 0;
}