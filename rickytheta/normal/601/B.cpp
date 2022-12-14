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

#define MP make_pair

ll sz(ll m,ll pos){
  return (m-pos)*(pos+1);
}

struct dia{
  ll max, pos, left, right;
};

int main(){
  ll n,q;
  cin >> n >> q;
  ll a[n];
  REP(i,n)cin >> a[i];

  ll b[n-1];
  REPR(i,n){
    b[i-1] = abs(a[i-1]-a[i]);
  }

  while(q--){
    ll l,r;
    cin >> l >> r;
    --l; --r;
    ll s = r-l;

    ll res = 0;
    stack<dia> st;
    st.push( (dia){1e18,0,0,0} );
    REP(i,s){
      while(st.top().max <= b[i+l]){
        dia yee = st.top();
        yee.right = i;
        res += yee.max * sz(yee.right-yee.left+1,yee.pos-yee.left);
        st.pop();
      }
      dia yee;
      yee.max = b[i+l];
      yee.left = st.top().pos + 1;
      yee.pos = i+1;
      st.push(yee);
    }
    while(st.size()>1){
      dia yee = st.top();
      yee.right = s;
      res += yee.max * sz(yee.right-yee.left+1,yee.pos-yee.left);
      st.pop();
    }
    cout << res << endl;
  }

  return 0;
}