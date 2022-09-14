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

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	ll t, n, k;
    cin >> t;
    rep(z, t) {
        cin >> n >> k;
        vector<ll> a(n), ps(n + 1);
        ll f = 0, fl = 0, mn = 1;
        rep(i, n) {
            cin >> a[i];
            if (a[i] == k)
                f = 1;
            a[i] = (a[i] >= k ? 1 : -1);
            ps[i + 1] = ps[i] + a[i];
            if (ps[i + 1] > mn)
                fl = 1;
            mn = min(mn, ps[i]);
        }
        if (f && (fl || n == 1))
            cout << "yes\n";
        else
            cout << "no\n";
    }
}