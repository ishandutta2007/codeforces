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

int n;
int p[525252];
string s;
int main(){
  scanf("%d",&n);
  REP(i,n)scanf("%d",p+i);
  cin>>s;
  ll beg = 0;
  REP(i,n)if(s[i]=='B')beg+=p[i];
  ll ans = beg;
  ll now;
  // prefix part
  now = beg;
  REP(i,n){
    if(s[i]=='A')now+=p[i];
    else now-=p[i];
    ans = max(ans,now);
  }
  // suffix part
  now = beg;
  REP(_i,n){
    int i = n-1-_i;
    if(s[i]=='A')now+=p[i];
    else now-=p[i];
    ans = max(ans,now);
  }
  cout<<ans<<endl;
  return 0;
}