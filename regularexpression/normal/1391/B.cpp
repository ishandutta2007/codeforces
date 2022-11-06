#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                char c;
                cin >> c;
                if (i == n - 1 && c == 'D')
                    ++ans;
                if (j == m - 1 && c == 'R')
                    ++ans;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}