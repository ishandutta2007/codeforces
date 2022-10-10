#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        long long x;
        cin >> x;

        bool ok = false;
        for (int i=1; i<=6; i++)
            if ((x - (21 - i)) >= 0 && (x - (21 - i)) % 14 == 0) {
                ok = true;
                break;
            }

        cout << (ok ? "YES" : "NO") << "\n";
    }

    return 0;
}