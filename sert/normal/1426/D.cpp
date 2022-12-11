#include <bits/stdc++.h>
using namespace std;
bool D = false;
const int INF = (int)1e9 + 34;
typedef long long ll;

void solve() {
    int n, ans = 0;
    cin >> n;
    unordered_set<ll> pref;
    ll sum = 0;
    pref.insert(sum);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        sum += x;
        if (pref.find(sum) != pref.end()) {
            ans++;
            pref.clear();
            sum = x;
            pref.insert(0);
        }
        pref.insert(sum);
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
#ifdef SERT
    freopen("a.in", "r", stdin);
    D = true;
    t = 4;
#else

#endif
    while (t--) {
        solve();
    }
}