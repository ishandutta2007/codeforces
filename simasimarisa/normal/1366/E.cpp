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
    vector<ll> z(n);
    vector<ll> x(m);
    for (int i = 0; i < n; i++) {
        cin >> z[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> x[i];
    }
    reverse(z.begin(), z.end());
    reverse(x.begin(), x.end());
    x.push_back(x[m - 1]);
    ll now = 0;
    ll ans = 1;
    ll zans = 1;
    ll flag = 0;
    for (int i = 0; i < n; i++) {
        
        if (x[now] > z[i]) {
            ans = 0;
            break;
        }
        if (now == m)continue;
        if (now != 0) {
            if (x[now - 1] > z[i] && flag == 1) {
                ans *= zans;
                ans %= 998244353;
                zans = 0;
                flag = 0;
            }
        }
        if (x[now] == z[i]) {
            now++;
            zans = 0;
            flag = 1;
        }
        zans++;
    }
    if (now != m)ans = 0;
    cout << ans << endl;
}