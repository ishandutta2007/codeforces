#include<stdio.h>
#include<stdlib.h>

typedef struct wedge{
  int a,b;
  int w;
} edge;

int cmp(const void *a,const void *b){
  return ((edge *)a)->w-((edge *)b)->w;
}

int root(int *u,int x){
  if(u[x]==x) return x;
  return u[x]=root(u,u[x]);
}

int same(int *u,int x,int y){
  return root(u,x)==root(u,y);
}

void unite(int *u,int x,int y){
  x=root(u,x);
  y=root(u,y);
  if(x==y) return;
  u[x]=y;
}

void run(void){
  int n,m,k;
  scanf("%d%d%d",&n,&m,&k);
  int *x=(int *)calloc(k,sizeof(int));
  int i;
  for(i=0;i<k;i++){
    scanf("%d",x+i);
    x[i]--;
  }
  edge *e=(edge *)calloc(m,sizeof(edge));
  for(i=0;i<m;i++){
    int a,b,w;
    scanf("%d%d%d",&a,&b,&w);
    a--;
    b--;
    e[i]=(edge){a,b,w};
  }
  qsort(e,m,sizeof(edge),cmp);
  int *u=(int *)calloc(n,sizeof(int));
  for(i=0;i<n;i++) u[i]=i;
  int max=0;
  int cnt=1;
  for(i=0;cnt<k && i<m;i++){
    int a=e[i].a;
    int b=e[i].b;
    if(same(u,a,b)) continue;
    max=e[i].w;
    unite(u,a,b);
    while(cnt<k && same(u,x[0],x[cnt])) cnt++;
  }
  for(i=0;i<k;i++) printf("%d ",max);
  printf("\n");
}

int main(void){
  run();
  return 0;
}