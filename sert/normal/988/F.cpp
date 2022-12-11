//made by Sert
#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9 + 34;
const int N = (int)1e6 + 34;

typedef long long ll;

int go(string s, char a, char b) {
    int n = s.length();
    if (a == '0' && b == '0') {
        vector<int> ps;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') ps.push_back(i);
        }
        if ((int)ps.size() < 2) return INF;
        return (n - 1) - ps[0] + (n - 2) - ps[1];
    }

    int pa = -1;
    int pb = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == a && pa == -1) pa = i;
        if (s[i] == b && pb == -1) pb = i;
    }
    if (pa == -1 || pb == -1) return INF;

    int ans = 0;
    if (pb < pa) {
        swap(pa, pb);
        ans++;
    }
    ans += (n - 1) - pb + (n - 2) - pa;
    int num = 0;
    int ok = false;
    for (int i = 0; i < n; i++) {
        if (i == pa || i == pb) continue;
        if (s[i] == '0' && !ok) num++;
        else ok = true;
    }
    if (!ok && num > 0) return INF;
    ans += num;
    return ans;
}

void solve() {
    int a, n, m;
    cin >> a >> n >> m;
    vector<int> dp(m);
    vector<int> x(m), p(m);
    for (int i = 0; i < m; i++) dp[i] = INF;

    vector<int> l(n), r(n);
    int st = INF;
    int fn = 0;
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
        st = min(st, l[i]);
        fn = max(fn, r[i]);
    }

    int mx = -1;

    for (int i = 0; i < m; i++) {
        cin >> x[i] >> p[i];
        mx = max(mx, x[i]);
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m - i - 1; j++) {
            if (x[j] > x[j + 1]) {
                swap(x[j], x[j + 1]);
                swap(p[j], p[j + 1]);
            }
        }
    }

    for (int i = m - 1; i >= 0; i--) {
        int ind = -1;
        for (int j = 0; j < n; j++) {
            if (l[j] >= x[i]) continue;
            if (ind == -1) ind = j;
            if (l[j] > l[ind]) ind = j;
        }

        int cur = (fn > x[i] ? (fn - x[i]) * p[i] : 0);
        dp[i] = min(dp[i], cur);


        for (int j = 0; j < i; j++) {
            int cur;
            if (r[ind] > x[j]) {
                cur = (min(r[ind], x[i]) - x[j]) * p[j];
            } else {
                cur = 0;
            }
            dp[j] = min(dp[j], dp[i] + cur);
        }
    }

    int ans = INF;
    for (int i = 0; i < m; i++) {
        if (x[i] <= st && dp[i] < ans) ans = dp[i];
    }
    cout << (ans == INF ? -1 : ans) << "\n";
}

int main() {
#ifdef SERT
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    solve();
    solve();
    //solve();
    //solve();
#endif
    solve();
    return 0;
}