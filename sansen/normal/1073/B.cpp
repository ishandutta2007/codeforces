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
  int *a=(int *)calloc(n,sizeof(int));
  int i;
  for(i=0;i<n;i++) scanf("%d",a+i);
  int *used=(int *)calloc(n+1,sizeof(int));
  int p=0;
  for(i=0;i<n;i++){
    int b;
    scanf("%d",&b);
    if(used[b]){
      printf("0 ");
      continue;
    }
    int cnt=0;
    while(a[p]!=b){
      used[a[p++]]=1;
      cnt++;
    }
    printf("%d ",cnt+1);
    used[a[p++]]=1;
  }
  printf("\n");
}

int main(void){
  run();
  return 0;
}