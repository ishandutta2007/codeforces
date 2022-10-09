#include <bits/stdc++.h>

#define int int64_t

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    int max_n = 1e6 + 1;
    vector<int32_t> divs_size(max_n);
    for (int d = 1; d < max_n; d++) {
        for (int m = d; m < max_n; m += d) {
            divs_size[m]++;
        }
    }
    vector<vector<int32_t>> divs(max_n);
    for (int i = 0; i < max_n; i++) {
        divs[i].resize(divs_size[i]);
        divs_size[i] = 0;
    }
    for (int d = 1; d < max_n; d++) {
        for (int m = d; m < max_n; m += d) {
            divs[m][divs_size[m]++] = d;
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<bool> marked(n + 1);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int x = i + 1;
            if (s[i] == '1') {
                for (int d: divs[x]) {
                    marked[d] = true;
                }
            } else {
                for (int d: divs[x]) {
                    if (!marked[d]) {
                        ans += d;
                        break;
                    }
                }
            }
        }
        cout << ans << '\n';
    }
}