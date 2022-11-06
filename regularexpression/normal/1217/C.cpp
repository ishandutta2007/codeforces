#include<bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = s[i] - '0';
    }
    int maxlen = 25;
    vector<int> p(n);
    p[0] = (a[0] == 0 ? 1 : 0);
    for (int i = 1; i < n; i++) {
        p[i] = (a[i] == 0 ? p[i - 1] + 1 : 0);
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            continue;
        }
        int num = 0;
        for (int j = i; j < i + min(maxlen, n - i); j++) {
            num = num * 2LL + a[j];
            if (num == j - i + 1) {
                cnt++;
            } else {
                if (num > j - i + 1) {
                    if (i > 0 && p[i - 1] >= num - j + i - 1) {
                        cnt++;
                    }
                }
            }
        }
    }
    cout << cnt << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}