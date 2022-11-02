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
    ll n, x;
    cin >> n >> x;
    vector<ll> z(n*2);
    for (int i = 0; i < n; i++) {
        cin >> z.at(i);
        z.at(i + n) = z.at(i);
    }
    reverse(z.begin(), z.end());
    ll ans = 0;
    ll zans = 0;
    ll cut = 0;
    ll sm = 0;
    ll start = 0;
    for (int i = 0; i < n; i++) {
        if (sm + z.at(i) >= x) {
            cut = sm + z.at(i) - x;
            ans += z.at(i) * (z.at(i) + 1) / 2;
            ans -= cut * (cut + 1) / 2;
            start = i + 1;
            break;
        }
        else {
            ans += z.at(i) * (z.at(i) + 1) / 2;
            sm += z.at(i);
        }
    }
    zans = ans;
    for (int i = 1; i < 2*n; i++) {
        zans -= z.at(i-1) * (z.at(i-1) + 1) / 2;
        if (cut >= z.at(i - 1)) {
            zans += cut * (cut + 1) / 2;
            cut -= z.at(i - 1);
            zans -= cut * (cut + 1) / 2;
        }
        else {
            zans += cut * (cut + 1) / 2;
            ll u = z.at(i - 1) - cut;
            for (int j = start; j < n*2; j++) {
                if (z.at(j) >= u) {
                    cut = z.at(j)-u;
                    zans += z.at(j) * (z.at(j) + 1) / 2;
                    zans -= cut * (cut + 1) / 2;
                    start = j + 1;
                    break;
                }
                else {
                    zans += z.at(j) * (z.at(j) + 1) / 2;
                    u -= z.at(j);
                }
            }
        }
        ans = max(ans, zans);
        if (start >= n*2)break;
    }
    cout << ans << endl;
}