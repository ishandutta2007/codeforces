#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int mymod(int a, int m) {
    return (a < 0 ? a + m : (a >= m ? a - m : a));
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n), c(n);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;
    sort(all(b));
    int ans = m;
    for (int i = 0; i < n; i++) {
        int x = mymod(b[i] - a[0], m);
        for (int j = 0; j < n; j++) {
            c[j] = mymod(a[j] + x, m);
        }
        sort(all(c));
        if (b == c) ans = min(ans, x);
    }
    assert(ans != m);
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
#ifdef MADE_BY_SERT
    int T = 3;
    for (int i = 1; i < T; i++) solve();    
#endif
}