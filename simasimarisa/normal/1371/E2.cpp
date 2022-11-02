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

ll ll_gcd(ll a, ll b) {
    if (a < b) return ll_gcd(b, a);
    ll r;
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
        ll p, n;
        cin >> n >> p;
        vector<ll> z(n);
        for (int i = 0; i < n; i++) {
            cin >> z[i];
        }
        sort(z.begin(), z.end());
        ll kijun = z[n - 1];
        for (int i = 0; i < n; i++) {
            z[i] -= z[n - 1] - n + 1;
            if (z[i] < 0)z[i] = 0;
        }
        vector<ll> d(n);
        for (int i = 0; i < n; i++) {
            d[z[i]]++;
        }
        for (int i = 1; i < n; i++) {
            d[i] += d[i - 1];
        }
        
        vector<bool> out(n,true);
        vector<bool> seen(p, false);
        for (int i = 0; i < n; i++) {
            if(i>=p)out[i] = false;
        }
        for (int i = n-1; i > -1; i--) {
            if (seen[(i - d[i] % p + p) % p] == true)continue;
            seen[(i - d[i] % p + p) % p] = true;
            ll k = (i - d[i] % p + p) % p;
            for (int j = 0; j < 123456789; j++) {
                if (j * p + k > i)break;
                out[j * p + k] = false;
            }
        }
        
        vector<ll> ans;
        ll q = 0;
        for (ll i = 0; i < n; i++) {
            q = max(q, i - d[i]);
        }
        for (int i = 0; i < q; i++) {
            out[i] = false;
        }
        
        for (int i = 0; i < n; i++) {
            if (out[i] == true)ans.push_back(kijun - n + 1 + i);
        }
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
}