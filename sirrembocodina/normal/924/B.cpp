#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define double long double

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, U;
    cin >> n >> U;
    int E[n];
    bool ok = false;
    double ans = 0;
    int k = 0;
    for(int i = 0; i < n; i++) {
        cin >> E[i];
    }
    for(int i = 0; i + 2 < n; i++) {
        while(k < n && E[k] - E[i] <= U) {
            k++;
        }
        //cout << i << ' ' << k << endl;
        if((k - 1) - i > 1) {
            ok = true;
            ans = max(ans, (double)1 * (E[k - 1] - E[i + 1]) / (E[k - 1] - E[i]));
        }
    }
    if(!ok) {
        cout << -1 << endl;
    } else {
        cout << fixed << setprecision(12) << ans << endl;
    }
    return 0;
}