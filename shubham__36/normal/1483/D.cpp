#pragma GCC optimize("Ofast")
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
typedef pair<ll, ll> p32;
typedef pair<ll, ll> p64;
typedef pair<p64, p64> pp64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<ll> v32;
typedef vector<vector<ll>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
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
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define zero ll(0)
#define set_bits(x) __builtin_popcountll(x)
// #define mll modll998244353
 
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
    if (b == 0)
        return 1;
    if (a == 0)
        return 0;
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
 
ll ceil(ll p, ll q)
{
    return (p + q - 1) / q;
}

struct node
{
	ll u,v,w;
};

void solve()
{
	ll n,m;
	cin >> n >> m;
	ll dist[n][n];
	forn(i,n) forn(j,n) dist[i][j]=INF;
	forn(i,n) dist[i][i]=0;
	node node[m];
	forn(i,m){
		cin >> node[i].u >> node[i].v >> node[i].w;
		node[i].u--;
		node[i].v--;
		dist[node[i].u][node[i].v]=node[i].w;
		dist[node[i].v][node[i].u]=node[i].w;
	}
    forn(k,n){
        forn(i,n){ 
            forn(j,n){
                if (dist[i][k] + dist[k][j] < dist[i][j]) dist[i][j] = dist[i][k] + dist[k][j]; 
            } 
        } 
    }
    ll q[n][n];
    forn(i,n) forn(j,n) q[i][j]=0;
    ll q1;
    cin >> q1;
    forn(i,q1){
    	ll u,v,w;
    	cin >> u >> v >> w;
    	u--,v--;
    	q[u][v]=w;
    	q[v][u]=w;
    }
    forn(k,n){
        forn(i,n){ 
            forn(j,n){
                if(q[i][j]-dist[k][j] > q[k][i]) q[k][i] = q[i][k] = q[i][j]-dist[k][j];
            } 
        } 
        // forn(i,n){
        // 	forn(j,n) cout << q[i][j] << " ";
        // 	cout << ln;
        // }
        // cout << ln;
    }
    // cout << q[1][3] << ln;
    ll ans = 0;
    forn(i,m){
    	if(node[i].w <= q[node[i].u][node[i].v]) {
    		ans++;
    		// cout << i << ln;
    	}
    }
    cout << ans << ln;
}
 
int main()
{
    fast_cin();
    ll t = 1;
    // cin >> t;
    forn(i, t)
    {
        // cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}