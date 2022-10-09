#include <bits/stdc++.h>

using namespace std;
#define int int64_t

int32_t main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    vector<int> left(m + 1);
    left[0] = 0;
    for (int i = 0; i < m; i++) {
        for (int j = left[i]; j < s.size(); j++) {
            if (s[j] == t[i]) {
                left[i + 1] = j + 1;
                break;
            }
        }
    }
    vector<int> right(m + 1);
    right[m] = n;
    for (int i = m - 1; i >= 0; i--) {
        for (int j = right[i + 1] - 1; j >= 0; j--) {
            if (s[j] == t[i]) {
                right[i] = j;
                break;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i + 1 < m; i++) {
        ans = max(ans, right[i + 1] - left[i + 1] + 1);
    }
    cout << ans << endl;
}