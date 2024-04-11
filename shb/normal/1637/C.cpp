#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<int>a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        if (n == 3) {
            if (a[1] % 2 != 0) {
                cout << "-1\n";
            } else {
                cout << a[1] / 2 << '\n';
            }
        } else {
            LL ans = 0;
            bool have = false;
            for (int i = 1; i < n - 1; i++) {
                if (a[i] >= 2) have = true;
                ans += (a[i] + 1) / 2;
                //cout << "+=" << (a[i]+1)/2;
            }
            if (!have) {
                cout << "-1\n";
            } else {
                cout << ans << '\n';
            }
        }
    }
}