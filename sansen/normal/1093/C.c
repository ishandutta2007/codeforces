#include<stdio.h>
#include<stdlib.h>

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

static int64 readInt(void){
  int c=getchar();
  while(!('0'<=c && c<='9')) c=getchar();
  int64 res=0;
  while('0'<=c && c<='9'){
    res=10*res+c-'0';
    c=getchar();
  }
  return res;
}

void run(void){
  int n;
  scanf("%d",&n);
  int64 *a=(int64 *)calloc(n,sizeof(int64));
  a[0]=0;
  a[n-1]=readInt();
  int i;
  for(i=1;i<n/2;i++){
    const int64 b=readInt();
    a[i]=a[i-1];
    a[n-1-i]=b-a[i];
    if(a[n-1-i]>a[n-i]){
      a[n-1-i]=a[n-i];
      a[i]=b-a[n-1-i];
    }
  }
  printInt(a[0]);
  for(i=1;i<n;i++){
    putchar(' ');
    printInt(a[i]);
  }
  putchar('\n');
}

int main(void){
  run();
  return 0;
}