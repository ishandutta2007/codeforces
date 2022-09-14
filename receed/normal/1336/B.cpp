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

ll sqr(ll x) {
    return x * x;
}

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	ll t;
    cin >> t;
    rep(z, t) {
        vector<ll> n(3);
        rep(i, 3)
            cin >> n[i];
        vector<vector<ll>> a(3);
        rep(i, 3) {
            a[i].resize(n[i]);
            rep(j, n[i])
                cin >> a[i][j];
            sort(all(a[i]));
        }
        ll ans = 3e18;
        vector<int> p(3);
        rep(i, 3)
            p[i] = i;
        do {
            int p1 = 0, p2 = 0;
            rep(i, n[p[0]]) {
                while (p1 + 1 < n[p[1]] && a[p[1]][p1 + 1] <= a[p[0]][i])
                    p1++;
                while (p2 + 1 < n[p[2]] && a[p[2]][p2] < a[p[1]][p1])
                    p2++;
                ans = min(ans, sqr(a[p[0]][i] - a[p[1]][p1]) + sqr(a[p[0]][i] - a[p[2]][p2]) + sqr(a[p[1]][p1] - a[p[2]][p2]));
            }
        } while (next_permutation(all(p)));
        cout << ans << '\n';
    }

}