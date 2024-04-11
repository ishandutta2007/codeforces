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

ll d2(ll x) {
    if (x >= 0)
        return x / 2;
    return -((-x + 1) / 2);
}
ll c2(ll x) {
    if (x >= 0)
        return (x + 1) / 2;
    return -((-x) / 2);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, t, m = 50;
    string s;
    cin >> n >> t >> s;
    vector<ll> a(n);
    rep(i, n)
        a[i] = s[i] - 'a';
    t += (1ll << a[n - 2]) - (1ll << a[n - 1]);
    vector<ll> c(m);
    rep(i, n - 2)
        c[a[i]]++;
    t = abs(t);
    ll l = t, r = t;
    rep(i, m - 1) {
        ll x = max(0ll, c[i] - 2) / 2;
        c[i] -= x * 2;
        c[i + 1] += x;
        if (abs(l % 2) != c[i] % 2)
            l++;
        if (abs(r % 2) != c[i] % 2)
            r--;
        if (r < l) {
            cout << "No";
            return 0;
        }
        r = d2(r + c[i]);
        l = c2(l - c[i]);
    }
    cout << "Yes";
}