#pragma GCC optimize("-Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
// #include <atcoder/all>
// #include <bits/stdc++.h>
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>

using namespace std;
// using namespace atcoder;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<p64, p64> pp64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
typedef pair<ll, p64> tp;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i, e) for (ll i = 0; i < e; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define ln '\n'
#define dbg(x) cout << #x << " = " << x << ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 1e18
#define fast_cin()                    \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define zero ll(0)
#define set_bits(x) __builtin_popcountll(x)
// #define mint modint998244353

ll mpow(ll a, ll b)
{
	if (a == 0)
		return 0;
	if (b == 0)
		return 1;
	ll t1 = mpow(a, b / 2);
	t1 *= t1;
	t1 %= MOD;
	if (b % 2)
		t1 *= a;
	t1 %= MOD;
	return t1;
}

ll mpow(ll a, ll b, ll p)
{
	if (a == 0)
		return 0;
	if (b == 0)
		return 1;
	ll t1 = mpow(a, b / 2, p);
	t1 *= t1;
	t1 %= p;
	if (b % 2)
		t1 *= a;
	t1 %= p;
	return t1;
}

ll modinverse(ll a, ll m)
{
	ll m0 = m;
	ll y = 0, x = 1;
	if (m == 1)
		return 0;
	while (a > 1)
	{
		ll q = a / m;
		ll t = m;
		m = a % m, a = t;
		t = y;
		y = x - q * y;
		x = t;
	}
	if (x < 0)
		x += m0;
	return x;
}

mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());

ll range(ll l, ll r)
{
	return l + mt() % (r - l + 1);
}

ll rev(ll v)
{
	return mpow(v, MOD - 2);
}

ll nc2(ll n)
{
	return (n * (n - 1)) / 2;
}

struct cell{
	ll index,sum,num;

	cell(){
	}

	cell(ll i, ll s, ll n){
		index = i;
		sum = s;
		num = n;
	}

	p64 avg(){
		return mp(sum,num);
	}
};

bool cmp(p64 a, p64 b){
	return a.fi*b.se < a.se*b.fi;
}

bool cmp1(cell a, cell b){
	return cmp(a.avg(),b.avg());
}

class SegmentTree {
	ll n;
	v64 t;

	public:

	SegmentTree(ll n1){
		n = n1;
		t.assign(2*n,0);
	}

	void modify(ll p, ll value) {  // set value at position p
	  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = max(t[p],t[p^1]);
	}

	ll query(ll l, ll r) {  // sum on interval [l, r)
	  ll res = 0;
	  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
	    if (l&1) res = max(res,t[l++]);
	    if (r&1) res = max(res,t[--r]);
	  }
	  return res;
	}
};

void solve()
{
	ll n,m;
	cin >> n >> m;
	p64 a[n];
	forn(i,n) {
		cin >> a[i].fi;
		a[i].se=1;
	}
	sort(a,a+n);
	v64 b[m];
	v64 ans[m];
	cell c[m];
	forn(i,m){
		ll k;
		cin >> k;
		b[i].resize(k);
		ans[i].resize(k,0);
		ll sum = 0;
		forn(j,k) {
			cin >> b[i][j];
			sum += b[i][j];
		}
		c[i] = cell(i,sum,k);
	}
	sort(c,c+m,cmp1);
	SegmentTree S(m);
	ll over = m;
	set<ll> eq;
	rforn(i,m-1){
		ll l = 0, r = n;
		while(l<r){
			ll mid = (l+r)/2;
			// cout << mid << " " << a[mid].fi << " " << a[mid].se << " " << c[i].avg().fi << " " << c[i].avg().se << ln;
			if(cmp(a[mid],c[i].avg())) l = mid+1;
			else r = mid;
		}
		S.modify(i,l+(m-i));
		// cout << i << " " << l+(m-i) << ln;
		if(l+(m-i) > n) over = i;
		if(l+(m-i) == n) eq.insert(i);
	}
	forn(i,m){
		if(*eq.begin() == i) eq.erase(eq.begin());
		if(S.query(i+1,m)<n+1){
			if(over < i){
				if(S.query(over,i)<n+2){
					ll ci = 0;
					for(auto j:b[c[i].index]){
						if(!cmp(a[n-m+over],mp(c[i].sum-j,c[i].num-1))) ans[c[i].index][ci]=1;
						ci++;
					}
				}
			}
			else{
				ll r = n;
				if(sz(eq)) r = n-m+(*eq.begin());
				r--;
				// cout << r << ln;
					ll ci = 0;
					for(auto j:b[c[i].index]){
						if(!cmp(a[r],mp(c[i].sum-j,c[i].num-1))) ans[c[i].index][ci]=1;
						ci++;
					}
			}
		}
	}
	forn(i,m) for(auto it : ans[i]) cout << it;
	cout << ln;
}

int main()
{
	fast_cin();
	ll t=1;
	cin >> t;
	forn(i, t)
	{
		// cout << "Case #" << i+1 << ": ";
		solve();
	}
	return 0;
}