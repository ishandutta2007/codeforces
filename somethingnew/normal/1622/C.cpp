#include <iostream>
#include "cmath"
#include "string"
#include "vector"
#include "set"
#include "algorithm"
#include "map"
#include "queue"
#include "numeric"
#define int long long
#define all(x) (x).begin(), (x).end()
using namespace std;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int sm = 0, mn = 1e9;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sm += a[i];
        mn = min(a[i], mn);
    }
    sort(all(a));
    reverse(all(a));
    vector<int> prefsum = a;
    for (int i = 1; i < n; ++i) {
        prefsum[i] += prefsum[i-1];
    }
    k = sm - k;
    if (k <= 0) {
        cout << "0\n";
        return;
    }
    int res = k;
    for (int ttt = 1; ttt < n; ++ttt) {
        res = min(res, ttt + max(0ll, ((k - (prefsum[ttt-1] - a.back() * ttt)) + ttt) / (ttt + 1)));
    }
    cout << res << '\n';

}

signed main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    while (n--) solve();
}
//abacdcababb