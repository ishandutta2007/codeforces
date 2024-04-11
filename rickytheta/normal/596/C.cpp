#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef complex<double> P;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define REP(i,n) for(ll i=0;i<n;++i)
#define REPR(i,n) for(ll i=1;i<n;++i)
#define FOR(i,a,b) for(ll i=a;i<b;++i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

#define MOD (ll)(1e9+7)
#define ADD(a,b) a=((a)+(b))%MOD
#define FIX(a) ((a)%MOD+MOD)%MOD

vl ways[200010];
int main(){
  ll b = 1e6;
  ll n;
  cin >> n;
  // vl p(n);
  vl iter(200010);
  REP(i,n){
    ll x,y;
    cin >> x >> y;
    // p[i] = x*b+y;
    ways[y-x+100000].push_back(x*b+y);
  }
  REP(i,200010)sort(ALL(ways[i]));

  vl ans(n);
  REP(i,n){
    ll w;
    cin >> w;
    w += 100000;
    if(ways[w].size() == iter[w]){
      cout << "NO" << endl;
      return 0;
    }
    ans[i] = ways[w][iter[w]];
    iter[w]++;
  }

  set<pll> vs;
  vs.insert(make_pair(ans[0]/b,ans[0]%b));
  REPR(i,n){
    ll x = ans[i]/b;
    ll y = ans[i]%b;
    set<pll>::iterator iter = vs.lower_bound(make_pair(x,0));
    if(iter != vs.end()){
      if(y <= iter->second){
        cout << "NO" << endl;
        return 0;
      }
    }
    iter = vs.insert(iter,make_pair(x,y));
    if(iter == vs.begin())continue;
    --iter;
    while(iter != vs.begin()){
      if(iter->second <= y){
        vs.erase(iter--);
      }else{
        break;
      }
    }
  }

  cout << "YES" << endl;
  REP(i,n){
    cout << (ll)(ans[i]/b) << " " << (ll)(ans[i]%b) << endl;
  }
  return 0;
}