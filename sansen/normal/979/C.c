#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

typedef struct dedge{
  int x;
  struct dedge *next;
} edge;

void append(edge *array,int a,int b){
  edge *t=(edge *)malloc(sizeof(edge));
  t->x=b;
  t->next=array[a].next;
  array[a].next=t;
  edge *s=(edge *)malloc(sizeof(edge));
  s->x=a;
  s->next=array[b].next;
  array[b].next=s;
  return;
}

int span(int x,int y,const edge *array,int *visited,int *stack,int n){
  int i;
  for(i=1;i<=n;i++) visited[i]=0;
  visited[y]=1;
  int top=0;
  stack[top++]=x;
  int cnt=0;
  while(top>0){
    int index=stack[--top];
    if(visited[index]) continue;
    visited[index]=1;
    cnt++;
    edge *t=array[index].next;
    while(t!=NULL){
      stack[top++]=t->x;
      t=t->next;
    }
  }
  return cnt;
}

void run(void){
  int n,x,y;
  scanf("%d%d%d",&n,&x,&y);
  edge *array=(edge *)malloc(sizeof(edge)*(n+1));
  int i;
  for(i=0;i<=n;i++){
    array[i].x=0;
    array[i].next=NULL;
  }
  for(i=0;i<n-1;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    append(array,a,b);
  }
  int *visited=(int *)malloc(sizeof(int)*(n+1));
  int *stack=(int *)malloc(sizeof(int)*(n+1));
  int m=span(x,y,array,visited,stack,n);
  int k=span(y,x,array,visited,stack,n);
  int l=m+k-n;
  int64 ans=(int64)n*(n-1)-(int64)(m-l)*(k-l);
  printf("%lld\n",ans);
}

int main(void){
  run();
  return 0;
}