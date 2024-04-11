#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) (a).begin(),(a).end()

template<typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

const int N = 3e5 + 10;
int n;
int a[N];
vector<int> pos[N];
int ans[N];

void solve(int l, int r, int val) {
    if (pos[val].empty()) return;
    ans[n - val] = 1;
    if (pos[val].size() != 1) return;
    int myPos = pos[val][0];
    if (myPos == l) {
        solve(l + 1, r, val + 1);
    } else if (myPos == r) {
        solve(l, r - 1, val + 1);
    }
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n + 5; ++i) {
        pos[i].clear();
    }
    for (int i = 0; i < n; ++i) {
        pos[a[i]].push_back(i);
    }
    fill(ans, ans + n, 0);
    solve(0, n - 1, 1);

    sort(a, a + n);
    int sz = unique(a, a + n) - a;
    if (sz == n && a[0] == 1 && a[n - 1] == n) {
        ans[0] = 1;
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i];
    }
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(20), cout.setf(ios::fixed);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}