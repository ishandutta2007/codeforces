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
  ll x=0,y=0;
  ll n,bx;
  cin >> n >> bx;
  REP(i,n){
    x *= bx;
    ll tx;
    cin >> tx;
    x += tx;
  }
  ll m,by;
  cin >> m >> by;
  REP(i,m){
    y *= by;
    ll ty;
    cin >> ty;
    y += ty;
  }
  if(x<y)cout<<"<";
  if(x>y)cout<<">";
  if(x==y)cout<<"=";
  cout<<endl;
  return 0;
}