#include <bits/stdc++.h>
#define lft (u<<1)
#define rgt (lft|1)
#define mid (L+R>>1)
using namespace std;
typedef long long LL;

const LL INF=0x3f3f3f3f3f3f3f3fll;
const int NN=200020;
LL Answer[NN<<2];
LL Min[NN<<2],Max[NN<<2];
LL D[NN],H[NN];
LL Y[NN],X[NN];

inline void Push_up(int u){
  Answer[u]=max(Answer[lft],Answer[rgt]);
  Answer[u]=max(Answer[u],Max[rgt]-Min[lft]);
  Min[u]=min(Min[lft],Min[rgt]);
  Max[u]=max(Max[lft],Max[rgt]);
}

inline void Build(int u,int L,int R){
  if(L+1==R){
    Max[u]=Y[L];
    Min[u]=X[L];
  }else{
    Build(lft,L,mid);
    Build(rgt,mid,R);
    Push_up(u);
  }
}

LL Ans,MN;

inline void Calc(int u,int L,int R,int st,int ed){
  if(ed<=L || R<=st) return;
  if(st<=L && R<=ed){
    if(Answer[u]>Ans) Ans=Answer[u];
    if(Max[u]-MN>Ans) Ans=Max[u]-MN;
    if(MN>Min[u]) MN=Min[u];
  }else{
    Calc(lft,L,mid,st,ed);
    Calc(rgt,mid,R,st,ed);
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.in", "r", stdin);
  freopen("out.out", "w", stdout);
#endif
  
  int N,Test,i,j;
  scanf("%d%d",&N,&Test);
  for(i=1; i<=N; i++){
    scanf("%I64d",D+i);
    D[N+i]=D[i];
  }
  for(i=1; i<=N; i++){
    scanf("%I64d",H+i);
    H[i]<<=1;
    H[i+N]=H[i];
  }
  for(i=1; i<=(N<<1); i++){
    Y[i]=D[i-1]+H[i];
    X[i]=D[i-1]-H[i];
    D[i]+=D[i-1];
  }
  
  Build(1,1,(N<<1)+1);
  
  int L,R;
  while(Test--){
    scanf("%d%d",&L,&R);
    if(L>R){
      L--;
      R++;
      swap(L,R);
    }else{
      R++;
      L--;
      L+=N;
      swap(L,R);
    }
    Ans=0ll;
    MN=INF;
    Calc(1,1,(N<<1)+1,L,R+1);
    printf("%I64d\n",Ans);
  }
  
  return 0;
}