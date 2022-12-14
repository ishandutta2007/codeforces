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
  ll n,m;
  cin>>n>>m;
  string s;
  cin>>s;
  int idx[26];
  REP(i,26)idx[i]=i;
  REP(i,m){
    char from,to;
    cin>>from>>to;
    swap(idx[from-'a'],idx[to-'a']);
  }
  int rev[26];
  REP(i,26)rev[idx[i]]=i;
  REP(i,n){
    cout << (char)(rev[s[i]-'a']+'a');
  }
  cout<<endl;
  return 0;
}