#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

typedef long long int int64;

static void printInt(int64 n){
  if(n<0){putchar('-');n=-n;}
  if(n==0){putchar('0');return;}
  int s[20];int len=0;
  while(n>0){s[len++]=n%10+'0';n/=10;}
  while(len>0){putchar(s[--len]);}
}
static int64 readInt(void){
  int prev='\0';int c=getchar();
  while(!('0'<=c && c<='9')){prev=c;c=getchar();}
  int64 res=0;
  while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}
  return prev=='-'?-res:res;
}

typedef struct directedGraph{
  int *vertex;
  int *next;
  int *start;
  int v,e;
  int pointer;
} graph;

graph* newGraph(const int v,const int e){
  graph *g=(graph *)malloc(sizeof(graph));
  g->vertex=(int *)calloc(e,sizeof(int));
  g->next=(int *)calloc(e,sizeof(int));
  g->start=(int *)calloc(v,sizeof(int));
  for(int i=0;i<v;i++) g->start[i]=-1;
  g->v=v;
  g->e=e;
  g->pointer=0;
  return g;
}

void freeGraph(graph *g){
  free(g->vertex);
  free(g->next);
  free(g->start);
  free(g);
  return;
}

void addEdge(graph *g,const int from,const int to){
  const int p=g->pointer;
  g->vertex[p]=to;
  g->next[p]=g->start[from];
  g->start[from]=p;
  g->pointer++;
  return;
}

typedef struct UnionFind{
  int *parent;
  int n;
} UnionFind;

UnionFind* newUnionFind(int n){
  UnionFind *u=(UnionFind *)calloc(1,sizeof(UnionFind));
  u->parent=(int *)calloc(n,sizeof(int));
  u->n=n;
  for(int i=0;i<n;i++) u->parent[i]=-1;
  return u;
}

void initUnionFind(UnionFind *u){
  for(int i=0;i<u->n;i++) u->parent[i]=-1;
}

int root(UnionFind *u,int x){
  if(u->parent[x]<0) return x;
  return u->parent[x]=root(u,u->parent[x]);
}

int same(UnionFind *u,int x,int y){
  return root(u,x)==root(u,y);
}

int getSize(UnionFind *u,int x){
  return -u->parent[root(u,x)];
}

void unite(UnionFind *u,int x,int y){
  x=root(u,x);
  y=root(u,y);
  if(x==y) return;
  if(u->parent[x]>u->parent[y]){
    int swap=x;
    x=y;
    y=swap;
  }
  u->parent[x]+=u->parent[y];
  u->parent[y]=x;
}

void run(void){
  int n=readInt();
  graph *g=newGraph(2*n,2*n);
  UnionFind *u=newUnionFind(2*n);
  int *r=(int *)calloc(2*n,sizeof(int));
  int i;
  for(i=0;i<2*n;i++) r[i]=i;
  for(i=1;i<n;i++){
    int a=readInt();
    int b=readInt();
    int ra=r[root(u,a)];
    int rb=r[root(u,b)];
    addEdge(g,n+i,ra);
    addEdge(g,n+i,rb);
    unite(u,a,b);
    r[root(u,a)]=n+i;
  }
  int *stack=(int *)calloc(2*n,sizeof(int));
  int *ans=(int *)calloc(n,sizeof(int));
  int len=0;
  int top=0;
  stack[top++]=n+i-1;
  while(top>0){
    int v=stack[--top];
    if(v<=n){
      ans[len++]=v;
      continue;
    }
    int p;
    for(p=g->start[v];p!=-1;p=g->next[p]){
      int u=g->vertex[p];
      stack[top++]=u;
    }
  }
  printInt(ans[0]);
  for(i=1;i<len;i++){
    putchar(' ');
    printInt(ans[i]);
  }
  puts("");
}

int main(void){
  run();
  return 0;
}