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

int last[1010];

int main(){
  // s -> 0
  int n,s;
  cin>>n>>s;
  REP(i,n){
    int f,t;
    cin>>f>>t;
    last[f] = max(last[f],t);
  }
  int tm = 0;
  REP(i,s+1){
    int now = s-i;
    tm = max(tm,last[now]);
    tm += 1;
  }
  cout << tm-1 << endl;
  return 0;
}