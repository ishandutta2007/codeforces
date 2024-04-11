#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <cstdint>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <functional>
#include <ctime>
#include <fstream>
#include <cmath>
#include <limits>
#include <chrono>
#include <numeric>
#include <type_traits>
#include <iomanip>
#include <float.h>
#include <math.h>
#include <cassert>
#pragma warning (disable: 4996)
using namespace std;

using ll = long long;
unsigned euclidean_gcd(unsigned a, unsigned b) {
    if (a < b) return euclidean_gcd(b, a);
    unsigned r;
    while ((r = a % b)) {
        a = b;
        b = r;
    }
    return b;
}

ll ll_gcd(ll a, ll b) {
    if (a < b) return ll_gcd(b, a);
    ll r;
    while ((r = a % b)) {
        a = b;
        b = r;
    }
    return b;
}

struct UnionFind {
    vector <ll> par;
    vector <ll> siz;
    UnionFind(ll sz_) : par(sz_), siz(sz_, 1LL) {
        for (ll i = 0; i < sz_; ++i) par[i] = i;
    }
    void init(ll sz_) {
        par.resize(sz_);
        siz.assign(sz_, 1LL);
        for (ll i = 0; i < sz_; ++i) par[i] = i;
    }
    ll root(ll x) {
        while (par[x] != x) {
            x = par[x] = par[par[x]];
        }
        return x;
    }
    bool merge(ll x, ll y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (siz[x] < siz[y]) swap(x, y);
        siz[x] += siz[y];
        par[y] = x;
        return true;
    }

    bool issame(ll x, ll y) {
        return root(x) == root(y);
    }

    ll size(ll x) {
        return siz[root(x)];
    }
};

long long modpow(long long a, long long n, long long mod) {
    if (n < 0)return 0;
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

long long modinv(long long a, long long mod) {
    return modpow(a, mod - 2, mod);
}

ll merge_cnt(vector<ll>& a) {
    int n = a.size();
    if (n <= 1) { return 0; }

    ll cnt = 0;
    vector<ll> b(a.begin(), a.begin() + n / 2);
    vector<ll> c(a.begin() + n / 2, a.end());

    cnt += merge_cnt(b);
    cnt += merge_cnt(c);

    int ai = 0, bi = 0, ci = 0;
    while (ai < n) {
        if (bi < b.size() && (ci == c.size() || b[bi] <= c[ci])) {
            a[ai++] = b[bi++];
        }
        else {
            cnt += n / 2 - bi;
            a[ai++] = c[ci++];
        }
    }
    return cnt;
}

struct edge { ll to; ll cost; };
typedef pair<ll, ll> P;
struct graph {
    ll V;
    vector<vector<edge> > G;
    vector<ll> d;

    graph(ll n) {
        init(n);
    }

    void init(ll n) {
        V = n;
        G.resize(V);
        d.resize(V);
        for (int i = 0; i < V; i++) {
            d[i] = 2000000000000000000;
        }
    }

    void add_edge(ll s, ll t, ll cost) {
        edge e;
        e.to = t, e.cost = cost;
        G[s].push_back(e);
    }

    void dijkstra(ll s) {
        for (int i = 0; i < V; i++) {
            d[i] = 2000000000000000000;
        }
        d[s] = 0;
        priority_queue<P, vector<P>, greater<P> > que;
        que.push(P(0, s));
        while (!que.empty()) {
            P p = que.top(); que.pop();
            ll v = p.second;
            if (d[v] < p.first) continue;
            for (auto e : G[v]) {
                if (d[e.to] > d[v] + e.cost / (ll)1100000000 + (e.cost % (ll)1100000000)) {
                    d[e.to] = d[v] + e.cost;
                    que.push(P(d[e.to], e.to));
                }
            }
        }
    }
};

vector<int> makeTable(const string& s) {
    int n = s.size();
    vector<int> ret(n + 1);
    ret[0] = -1;
    int j = -1;
    for (int i = 0; i < n; i++) {
        while (j >= 0 && s[i] != s[j]) j = ret[j];
        ret[i + 1] = ++j;
    }
    return ret;
}

vector<int> kmp(const string& str, const string& word) {
    vector<int> table = makeTable(word), ret;
    int m = 0, i = 0, n = str.size();
    while (m + i < n) {
        if (word[i] == str[m + i]) {
            if (++i == (int)(word.size())) {
                ret.push_back(m);
                m = m + i - table[i];
                i = table[i];
            }
        }
        else {
            m = m + i - table[i];
            if (i > 0) i = table[i];
        }
    }
    return ret;
}

ll dps(vector<vector<ll>>& dp, vector<vector<ll>>& z, ll l, ll r) {
    if (l == r)return 0;
    if (dp[l][r] != -1)return dp[l][r];
    vector<int> f(102, 0);
    for (int i = 0; i < z.size(); i++) {
        if (l <= z[i][0] && z[i][1] <= r) {
            f[dps(dp, z, l, z[i][0]) ^ dps(dp, z, z[i][1], r)] = 1;
        }
    }
    for (int i = 0; i < 102; i++) {
        if (f[i] == 0) {
            dp[l][r] = i;
            return i;
        }
    }
}


int main() {
    ll t;
    cin >> t;
    for (int ik = 0; ik < t; ik++) {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        string t = s;
        sort(t.begin(), t.end());
        ll ans = 0;
        for (int j = 0; j < t.size(); j++) {
            if (s[j] != t[j])ans++;
        }
        cout << ans << endl;
    }
}