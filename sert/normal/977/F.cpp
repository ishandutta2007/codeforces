#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = (ll)2e5 + 34;
const int INF = (int)1e9 + 34;

int a[N], pr[N], dp[N];
map<int, int> bst;

void solve() {
    int n;
    scanf("%d", &n);
    int mx = 0;
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    for (int i = 0; i < n; i++) {
        int x = a[i] - 1;
        if (bst.find(x) == bst.end()) {
            dp[i] = 1;
            pr[i] = -1;
        } else {
            int ps = bst[x];
            dp[i] = dp[ps] + 1;
            pr[i] = ps;
            if (dp[i] > dp[mx]) mx = i;
        }

        if (bst.find(a[i]) == bst.end() || dp[bst[a[i]]] < dp[i]) bst[a[i]] = i;
    }
    vector<int> ans;
    while (mx != -1) {
        ans.push_back(mx);
        mx = pr[mx];
    }
    cout << ans.size() << "\n";
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < (int)ans.size(); i++) cout << ans[i] + 1 << " ";
}

int main() {
#ifdef FIRE_MIND
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#endif
    //solve();
    solve();
    return 0;
}