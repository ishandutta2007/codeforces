#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  int n;
  scanf("%d",&n);
  int *a=(int *)malloc(sizeof(int)*n);
  int i;
  for(i=0;i<n;i++) scanf("%d",a+i);
  int max=0;
  for(i=0;i<n;i++){
    int j=i+1;
    while(j<n && a[j]<=a[j-1]*2) j++;
    max=MAX(max,j-i);
    i=j-1;
  }
  printf("%d\n",max);
}

int main(void){
  run();
  return 0;
}