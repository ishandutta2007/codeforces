#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

int can(int *a,int n,int sum){
  int i;
  int cnt=0;
  int x=0;
  for(i=0;i<n;i++){
    if(x==0){
      x=sum;
      cnt++;
    }
    x-=a[i];
    if(x<0) return 0;
  }
  return (cnt>=2 && x==0) || (cnt>2 && (x==0 || x==sum));
}

void run(void){
  int n;
  scanf("%d",&n);
  char s[101];
  scanf("%s",s);
  int a[100];
  int i;
  for(i=0;i<n;i++) a[i]=s[i]-'0';
  for(i=0;i<=9*n/2;i++){
    if(can(a,n,i)){
      printf("YES\n");
      return;
    }
  }
  printf("NO\n");
  return;
}

int main(void){
  run();
  return 0;
}