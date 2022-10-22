#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    int s, q, e;
    int ans;
    int e0;
    for (int qq = 0; qq < t; qq++) {
        cin >> s >> q >> e;
        if (s > q) {
            e0 = e;
            e = e - (s - q);
            q = s + 1;
            if (e > 0 && e % 2 == 1) {
                q++;
                e--;
            }
            if (e < 0) {
                cout << e0 + 1 << '\n';
                continue;
            }
            ans = 1;
            ans += e / 2;
            ans = e0 + 1 - ans;
            cout << ans << '\n';
            continue;
        }
        if (s <= q) {
            e = e - (q + 1 - s);
            s = q + 1;
        }
        if (e > 0 && e % 2 == 1) {
            s++;
            e--;
        }
        if (e < 0) {
            cout << "0" << '\n';
            continue;
        }
        ans = 1;
        ans += e / 2;
        cout << ans << '\n';
    }
    return 0;
}