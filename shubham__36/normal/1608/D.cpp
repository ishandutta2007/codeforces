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

const ll N = 2e5+5;
ll fact[N],rfact[N];

ll ncr(ll n, ll r){
	// cout << n << " " << r << ln;
	if(r<0 || r>n) return 0;
	ll ans = rfact[r]*rfact[n-r];
	ans %= MOD;
	return (fact[n]*ans)%MOD;
}

void solve()
{
	ll n;
	cin >> n;
	string s[n];
	ll ww=0,bb=0,dq=0,sw=0,sb=0;
	forn(i,n){
		cin >> s[i];
		if(s[i]=="WW" ) ww++;
		else if(s[i]=="BB") bb++;
		else if(s[i]=="??") dq++;
		else if(s[i]=="WB" || s[i]=="BW");
		else if(s[i][0]=='W' || s[i][1]=='W') sw++;
		else sb++;
	}
	ll ans = 0;
	forsn(i,-n,n+1){
		ll j = i-(ww-bb);
		ans += ncr(2*dq,dq+i)*ncr(sw+sb,sb+j);
		ans %= MOD;
	}
	if(ww==0 && bb==0){
		ans += MOD-mpow(2,dq);
		ll c1 = 1, c2 = 1;
		forn(i,n){
			if(s[i][0]=='W' || s[i][1]=='B') c1=0;
			if(s[i][0]=='B' || s[i][1]=='W') c2=0;
		}
		ans += c1+c2;
		ans %= MOD;
	}
	cout << ans << ln;
}

int main()
{
	fast_cin();
	ll t = 1;
	fact[0]=1;
	forsn(i,1,N) fact[i]=(fact[i-1]*i)%MOD;
	forn(i,N) rfact[i]=rev(fact[i]);
	// cin >> t;
	forn(i, t)
	{
		// cout << "Case #" << i+1 << ": ";
		solve();
	}
	return 0;
}