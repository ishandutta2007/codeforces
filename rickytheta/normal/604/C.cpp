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
  string s;
  cin >> s;

  ll ln = 1;
  ll c = s[0];
  REPR(i,n){
    if(s[i]!=c){
      ++ln;
      c = s[i];
    }
  }

  ll iter = 0;
  ll third = 0;
  ll second = 0;
  while(iter<n){
    c = s[iter];
    ll cnt = 1;
    while(++iter<n && c==s[iter])++cnt;
    if(cnt>=3)++third;
    else if(cnt==2)++second;
  }
  if(third>0)ln+=2;
  else if(second>1)ln+=2;
  else if(second>0)ln+=1;
  cout << ln << endl;

  return 0;
}