#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

typedef struct scorelist{
  int v;
  int p;
} node;

int cmp(const void *a,const void *b){
  node *p=(node *)a;
  node *q=(node *)b;
  return p->v-q->v;
}

void run(void){
  int n;
  scanf("%d",&n);
  node *array=(node *)malloc(sizeof(node)*2*n);
  int i;
  for(i=0;i<2*n;i++){
    int v;
    scanf("%d",&v);
    array[i].v=v;
    array[i].p=(i<n?0:1);
  }
  qsort(array,2*n,sizeof(node),cmp);
  int64 a=0;
  int64 b=0;
  for(i=2*n-1;i>0;i-=2){
    if(array[i].p==0) a+=array[i].v;
    if(array[i-1].p==1) b+=array[i-1].v;
  }
  printf("%lld\n",a-b);
}

int main(void){
  run();
  return 0;
}