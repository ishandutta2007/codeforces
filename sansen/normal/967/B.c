#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

int cmp(const void *a,const void *b){
  int aa=*(int *)a;
  int bb=*(int *)b;
  return aa-bb;
}

void run(void){
  int n,a,b;
  scanf("%d%d%d",&n,&a,&b);

  int *s=(int *)malloc(sizeof(int)*n);
  int i;
  for(i=0;i<n;i++){
    scanf("%d",s+i);
  }
  int sum=0;
  for(i=0;i<n;i++){
    sum+=s[i];
  }
  if((a*s[0])/sum>=b){
    printf("0\n");
    return;
  }

  int *t=(int *)malloc(sizeof(int)*n);
  for(i=0;i<n;i++) t[i]=s[i];
  qsort(t,n,sizeof(int),cmp);

  int cnt=0;
  int k;
  for(k=0;k<n;k++){
    if(t[n-1-k]==s[0] && cnt==k) continue;
    sum-=t[n-1-k];
    cnt++;
    if((a*s[0])/sum>=b){
      printf("%d\n",cnt);
      return;
    }
  }
}

int main(void){
  run();
  return 0;
}