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

class UnionFind {
public:
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

int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> f(n);
    vector<vector<pair<ll,ll>>> r(n);
    vector<bool> bol(m,false);
    for (int i = 0; i < n; i++) {
        cin >> f[i];
    }
    for (int i = 1; i < m+1; i++) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        f[a]--;
        f[b]--;
        r[a].push_back(make_pair(b,i));
        r[b].push_back(make_pair(a, i));
    }
    vector<ll> ans(m, -1);
    queue<ll> q;
    for (int i = 0; i < n; i++) {
        if (f[i] >= 0)q.push(i);
    }
    ll now = 0;
    while (!(q.empty())) {
        ll ima = q.front();
        for (int i = 0; i < r[ima].size(); i++) {
            if (bol[r[ima][i].second-1] == false) {
                bol[r[ima][i].second-1] = true;
                ans[now] = r[ima][i].second;
                now++;
                f[ima]++;
                f[r[ima][i].first]++;
                if (f[r[ima][i].first] == 0)q.push(r[ima][i].first);
            }
        }
        q.pop();
    }
    if (ans[m - 1] == -1)cout << "DEAD" << endl;
    else {
        reverse(ans.begin(), ans.end());
        cout << "ALIVE" << endl;
        for (int i = 0; i < m; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}