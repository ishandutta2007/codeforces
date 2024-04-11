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
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string a;
        cin >> a;
        ll ans = 1341398495;
        queue<char> p;
        p.push(a.at(0));
        int one = 1;
        int two = 1;
        int three = 1;
        if (a.at(0) == '1')one = 0;
        if (a.at(0) == '2')two = 0;
        if (a.at(0) == '3')three = 0;
        for (int j = 1; j < a.size(); j++) {
            while (!p.empty()) {
                if (p.front() == a.at(j)) {
                    p.pop();
                }
                else break;
            }
            if (a.at(j) == '1')one = 0;
            if (a.at(j) == '2')two = 0;
            if (a.at(j) == '3')three = 0;
            if (one + two + three == 0) {
                ll z = p.size();
                char d = p.front();
                p.pop();
                while (!p.empty()) {
                    if (p.front() == d) {
                        p.pop();
                        z--;
                    }
                    else break;
                }
                ans = min(ans, z + 1);
                if (d == '1')one = 1;
                if (d == '2')two = 1;
                if (d == '3')three = 1;
                
            }
            p.push(a.at(j));
            
        }
        if (ans == 1341398495)ans = 0;
        cout << ans << endl;
        
    }
}