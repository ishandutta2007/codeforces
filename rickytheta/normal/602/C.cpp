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

#define INF 1e9

int main(){
  ll n,m;
  cin >> n >> m;
  vector<vi> g(n,vi(n,INF));
  REP(i,m){
    int u,v;
    cin >> u >> v;
    --u;
    --v;
    g[u][v] = 1;
    g[v][u] = 1;
  }
  vector<vi> train = g;
  vector<vi> bus = g;
  REP(i,n)REP(j,n){
    if(i==j)continue;
    if(bus[i][j] == 1)bus[i][j] = INF;
    else bus[i][j] = 1;
  }

  REP(k,n)REP(i,n)REP(j,n)train[i][j]=min(train[i][j],train[i][k]+train[k][j]);
  REP(k,n)REP(i,n)REP(j,n)bus[i][j]=min(bus[i][j],bus[i][k]+bus[k][j]);

  int t_cost = train[0][n-1];
  int b_cost = bus[0][n-1];
  int result = max(t_cost,b_cost);
  if(result == INF){
    cout << -1 << endl;
  }else{
    cout << result << endl;
  }
  return 0;
}