#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        vector<ll> a, b;
        for(int i = 0; i < 2 * n; i++) {
            ll x, y;
            cin >> x >> y;
            if(x == 0)
                a.push_back(abs(y));
            else
                b.push_back(abs(x));
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        double ans = 0.0;
        for(int i = 0; i < n; i++)
            ans += hypot(a[i], b[i]);
        cout << fixed << setprecision(9) << ans << '\n';
    }
}