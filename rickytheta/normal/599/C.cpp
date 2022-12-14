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
  ll n;
  cin >> n;
  vl h(n);
  REP(i,n) cin>>h[i];

  // maxh[i] := max( h[0]~h[i] )
  // minh[i] := min( h[i]~h[n-1] )
  vl minh(n),maxh(n);
  maxh[0] = h[0];
  minh[n-1] = h[n-1];
  REPR(i,n){
    maxh[i] = max(maxh[i-1],h[i]);
    minh[n-1-i] = min(minh[n-i],h[n-1-i]);
  }

  ll result = 1;
  REPR(i,n){
    if(maxh[i-1] <= minh[i])++result;
  }

  cout << result << endl;

  return 0;
}