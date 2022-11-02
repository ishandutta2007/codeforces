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

void dfs(vector<vector<char>> &f,ll &count,ll a,ll b){
    if (f[a - 1][b] == 'B' || f[a + 1][b] == 'B' || f[a][b - 1] == 'B' || f[a][b + 1] == 'B') {
        f[a][b] = '#';
        return;
    }
    if (f[a][b] == 'G') {
        count--;
    }
    f[a][b] = '#';
    if (f[a - 1][b] != '#') {
        dfs(f,count, a-1, b);
    }
    if (f[a + 1][b] != '#') {
        dfs(f, count, a + 1, b);
    }
    if (f[a][b-1] != '#') {
        dfs(f, count, a, b-1);
    }
    if (f[a][b+1] != '#') {
        dfs(f, count, a, b+1);
    }
}

int main() {
    ll t;
    cin >> t;
    for (int popo = 0; popo < t; popo++) {
        ll n, m;
        cin >> n >> m;
        vector<vector<char>>z(n + 2, vector<char>(m + 2,'#'));
        ll ans = 0;
        for (int i = 1; i < n+1; i++) {
            for (int j = 1; j < m + 1; j++) {
                cin >> z[i][j];
                if (z[i][j] == 'G')ans++;
            }
        }
        dfs(z, ans, n, m);
        if (ans == 0)cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}