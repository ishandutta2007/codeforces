#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

typedef struct segment{
  int l,r;
  int index;
} node;

int cmp(const void *a,const void *b){
  node *p=(node *)a;
  node *q=(node *)b;
  if(p->l!=q->l) return p->l-q->l;
  return -(p->r-q->r);
}

void print(node *a,int n){
  printf("print\n");
  int i;
  for(i=0;i<n;i++){
    printf("%d %d %d\n",a[i].l,a[i].r,a[i].index);
  }
  printf("end\n");
}

void printRI(int *r,int *index,int n){
  printf("r index\n");
  int i;
  for(i=0;i<n;i++){
    printf("%d %d\n",r[i],index[i]);
  }
  printf("end\n");
  return;
}

void run(void){
  int n;
  scanf("%d",&n);
  node *a=(node *)malloc(sizeof(node)*n);
  int i;
  for(i=0;i<n;i++){
    int l,r;
    scanf("%d%d",&l,&r);
    a[i].l=l;
    a[i].r=r;
    a[i].index=i+1;
  }
  qsort(a,n,sizeof(node),cmp);
  //print(a,n);

  int *r=(int *)malloc(sizeof(int)*n);
  int *index=(int *)malloc(sizeof(int)*n);
  r[n-1]=a[n-1].r;
  index[n-1]=n-1;
  for(i=n-2;i>=0;i--){
    if(r[i+1]>a[i].r){
      r[i]=a[i].r;
      index[i]=i;
    } else {
      r[i]=r[i+1];
      index[i]=index[i+1];
    }
  }
  //printRI(r,index,n);

  for(i=0;i+1<n;i++){
    if(a[i].r>=r[i+1]){
      printf("%d %d\n",a[index[i+1]].index,a[i].index);
      return;
    }
  }
  printf("-1 -1\n");
  return;
}

int main(void){
  run();
  return 0;
}