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

int rev[364364];

set<pii> S;
multiset<int> MS;

set<pii>::iterator iter;

int main(){
  int n,m;
  scanf("%d%d",&n,&m);
  REP(i,n){
    int x;
    scanf("%d",&x);
    --x;
    rev[x] = i;
  }
  REP(i,m){
    int x,y;
    scanf("%d%d",&x,&y);
    --x; --y;
    x = rev[x];
    y = rev[y];
    if(x>y)swap(x,y);
    S.insert(pii(x,y));
  }
  iter = S.begin();
  while(iter != S.end()){
    pii p = *iter;
    int x = p.first;
    int y = p.second;
    MS.insert(y);
    ++iter;
  }
  MS.insert(n);
  ll res = 0;
  iter = S.begin();
  REP(i,n-1){
    ll j = *(MS.begin());
    res += (j-1-i);
    while(iter!=S.end() && iter->first==i){
      MS.erase(MS.find(iter->second));
      ++iter;
    }
  }
  res += n;
  cout<<res<<endl;
  return 0;
}