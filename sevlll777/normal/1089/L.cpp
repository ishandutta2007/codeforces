#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define ld long double
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<vector<int>> ind(k + 1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ind[x].pb(i);
    }
    vector<int> B(n);
    for (int i = 0; i < n; i++) cin >> B[i];
    vector<int> lal;
    int ans = 0, cnt = 0;
    for (int x = 1; x <= k; x++) {
        vector<int> C;
        for (auto i : ind[x]) {
            C.pb(B[i]);
        }
        sort(C.begin(), C.end());
        if (!C.empty()) {
            C.pop_back();
        } else {
            cnt++;
        }
        for (auto el : C) lal.pb(el);
    }
    sort(lal.begin(), lal.end());
    for (int i = 0; i < cnt; i++) ans += lal[i];
    cout << ans << '\n';
}