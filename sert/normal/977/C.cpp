#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = (ll)2e5 + 34;
const int INF = (int)1e9 + 34;

void solve() {
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a.begin(), a.end());
    if (k == 0) {
        if (a[0] == 1) cout << -1;
        else cout << a[0] - 1;
        return;
    }
    if (k == n) {
        cout << a.back();
        return;
    }
    if (a[k - 1] == a[k]) {
        cout << -1;
    } else {
        cout << a[k - 1];
    }
}

int main() {
#ifdef FIRE_MIND
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#endif
    //solve();
    solve();
    return 0;
}