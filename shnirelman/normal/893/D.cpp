#include <bits/stdc++.h>

using namespace std;
using li = long long;
using ld = long double;

int main() {
    int n, d;
    cin >> n >> d;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> s(n + 1, 0);
    for(int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i - 1];

    vector<int> mx(n + 1, s[n]);
    for(int i = n - 1; i >= 0; i--) {
        mx[i] = max(mx[i + 1], s[i]);
//        cout << s[i] << ' ' << mx[i] << endl;
    }


    int cur = 0, ans = 0;
    for(int i = 0; i < n; i++) {
//        cout << i << ' '  << cur << endl;
        if(cur < 0 && a[i] == 0) {
            int x = mx[i] - s[i];
            int y = d - cur - x;
//            cout << x << ' ' << y << ' ' << mx[i] << ' ' << s[i] << endl;
            cur += y;
            ans++;
            if(cur + a[i] < 0) {
                cout << -1 << endl;
                return 0;
            }
        }

        cur += a[i];
//        cout << cur << endl;
        if(cur > d) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << ans << endl;
}