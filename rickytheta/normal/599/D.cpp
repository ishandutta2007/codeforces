#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef complex<double> P;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define REP(i,n) for(ll i=0;i<n;++i)
#define REPR(i,n) for(ll i=1;i<n;++i)
#define FOR(i,a,b) for(ll i=a;i<b;++i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

#define MOD (ll)(1e9+7)
#define ADD(a,b) a=((a)+(b))%MOD
#define FIX(a) ((a)%MOD+MOD)%MOD

vector<pll> res;

int main(){
  ll x;
  cin >> x;

  for(ll m=1;m*m<=x;++m){
    ll n = (6*x+m*m*m-m)/(3*m*(m+1));
    if(n < m)break;
    if(6*x == m*m*(3*n-m) + m*(3*n+1) )res.push_back(make_pair(m,n));
  }


  ll len = res.size();
  if(len == 0)return 0;
  pll last = res[len-1];
  if(last.first == last.second){
    printf("%lld\n",(2*len-1));
    for(ll i=0;i<len;++i){
      printf("%lld %lld\n",res[i].first,res[i].second);
    }
    for(ll i=len-2;i>=0;--i){
      printf("%lld %lld\n",res[i].second,res[i].first);
    }
  }else{
    printf("%lld\n",(2*len));
    for(ll i=0;i<len;++i){
      printf("%lld %lld\n",res[i].first,res[i].second);
    }
    for(ll i=len-1;i>=0;--i){
      printf("%lld %lld\n",res[i].second,res[i].first);
    }
  }

  return 0;
}