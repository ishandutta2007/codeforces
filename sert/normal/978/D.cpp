//made by Sert
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(int d1, int d2, vector<int> &a) {
    int n = (int)a.size();
    int cur = 0;
    if (d1) cur++;
    if (d2) cur++;
    int st = a[0] + d1;
    int d = (a[1] + d2) - (a[0] + d1);
    for (int i = 2; i < n; i++) {
        int x = st + d * i;
        if (a[i] < x - 1 || a[i] > x + 1) return n + 1;
        if (a[i] != x) cur++;
    }
    return cur;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (n <= 2) {
        cout << "0\n";
        return;
    }
    int ans = n + 1;
    for (int d1 = -1; d1 <= 1; d1++) {
        for (int d2 = -1; d2 <= 1; d2++) {
            int cur = solve(d1, d2, a);
            ans = min(ans, cur);
        }
    }
    cout << (ans > n ? -1 : ans) << "\n";
}

int main() {
#ifdef SERT
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    solve();
    solve();
    solve();
#endif
    solve();
    return 0;
}