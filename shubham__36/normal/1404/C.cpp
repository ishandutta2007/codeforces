#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 1e9+7;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln '\n'
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 1e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define zero ll(0)
 
ll mpow(ll a, ll b){
	if(a==0) return 0;
	if(b==0) return 1;
	ll t1 = mpow(a,b/2);
	t1 *= t1;
	t1 %= MOD;
	if(b%2) t1 *= a;
	t1 %= MOD;
	return t1;
}
 
ll mpow(ll a, ll b, ll p){
	if(a==0) return 0;
	if(b==0) return 1;
	ll t1 = mpow(a,b/2,p);
	t1 *= t1;
	t1 %= p;
	if(b%2) t1 *= a;
	t1 %= p;
	return t1;
}
 
ll modinverse(ll a, ll m){
	ll m0 = m; 
    ll y = 0, x = 1; 
    if (m == 1) return 0; 
    while (a > 1){
        ll q = a / m; 
        ll t = m; 
        m = a % m, a = t; 
        t = y; 
        y = x - q * y; 
        x = t; 
    }
    if (x < 0) x += m0; 
    return x; 
}

mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
 
ll range(ll l, ll r){
	return l + mt()%(r-l+1);
}
 
ll rev(ll v){
	return mpow(v,MOD-2);
}

typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

class SegmentTree {
	ll n;
	v64 t;

	public:

	SegmentTree(ll n1){
		n = n1;
		t.assign(2*n,0);
	}

	ll at(ll index){
		return t[index];
	}

	void build() {  // build the tree
	  rforn(i,n-1) t[i] = t[i<<1] + t[i<<1|1];
	}

	void modify(ll p, ll value) {  // set value at position p
// 	  cout << "modify " << p << " " << value << ln;
	  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
// 	  cout << t[1];
	}

	ll query(ll l, ll r) {  // sum on interval [l, r)
// 	  cout << "query " << l << "  " << r << ln;
	  ll res = 0;
	  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
	   // cout << l << " " << r << ln;
	    if (l&1) res += t[l++];
	    if (r&1) res += t[--r];
	   // cout << res << ln;
	  }
// 	  cout << res << ln;
	  return res;
	}

	void modify(ll l, ll r, ll value) {
	  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
	    if (l&1) t[l++] += value;
	    if (r&1) t[--r] += value;
	  }
	}

	ll query(ll p) {
	  ll res = 0;
	  for (p += n; p > 0; p >>= 1) res += t[p];
	  res = min(res,n);
	  return res;
	}

	void push() {
	  forn (i,n) {
	    t[i<<1] += t[i];
	    t[i<<1|1] += t[i];
	    t[i] = 0;
	  }
	}
};


void solve(){
	ll n,q;
	cin >> n >> q;
	ll a[n];
	SegmentTree S(n);
	ordered_set index;
	forn(i,n) index.insert(i);
	forn(i,n) cin >> a[i],a[i]--;
	p64 query[q];
	set<p64> s;
	ll ans[q];
	forn(i,q){
		cin >> query[i].fi >> query[i].se;
		s.insert(mp(-query[i].fi,i));
	}
	ll cur = n-1;
	v64 vec[n];
	for(auto it : s){
		ll fv = -(it.fi+1);
		while(cur > fv){
			ll v1 = cur-a[cur];
			if(v1==0){
				S.modify(cur,1);
				ll st=n,en=n;
				if(sz(index)>1){
					st = *index.find_by_order(1);
					index.erase(index.find_by_order(1));
				}
				if(sz(index)>1){
					en = *index.find_by_order(1);
				}
				forsn(i,st,en) for(auto it : vec[i]) S.modify(it,1);
			}
			else if(v1 > 0 && v1 < sz(index)){
				ll curin = *index.find_by_order(v1);
				vec[curin].pb(cur);
				if(v1+1 < sz(index)) index.erase(index.find_by_order(v1+1));
			}
			cur--;
		}
		ans[it.se]=S.query(0,n-query[it.se].se);
	}
	forn(i,q) cout << ans[i] << ln;
}
 
int main()
{
	fast_cin();
	ll t=1;
    // cin >> t;
    forn(i,t) {
    	// cout << "Case #" << i+1 << ": ";
    	solve();
    }
    return 0;
}