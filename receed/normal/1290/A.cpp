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
	int t, n, m, k;
    cin >> t;
    rep(z, t) {
        cin >> n >> m >> k;
        vector<int> a(n);
        rep(i, n)
            cin >> a[i];
        k = min(k, m - 1);
        int ans = 0;
        rep(i, k + 1) {
            int mn = 2e9;
            rep(j, m - k) {
                mn = min(mn, max(a[i + j], a[n - (k - i) - (m - k - j)]));
            }
            ans = max(ans, mn);
        }
        cout << ans << '\n';
    }
}