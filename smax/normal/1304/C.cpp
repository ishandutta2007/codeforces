#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int q;
    cin >> q;
    while (q--) {
        int n, m;
        cin >> n >> m;

        int curTime = 0, lower = m, upper = m;
        bool ok = true;
        for (int i=0; i<n; i++) {
            int t, l, r;
            cin >> t >> l >> r;

            int change = t - curTime;
            lower = max(lower - change, l);
            upper = min(upper + change, r);
            if (lower > upper)
                ok = false;
            curTime = t;
        }

        cout << (ok ? "YES" : "NO") << "\n";
    }

    return 0;
}