#include <bits/stdc++.h>

using namespace std;
const int NN=100010;
const int More=320;

int HHead[NN];
int NNext[NN<<1];
int TTo[NN<<1];
int EE;

void AAdd(int u,int v){
  NNext[EE]=HHead[u];
  TTo[EE]=v;
  HHead[u]=EE++;
  NNext[EE]=HHead[v];
  TTo[EE]=u;
  HHead[v]=EE++;
}

int Head[NN];
int Next[NN];
int To[NN];
int E;

void Add(int u,int v){
  Next[E]=Head[u];
  To[E]=v;
  Head[u]=E++;
}

void predfs(int u,int fa=-1){
  for(int i=HHead[u];~i;i=NNext[i]){
    int v=TTo[i];
    if(v==fa) continue;
    Add(u,v);
    predfs(v,u);
  }
}

int N,Answer,Key;

inline int dfs(int u){
  int firstmax=0,secondmax=0;
  for(int i=Head[u];~i;i=Next[i]){
    int r=dfs(To[i]);
    if(r>=firstmax){
      secondmax=firstmax;
      firstmax=r;
    }else if(r>secondmax){
      secondmax=r;
    }
  }
  if(1+firstmax+secondmax>=Key){
    Answer++;
    return 0;
  }else return firstmax+1;
}

int Trivial(int K){
  Answer=0;
  Key=K;
  dfs(1);
  return Answer;
}

int Array[NN];

void solve(){
  Array[0]=N+1;
  for(int i=1,j; i<=More; i++){
    int st=1,ed=min(N+1,Array[i-1]+1);
    while(st+1<ed){
      int md=st+ed>>1;
      j=Trivial(md);
      if(j>=i) st=md;
      else ed=md;
    }
    Array[i]=st;
  }
  for(int i=More+1; i<=N; i++){
    int st=0,ed=More+1;
    while(st+1<ed){
      int md=st+ed>>1;
      if(Array[md]>=i) st=md;
      else ed=md;
    }
    printf("%d ",st);
  }
  puts("");
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.in", "r", stdin);
  freopen("out.out", "w", stdout);
#endif
  memset(HHead,-1,sizeof HHead);
  memset(Head,-1,sizeof Head);
  scanf("%d",&N);
  for(int i=1,j,k; i<N; i++){
    scanf("%d%d",&j,&k);
    AAdd(j,k);
  }
  predfs(1);
  for(int i=1; i<=min(N,More); i++){
    printf("%d ",Trivial(i));
  }
  if(N>More) solve();
  return 0;
}