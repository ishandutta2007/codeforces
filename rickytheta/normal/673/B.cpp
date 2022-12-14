#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef complex<double> P;
typedef pair<int,int> pii;
#define REP(i,n) for(ll i=0;i<n;++i)
#define REPR(i,n) for(ll i=1;i<n;++i)
#define FOR(i,a,b) for(ll i=a;i<b;++i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

#define MOD (ll)(1e9+7)
#define ADD(a,b) a=((a)+(b))%MOD
#define FIX(a) ((a)%MOD+MOD)%MOD

int n,m;
vi g[125252];
int dv[125252];

int dfs(int x,int d){
  if(dv[x]!=-1 && dv[x]!=d)return -1;
  if(dv[x]!=-1)return dv[x];
  dv[x] = d;
  for(int to:g[x]){
    if(to<x && d==2)return -1;
    if(to>x && d==1)return -1;
    int tst;
    if(to<x){
      tst = dfs(to,2);
    }else{
      tst = dfs(to,1);
    }
    if(tst==-1)return -1;
  }
  return dv[x];
}

int main(){
  scanf("%d%d",&n,&m);
  REP(i,m){
    int u,v;
    scanf("%d%d",&u,&v);
    --u;--v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  REP(i,n)dv[i] = -1;
  ll ans = 1;
  bool flag = false;
  REP(i,n){
    if(dv[i]!=-1)continue;
    if(g[i].size()){
      int tst = dfs(i,2);
      if(tst==-1){
        ans = 0;
        break;
      }
      flag = true;
    }else{
      dv[i]=0;
    }
  }
  // min & max
  int mndv1=n-1, mxdv2=0;
  REP(i,n){
    if(dv[i]==1)mndv1=min(mndv1,(int)i);
    if(dv[i]==2)mxdv2=max(mxdv2,(int)i);
  }
  if(ans==0 || mndv1<mxdv2)ans = 0;
  else{
    ans = mndv1-mxdv2;
  }
  printf("%d\n",ans);
  return 0;
}