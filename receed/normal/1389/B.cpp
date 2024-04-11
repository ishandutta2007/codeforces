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
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t, n, k, z;
    cin >> t;
    rep(q, t) {
        cin >> n >> k >> z;
        vector<ll> a(n);
        rep(i, n)
            cin >> a[i];
        ll ans = 0, s, mx;
        rep(i, z + 1) {
            if (i > k - i)
                continue;
            s = mx = 0;
            rep(j, k + 1 - 2 * i) {
                s += a[j];
                if (j > 0)
                    mx = max(mx, a[j] + a[j - 1]);
            }
            ans = max(ans, s + i * mx);
            if (i > 0) {
                mx = max(mx, a[k + 1 - 2 * i] + a[k - 2 * i]);
                ans = max(ans, s + (i - 1) * mx + a[k + 1 - 2 * i] + a[k - 2 * i]);
            }
        }
        cout << ans << '\n';
    }
}