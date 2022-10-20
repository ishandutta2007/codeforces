#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

const int M = 1000000007;


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int T;
    T = 1;
    // cin >> T;
    for (int _ = 0; _ < T; ++_) {
        int n, q;
        string s;
        cin >> n >> q >> s;
        int ans = 0;
        for (int i = 0; i + 2 < n; ++i) {
            if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c') {
                ++ans;
            }
        }
        for (int i = 0; i < q; ++i) {
            int j;
            char c;
            cin >> j >> c;
            --j;

            for (int k = max(-2, -j); k <= 2 && j + k + 2 < n; ++k) {
                if (s[j + k] == 'a' && s[j + k + 1] == 'b' && s[j + k + 2] == 'c') {
                    --ans;
                }
            }

            s[j] = c;

            for (int k = max(-2, -j); k <= 2 && j + k + 2 < n; ++k) {
                if (s[j + k] == 'a' && s[j + k + 1] == 'b' && s[j + k + 2] == 'c') {
                    ++ans;
                }
            }
            cout << ans << '\n';
        }

    }
    return 0;
}