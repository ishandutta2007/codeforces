#include <algorithm>
#include <chrono>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int INF = 1000000009;
const ll INFL = 1e18 + 5LL;
const ld EPS = 1e-11;
const ll MOD = 998244353;

ld absld(ld x, ld y) {
    if (x < y) {
        return y - x;
    }
    return x - y;
}

void solve() {
    int n, l;
    cin >> n >> l;
    vector<int> a(n + 2);
    a[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    a[n + 1] = l;

    ld lsp = 1, rsp = 1;

    vector<ld> tl(n + 2, 0), tr(n + 2, 0);
    vector<ll> lcs(n + 2), rcs(n + 2);
    for (int i = 0; i <= n; ++i) {
        lcs[i] = lsp;
        tl[i + 1] = tl[i] + (a[i + 1] - a[i]) / lsp;
        ++lsp;
        rcs[n - i + 1] = rsp;
        tr[n - i] = tr[n - i + 1] + (a[n - i + 1] - a[n - i]) / rsp;
        ++rsp;
    }

    int il = 0;
    while (tl[il] < tr[il] && tl[il + 1] < tr[il + 1]) {
        ++il;
    }
    lsp = lcs[il];
    rsp = rcs[il + 1];

    cout << setprecision(9);

    if (absld(tl[il], tr[il]) < EPS) {
        cout << tl[il] << "\n";
        return;
    }
    if (absld(tl[il + 1], tr[il + 1]) < EPS) {
        cout << tl[il + 1] << "\n";
        return;
    }

    ld lx = a[il], rx = a[il + 1];
    if (tl[il] < tr[il + 1]) {
        lx += lsp * (tr[il + 1] - tl[il]);
    }
     else if (tr[il + 1] < tl[il]) {
        rx -= rsp * (tl[il] - tr[il + 1]);
    }
    ld ans = max(tl[il], tr[il + 1]);
    ans += (rx - lx) / (lsp + rsp);

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }

    return 0;
}