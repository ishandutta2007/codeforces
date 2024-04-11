#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) (a).begin(),(a).end()

template<typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (s[i] != '?') {
            q.push(i);
        }
    }
    if (q.empty()) {
        cout << "YES\n";
        return;
    }
    while (!q.empty()) {
        int pos = q.front();
        q.pop();
        vector<int> dx = {-k, k};
        for (int it = 0; it < 2; it++) {
            int nx = pos + dx[it];
            if (nx >= n || nx < 0) continue;
            if (s[nx] == s[pos]) {
                continue;
            }
            if (s[nx] != '?') {
                cout << "NO\n";
                return;
            }
            q.push(nx);
            s[nx] = s[pos];
        }
    }
    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < k; i++) {
        cnt0 += s[i] == '0';
        cnt1 += s[i] == '1';
    }
    if (max(cnt0, cnt1) * 2 > k) {
        cout << "NO\n";
        return;
    } 
    cout << "YES\n";
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(20), cout.setf(ios::fixed);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}