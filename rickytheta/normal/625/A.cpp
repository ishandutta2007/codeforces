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
  ll n,a,b,c;
  cin>>n>>a>>b>>c;
  if(a <= b-c || n<b){
    cout<<(n/a)<<endl;
  }else{
    ll res = 0;
    ll tgt = n-b;
    res += tgt/(b-c);
    n = b + tgt%(b-c);
    while(n>=b){
      ll cnt = n/b;
      res += cnt;
      n -= cnt*b;
      n += cnt*c;
    }
    res += n/a;
    cout<<res<<endl;
  }
  return 0;
}