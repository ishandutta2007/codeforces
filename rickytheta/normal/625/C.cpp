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
  ll n,k;
  cin>>n>>k;
  ll res[n][n];
  ll iter = 1;
  --k;
  REP(j,k)REP(i,n)res[i][j] = iter++;
  REP(i,n)FOR(j,k,n)res[i][j] = iter++;
  ll sum = 0;
  REP(i,n)sum+=res[i][k];
  cout<<sum<<endl;
  REP(i,n){
    cout<<res[i][0];
    REPR(j,n)cout<<" "<<res[i][j];
    cout<<endl;
  }
  return 0;
}