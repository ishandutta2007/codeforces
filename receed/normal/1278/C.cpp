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
	int t, n;
    cin >> t;
    rep(z, t) {
        cin >> n;
        vector<int> a(2 * n), b(2 * n + 1, -1);
        int cs = n;
        b[n] = 0;
        rep(i, 2 * n) {
            cin >> a[i];
            a[i] = a[i] * 2 - 3;
            cs += a[i];
            if (i < n)
                b[cs] = i + 1;
        }
        int ans = 2 * n, ts = 0, ns;
        rep(i, n + 1) {
            ns = n - ts;
            if (ns >= 0 && ns <= 2 * n && b[ns] != -1)
                ans = min(ans, 2 * n - i - b[ns]);
            ts += a[n * 2 - 1 - i];
        }
        cout << ans << '\n';
    }
}