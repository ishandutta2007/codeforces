#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int ans = 1e9;
        for (int add = 0; add <= 100; add++) {
            int bb = b + add;
            if (bb != 1) {
                int need = add;
                int aa = a;
                while (aa != 0) {
                    need++;
                    aa /= bb;
                }
                ans = min(ans, need);
            }
        }
        cout << ans << "\n";
    }

    return 0;
}