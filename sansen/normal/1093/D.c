#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

static void printInt(int64 n){
  if(n<0){
    putchar('-');
    n=-n;
  }
  if(n==0){
    putchar('0');
    return;
  }
  int s[20];
  int len=0;
  while(n>0){
    s[len++]=n%10+'0';
    n/=10;
  }
  while(len>0){
    putchar(s[--len]);
  }
}

static int64 readInt(void){
  int c=getchar();
  while(!('0'<=c && c<='9')) c=getchar();
  int64 res=0;
  while('0'<=c && c<='9'){
    res=10*res+c-'0';
    c=getchar();
  }
  return res;
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

const int mod=998244353;

int modPow(int r,int n){
  int t=1;
  int s=r;
  while(n){
    if(n&1) t=(int64)t*s%mod;
    s=(int64)s*s%mod;
    n>>=1;
  }
  return t;
}

void solve(void){
  int n=(int)readInt();
  int m=(int)readInt();
  graph *g=newGraph(n,2*m);
  while(m--){
    int u=(int)readInt()-1;
    int v=(int)readInt()-1;
    addEdge(g,u,v);
    addEdge(g,v,u);
  }
  int *dp=(int *)calloc(n,sizeof(int));
  int *stack=(int *)calloc(n,sizeof(int));
  int ans=1;
  int i;
  for(i=0;i<n;i++){
    if(dp[i]>0) continue;
    int size=0;
    int cnt=0;
    int top=0;
    dp[i]=1;
    stack[top++]=i;
    while(top>0){
      const int v=stack[--top];
      size++;
      if(dp[v]&1) cnt++;
      int p;
      for(p=g->start[v];p!=-1;p=g->next[p]){
	const int u=g->vertex[p];
	if(dp[u]>0){
	  if(dp[v]==dp[u]) ans=0;
	  continue;
	}
	dp[u]=dp[v]^3;
	stack[top++]=u;
      }
    }
    ans=(int64)ans*(modPow(2,cnt)+modPow(2,size-cnt))%mod;
  }
  printInt(ans);
  putchar('\n');
  freeGraph(g);
  free(dp);
  free(stack);
  return;
}

void run(void){
  int t;
  scanf("%d",&t);
  while(t--){
    solve();
  }
}

int main(void){
  run();
  return 0;
}