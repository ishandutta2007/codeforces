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

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> z(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        z[a].push_back(make_pair(c, b));
    }
    vector<int> s(9);
    for (int i = 0; i < 9; i++) {
        s[i] = i * (i + 1) / 2;
    }
    vector<vector<int>> x(n);
    for (int i = 0; i < n; i++) {
        sort(z[i].begin(), z[i].end());
        for (int j = 0; j < z[i].size(); j++) {
            x[z[i][j].second].push_back(s[z[i].size() - 1] + j);
        }
    }
    vector<vector<bool>> b(45, vector<bool>(45, true));
    for (int i = 0; i < n; i++) {
        if (x[i].size() == 0)continue;
        sort(x[i].begin(), x[i].end());
        for (int j = 0; j < x[i].size() - 1; j++) {
            if (x[i][j] == x[i][j + 1])b[x[i][j]][x[i][j]] = false;

        }
        x[i].erase(unique(x[i].begin(), x[i].end()), x[i].end());
        ll f = x[i].size();
        for (int j = 0; j < f; j++) {
            for (int k = j + 1; k < f; k++) {
                b[x[i][j]][x[i][k]] = false;
            }
        }
    }

    vector<int> d(9);
    ll ans = 0;
    for (d[0] = 0; d[0] < 1; d[0]++) {
        for (d[1] = 1; d[1] < 3; d[1]++) {
            for (d[2] = 3; d[2] < 6; d[2]++) {
                for (d[3] = 6; d[3] < 10; d[3]++) {
                    for (d[4] = 10; d[4] < 15; d[4]++) {
                        for (d[5] = 15; d[5] < 21; d[5]++) {
                            for (d[6] = 21; d[6] < 28; d[6]++) {
                                for (d[7] = 28; d[7] < 36; d[7]++) {
                                    for (d[8] = 36; d[8] < 45; d[8]++) {
                                        int ks = 1;
                                        for (int i = 0; i < 9; i++) {
                                            for (int j = i; j < 9; j++) {
                                                if (!b[d[i]][d[j]])ks = 0;
                                            }
                                        }
                                        ans += ks;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    for (int i = k + 1; i < 10; i++) {
        ans /= i;
    }
    cout << ans << endl;
}