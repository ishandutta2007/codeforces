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
        int n, k1, k2;
        cin >> n >> k1 >> k2;

        int mx1 = 0, mx2 = 0;
        for (int i=0; i<k1; i++) {
            int a;
            cin >> a;
            mx1 = max(mx1, a);
        }
        for (int i=0; i<k2; i++) {
            int b;
            cin >> b;
            mx2 = max(mx2, b);
        }

        cout << (mx1 > mx2 ? "YES" : "NO") << "\n";
    }

    return 0;
}