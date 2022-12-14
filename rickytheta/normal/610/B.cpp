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
  cin>>n;
  vl a(n);
  REP(i,n)cin>>a[i];
  ll minval = 1e18;
  REP(i,n)minval=min(minval,a[i]);
  ll result = 0;
  a.push_back(minval);
  vl conn;
  ll cnt = 0;
  REP(i,n+1){
    if(a[i]==minval){
      conn.push_back(cnt);
      cnt = 0;
    }else{
      ++cnt;
    }
  }
  if(a[0]!=minval && a[n-1]!=minval)conn.push_back(conn[0]+conn[conn.size()-1]);
  REP(i,conn.size())result = max(result,conn[i]);
  result += minval*n;
  cout << result << endl;
  return 0;
}