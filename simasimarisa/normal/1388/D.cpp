#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
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
#include <numeric>
#include <type_traits>
#include <iomanip>
#include <float.h>
#include <math.h>
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

vector<int> tpsort(vector<vector<int>>& G) {
    int V = G.size();
    vector<int> sorted_vertices;
    queue<int> que;
    vector<int> indegree(V);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < G[i].size(); j++) {
            indegree[G[i][j]]++;
        }
    }
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            que.push(i);
        }
    }
    while (que.empty() == false) {
        int v = que.front();
        que.pop();
        for (int i = 0; i < G[v].size(); i++) {
            int u = G[v][i];
            indegree[u] -= 1;
            if (indegree[u] == 0) que.push(u);
        }
        sorted_vertices.push_back(v);
    }
    return sorted_vertices;
}

struct Point
{
    double x;
    double y;
};

struct LineSegment
{
    Point start;
    Point end;
};

double tenkyori(const LineSegment& line, const Point& point)
{
    double x0 = point.x, y0 = point.y;
    double x1 = line.start.x, y1 = line.start.y;
    double x2 = line.end.x, y2 = line.end.y;

    double a = x2 - x1;
    double b = y2 - y1;
    double a2 = a * a;
    double b2 = b * b;
    double r2 = a2 + b2;
    double tt = -(a * (x1 - x0) + b * (y1 - y0));

    if (tt < 0)
        return sqrt((x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0));
    else if (tt > r2)
        return sqrt((x2 - x0) * (x2 - x0) + (y2 - y0) * (y2 - y0));

    double f1 = a * (y1 - y0) - b * (x1 - x0);
    return sqrt((f1 * f1) / r2);
}
void dfs1(vector<vector<ll>>& z, ll k, ll oya, ll& ans, vector<ll>& b) {
    for (auto m : z[k]) {
        if (m != oya)dfs1(z, m, k, ans, b);
    }
    vector<ll> s;
    for (auto m : z[k]) {
        if (m != oya)s.push_back(b[m]);
    }
    ll m = b.size() - 1;
    for (auto d : s) {
        m -= d;
    }
    b[k] = b.size() - m;
    if (m != 0)s.push_back(m);
    ll a = modinv(2, 1000000007);
    for (auto d : s) {
        a += 1000000007 - modinv(modpow(2, b.size() - d, 1000000007), 1000000007);
    }
    a += modinv(modpow(2, b.size(), 1000000007), 1000000007) * (z[k].size() - 1);
    ans += a;
    ans %= 1000000007;
    return;
}

ll merge_cnt(vector<int>& a) {
    int n = a.size();
    if (n <= 1) { return 0; }

    ll cnt = 0;
    vector<int> b(a.begin(), a.begin() + n / 2);
    vector<int> c(a.begin() + n / 2, a.end());

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

void dfs(vector<vector<ll>>&z,vector<ll>&a,ll now,ll oya,ll &ans,vector<ll> &c,vector<ll> &d) {
    for (int i = 0; i < z[now].size(); i++) {
        dfs(z, a, z[now][i], now, ans,c,d);
    }
    ans += a[now];
    if (a[now] >= 0) {
        a[oya] += a[now];
        c.push_back(now+1);
    }
    else {
        d.push_back(now + 1);
    }
    return;
}

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    vector<vector<ll>> z(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        if (b[i] < 0)continue;
        b[i]--;
        z[b[i]].push_back(i);
    }
    ll ans = 0;
    vector<ll> c;
    vector<ll> d;
    for (int i = 0; i < n; i++) {
        if (b[i] < 0) {
            dfs(z, a, i, i, ans,c,d);
        }
    }
    cout << ans << endl;
    for (int i = 0; i < c.size(); i++) {
        cout << c[i] << " ";
    }
    for (int i = d.size() - 1; i > -1;i--) {
        cout << d[i] << " ";
    }
    cout << endl;
}