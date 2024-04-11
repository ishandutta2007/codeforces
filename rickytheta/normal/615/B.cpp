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

int main(){
  int n,m;
  cin>>n>>m;
  vi edges[n];
  vi deg(n,0);
  REP(i,m){
    int x,y;
    cin>>x>>y;
    --x;--y;
    if(x>y)swap(x,y);
    edges[x].push_back(y);
    ++deg[x];
    ++deg[y];
  }
  vi dp(n,1);
  REP(i,n){
    REP(j,edges[i].size()){
      int to = edges[i][j];
      dp[to] = max(dp[to],dp[i]+1);
    }
  }
  ll result = 0;
  REP(i,n){
    result = max(result, (ll)deg[i]*(ll)dp[i]);
  }
  cout<<result<<endl;
  return 0;
}