#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

int cmp(const void *a,const void *b){
  return *(int *)a-*(int *)b;
}

void run(void){
  int n;
  scanf("%d",&n);
  int *a=(int *)malloc(sizeof(int)*n);
  int i;
  for(i=0;i<n;i++) scanf("%d",a+i);
  qsort(a,n,sizeof(int),cmp);
  int ans=0;
  int l,r;
  l=r=0;
  while(r<n){
    while(r<n && a[l]<a[r]){
      ans++;
      l++;
      r++;
    }
    while(r<n && a[l]==a[r]) r++;
  }
  printf("%d\n",ans);
}

int main(void){
  run();
  return 0;
}