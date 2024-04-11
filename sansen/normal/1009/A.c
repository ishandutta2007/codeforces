#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  int n,m;
  scanf("%d%d",&n,&m);
  int c[1000];
  int i;
  for(i=0;i<n;i++) scanf("%d",c+i);
  int a[1000];
  for(i=0;i<m;i++) scanf("%d",a+i);
  int j=0;
  for(i=0;i<n && j<m;i++){
    if(c[i]<=a[j]){
      j++;
    }
  }
  printf("%d\n",j);
}

int main(void){
  run();
  return 0;
}