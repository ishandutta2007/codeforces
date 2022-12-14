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

void solve(){
  string POS = "Possible";
  string AMB = "Ambiguity";
  string IMP = "Impossible";
  ll n,m;
  cin >> n >> m;
  bool ambf = false;
  vector<bool> ambfs(n,false);
  vl f(n),b(m);
  REP(i,n) cin>>f[i],--f[i];
  REP(i,m) cin>>b[i],--b[i];

  vl rev(n,-114514);
  REP(i,n){
    if(rev[f[i]]!=-114514){
      ambfs[f[i]] = true;
    }
    rev[f[i]] = i;
  }
  vl a(m);
  REP(i,m){
    if(rev[b[i]]==-114514){
      cout << IMP << endl;
      return;
    }
    if(ambfs[b[i]])ambf = true;
    a[i] = rev[b[i]]+1;
  }
  if(ambf){
    cout << AMB << endl;
    return;
  }
  cout << POS << endl;
  cout << a[0];
  REPR(i,m)cout<<" "<<a[i];
  cout << endl;
}

int main(){
  solve();
  return 0;
}