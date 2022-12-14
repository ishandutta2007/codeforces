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

int main(){
  int n,m;
  scanf("%d%d",&n,&m);
  int a[n+1];
  REP(i,n) scanf("%d",a+i);
  // (`)
  // 
  set<pll> R;
  a[n] = -1;
  ll bef = a[0];
  ll left = 0;
  REPR(i,n+1){
    if(bef != a[i]){
      // add range
      R.insert(make_pair<ll,ll>(left,bef));
      bef = a[i];
      left = i;
    }
  }
  R.insert(make_pair<ll,ll>(left,bef));
  while(m--){
    // query
    int l,r,x;
    scanf("%d%d%d",&l,&r,&x);
    --l; --r;
    set<pll>::iterator iter,iter2,iter3;
    iter2 = R.upper_bound(make_pair<ll,ll>(l,10000000000ll));
    iter = iter2; --iter;
    if(iter->second != x){
      printf("%d\n",l+1);
    }else if(iter2->first > r){
      printf("%d\n",-1);
    }else{
      printf("%d\n",iter2->first + 1);
    }
  }
  return 0;
}