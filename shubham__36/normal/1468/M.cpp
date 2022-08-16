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
ll MOD = 1e9 + 7;
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
// #define zero ll(0)
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

ll ceil(ll p, ll q)
{
    return (p + q - 1) / q;
}

const ll M = 500;

void solve()
{
    int n;
    cin >> n;
    map<ll, int> num;
    v64 vec[n];
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            int temp;
            cin >> temp;
            vec[i].push_back(temp);
            if (num.find(temp) == num.end())
            {
                num[temp] = cnt++;
            }
        }
    }
    v64 inverted[cnt];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < sz(vec[i]); j++)
        {
            vec[i][j] = num[vec[i][j]];
            if(sz(vec[i])<M) inverted[vec[i][j]].pb(i);
        }
        sort(all(vec[i]));
    }
    v64 pr(cnt,0);
    forn(i,n){
    	if(sz(vec[i])>=M){
    		for(auto it : vec[i]) pr[it]++;
    		forn(j,n){
    			if(i!=j){
    				ll cur = 0;
    				for(auto it : vec[j]) if(pr[it])cur++;
    				if(cur >= 2){
    					cout << i+1 << " " << j+1 << ln;
    					return;
    				}
    			}
    		}
    		for(auto it : vec[i]) pr[it]--;
    	}
    }
    forn(i,cnt) pr[i]=-1;
    rforn(i,cnt-1){
    	for(auto j : inverted[i]){
    		vec[j].pop_back();
    		for(auto it : vec[j]){
    			if(~pr[it]){
    				cout << pr[it]+1 << " " << j+1 << ln;
    				return;
    			}
    			pr[it]=j;
    		}
    	}
    	for(auto j : inverted[i]){
    		for(auto it : vec[j]){
    			pr[it]=-1;
    		}
    	}
    }
    cout << -1 << ln;
}

int main()
{
    fast_cin();
    ll t = 1;
    cin >> t;
    forn(i, t)
    {
        // cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}