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

ll powmod(ll a,ll b){
  if(b==0)return 1;
  ll ans = 1ll;
  while(b){
    if(b&1ll) ans=ans*a%MOD;
    a=a*a%MOD;
    b>>=1;
  }
  return ans;
}

ll inv(ll x,ll m){
  return powmod(x,m-2ll);
}

#define P_MAX 200100

ll pri[P_MAX];

int main(){
  ll m;
  cin>>m;
  REP(i,P_MAX){
    pri[i] = 0;
  }
  REP(i,m){
    ll x;
    cin>>x;
    pri[x]++;
  }
  ll primul = 1ll;
  bool flag = false;
  REP(i,P_MAX){
    primul *= (ll)(pri[i] + 1ll);
    if(!flag && pri[i]%2==1){
      flag = true;
      primul /= 2;
    }
    primul %= MOD-1;
  }
  ll result = 1ll;
  REP(i,P_MAX){
    result *= powmod(i,primul*pri[i]/(flag?1:2)%(MOD-1));
    result %= MOD;
  }
  result = FIX(result);
  cout<<result<<endl;
  return 0;
}