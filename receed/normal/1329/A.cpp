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
#include <ext/pb_ds/assoc_container.hpp>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	ll n, m, l, p;
    cin >> n >> m;
    vector<ll> a(m), b(m);
    rep(i, m) {
        cin >> a[i];
        if (a[i] + i > n) {
            cout << -1;
            return 0;
        }
    }
    p = n;
    for (ll i = m - 1; i >= 0; i--) {
        p = max(p - a[i], i);
        b[i] = p;
    }
    if (p > 0) {
        cout << -1;
        return 0;
    }
    rep(i, m)
        cout << b[i] + 1 << ' ';
}