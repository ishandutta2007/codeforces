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
int n;
void bfs(int i, int j, vector<string> &matrix, vv64 &level, v64 &counter)
{
    // cout << i << " " << j << endl;
    vp64 frontier;
    frontier.push_back(p64(i, j));
    level[i][j] = 0;
    while (sz(frontier) > 0)
    {
        vp64 next;
        for (int i = 0; i < sz(frontier); i++)
        {
            int x = frontier[i].fi, y = frontier[i].se;
            if (x < n && level[x + 1][y] == -1 && matrix[x + 1][y] == 'X')
            {
                level[x + 1][y] = level[x][y] + 1;
                counter[level[x + 1][y] % 3]++;
                next.push_back(p64(x + 1, y));
            }
            if (y < n && level[x][y + 1] == -1 && matrix[x][y + 1] == 'X')
            {
                level[x][y + 1] = level[x][y] + 1;
                counter[level[x][y + 1] % 3]++;
                next.push_back(p64(x, y + 1));
            }
            if (x > 1 && level[x - 1][y] == -1 && matrix[x - 1][y + 1] == 'X')
            {
                level[x - 1][y] = level[x - 1][y] + 1;
                counter[level[x - 1][y] % 3]++;
                next.push_back(p64(x - 1, y));
            }
            if (y > 1 && level[x][y - 1] == -1 && matrix[x][y - 1] == 'X')
            {
                level[x][y - 1] = level[x][y] + 1;
                counter[level[x][y - 1] % 3]++;
                next.push_back(p64(x, y - 1));
            }
        }
        frontier = next;
    }
}
void solve()
{
    v64 a(4, 0);
    for (int i = 0; i < 4; i++)
        cin >> a[i];
    sort(all(a));
    cout << a[0] * a[2] << endl;
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