#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = (int)1e6 + 34;
//const ll INF = (ll)1e18 + 41;
const int INF = (int)1e9 + 41;
const ll MD = (ll)1e9 + 7;
bool D = false;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int ans = 0;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int len = 0; len <= n; len++) {
        set<int> s;
        bool ok = true; 
        for (int i = 0; i < len; i++) 
            if (s.find(a[i]) != s.end()) ok = false; 
            else s.insert(a[i]);
        if (!ok) continue;

        int p = 0;
        for (int i = n - 1; i >= len; i--) {
            if (s.find(a[i]) == s.end()) {
                p++;
                s.insert(a[i]);
            } else {
                break;
            }
        }
        // cout << len << " " << p << "\n";
        ans = max(ans, len + p);
    }

    cout << n - ans << "\n";
}

int main() {
#ifdef LOCAL
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tst = 1;
    //scanf("%d", &tst);
    // cin >> tst;
#ifdef MADE_BY_SERT
    D = true;  
    tst = 3;  
    while (tst--) {
        solve();
    }
#else
    while (tst--) solve();
#endif
}