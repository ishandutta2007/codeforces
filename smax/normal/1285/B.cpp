#include <bits/stdc++.h>
using namespace std;

int a[100000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        bool ok = true;
        long long sum = 0;
        for (int i=0; i<n; i++) {
            cin >> a[i];
            sum += a[i];
            if (sum <= 0)
                ok = false;
        }

        if (!ok)
            cout << "NO\n";
        else {
            ok = true;
            sum = 0;
            for (int i=n-1; i>=0; i--) {
                sum += a[i];
                if (sum <= 0) {
                    ok = false;
                    break;
                }
            }
            cout << (ok ? "YES" : "NO") << "\n";
        }
    }

    return 0;
}