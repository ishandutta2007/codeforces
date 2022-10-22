#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

typedef struct testStruct{
  int c;
  int index;
} node;

int cmp(const void *a,const void *b){
  node *aa=(node *)a;
  node *bb=(node *)b;
  if(aa->c!=bb->c) return aa->c-bb->c;
  return aa->index-bb->index;
}

void run(void){
  int n,x,y;
  scanf("%d%d%d",&n,&x,&y);
  int *c=(int *)malloc(sizeof(int)*n);
  int i;
  for(i=0;i<n;i++) scanf("%d",c+i);

  node *a=(node *)malloc(sizeof(node)*n);
  for(i=0;i<n;i++){
    a[i].c=c[i];
    a[i].index=i+1;
  }
  qsort(a,n,sizeof(node),cmp);

  int yy=n-1;
  while(yy>=0 && (int64)(a[yy].c)*(n-yy)<y) yy--;
  for(i=0;i<yy;i++){
    int cc=a[i].c;
    int k=(x+cc-1)/cc;
    if(i+k<=yy){
      printf("Yes\n");
      printf("%d %d\n",k,n-yy);
      int j;
      for(j=i;j<i+k;j++){
	printf("%d ",a[j].index);
      }
      printf("\n");
      for(j=yy;j<n;j++){
	printf("%d ",a[j].index);
      }
      printf("\n");
      return;
    }
  }

  yy=n-1;
  while(yy>=0 && (int64)(a[yy].c)*(n-yy)<x) yy--;
  for(i=0;i<yy;i++){
    int cc=a[i].c;
    int k=(y+cc-1)/cc;
    if(i+k<=yy){
      printf("Yes\n");
      printf("%d %d\n",n-yy,k);
      int j;
      for(j=yy;j<n;j++){
	printf("%d ",a[j].index);
      }
      printf("\n");
      for(j=i;j<i+k;j++){
	printf("%d ",a[j].index);
      }
      printf("\n");
      return;
    }
  }
  printf("No\n");
  return;
}

int main(void){
  run();
  return 0;
}