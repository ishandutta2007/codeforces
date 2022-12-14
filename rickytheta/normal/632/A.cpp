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
  int n,p;
  cin>>n>>p;
  vector<bool> vb(n);
  REP(i,n){
    string s;
    cin>>s;
    vb[i] = (s=="halfplus");
  }
  ll num = 0;
  REP(i,n){
    num<<=1;
    if(vb[n-1-i])num+=1;
  }
  ll res = 0;
  REP(i,n){
    res += (p*num/2);
    num /= 2;
  }
  cout<<res<<endl;
  return 0;
}