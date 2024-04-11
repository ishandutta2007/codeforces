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

p64 combine(p64 a, p64 b)
{
    if (a.fi > b.fi)
        return a;
    if (b.fi > a.fi)
        return b;
    if (a.fi == b.fi)
    {
        if (a.se < b.se)
            return a;
        else
        {
            return b;
        }
    }
}

void update(int node, int start, int end, int idx, p64 val, vp64 &tree)
{
    if (start == end)
    {
        // Leaf node
        // A[idx] += val;
        tree[node] = combine(tree[node], val);
    }
    else
    {
        int mid = (start + end) / 2;
        if (start <= idx and idx <= mid)
        {
            // If idx is in the left child, recurse on the left child
            update(2 * node, start, mid, idx, val, tree);
        }
        else
        {
            // if idx is in the right child, recurse on the right child
            update(2 * node + 1, mid + 1, end, idx, val, tree);
        }
        // Internal node will have the sum of both of its children
        tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
    }
}
p64 query(int node, int start, int end, int l, int r, vp64 &tree)
{
    if (r < start or end < l)
    {
        // range represented by a node is completely outside the given range
        return p64(-1, -1);
    }
    if (l <= start and end <= r)
    {
        // range represented by a node is completely inside the given range
        return tree[node];
    }
    // range represented by a node is partially inside and partially outside the given range
    int mid = (start + end) / 2;
    p64 p1 = query(2 * node, start, mid, l, r, tree);
    p64 p2 = query(2 * node + 1, mid + 1, end, l, r, tree);
    return combine(p1, p2);
}

void solve()
{
    int n, k, l;
    cin >> n >> k >> l;
    int m = k / 2;
    v64 arr(l + 1, 0);
    v64 pre(l + 1, 0);
    for (int i = 1; i <= l; i++)
    {
        cin >> arr[i];
        int diff = (arr[i] - arr[i - 1] - 1);
        pre[i] = pre[i - 1] + diff;
    }
    int alpha = pre[l];
    int diff = (n - arr[l]);
    alpha += diff;
    if (alpha % (2 * m) != 0)
    {
        cout << "NO" << endl;
        return;
    }
    alpha /= 2 * m;
    ll total = 2 * alpha * m;
    if (total == 0)
    {
        cout << "YES" << endl;
        return;
    }
    for (int i = 1; i <= l; i++)
    {
        if (pre[i] >= m && total - pre[i] >= m)
        {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
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