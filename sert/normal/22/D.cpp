#include <bits/stdc++.h>
using namespace std;

const int N = 20003;
int a[N], b[N];

void solve() {
    int n;
    cin >> n;
    set<int> coords;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        coords.insert(a[i]);
        coords.insert(b[i]);
        if (a[i] > b[i]) swap(a[i], b[i]);
    }
    vector<int> c;
    for (int x : coords) c.push_back(x);

    vector<int> dp(c.size() + 1, 0);
    vector<int> pr(c.size() + 1, -1);

    for (int i = 0; i < (int)c.size(); i++) {
        int mn = -N;
        for (int j = 0; j < n; j++)
            if (b[j] < c[i]) mn = max(mn, a[j]);

        if (mn == -N) {
            dp[i + 1] = 1;
            continue;
        }
        dp[i + 1] = N;
        for (int j = i - 1; j >= 0 && c[j] >= mn; j--) {
            if (dp[j + 1] + 1 < dp[i + 1]) {
                dp[i + 1] = dp[j + 1] + 1;
                pr[i + 1] = j + 1;
            }
        }

        // cout << i << " " << c[i] << " " << dp[i + 1] << " " << pr[i + 1] << " " << mn << endl;
    }

    int mnVal = *max_element(a, a + n);
    int ansInd = -1, ans = N;
    for (int i = (int)c.size() - 1; i >= 0 && c[i] >= mnVal; i--) {
        if (dp[i + 1] < ans) {
            ans = dp[i + 1];
            ansInd = i + 1;
        }
    }

    vector<int> path;
    while (ansInd > 0) {
        path.push_back(c[ansInd - 1]);
        ansInd = pr[ansInd];
    }

    reverse(path.begin(), path.end());
    cout << path.size() << endl;
    for (int x : path) cout << x << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
#ifdef SERT
    int t = 3;
    for (int i = 1; i < t; i++) {
        solve();
    }
#endif
}