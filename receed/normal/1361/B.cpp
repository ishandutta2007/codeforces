#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

const int MOD = 1e9 + 7;

ll pw(ll x, ll k) {
    ll r = 1;
    while (k) {
        if (k & 1)
            r = r * x % MOD;
        x = x * x % MOD;
        k >>= 1;
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
	ll t, n, p;
    cin >> t;
    rep(z, t) {
        cin >> n >> p;
        vector<ll> a(n);
        rep(i, n)
            cin >> a[i];
        if (p == 1) {
            cout << n % 2 << '\n';
            continue;
        }
        sort(rall(a));
        ll cr = 0, cp = 0, md = 0;
        for (ll i : a) {
            if (md) {
                cr = cr * pw(p, cp - i) % MOD;
                cr = (cr + MOD - 1) % MOD;
                cp = i;
            }
            else if (cr == 0) {
                cr = 1;
                cp = i;
            }
            else {
                while (cp > i && cr < MOD) {
                    cp--;
                    cr = cr * p;
                }
                if (cp > i || cr >= MOD) {
                    cr = cr % MOD * pw(p, cp - i) % MOD;
                    cp = i;
                    md = 1;
                }
                cr = (cr + MOD - 1) % MOD;
            }
        }
        cout << cr * pw(p, cp) % MOD << '\n';
    }
}