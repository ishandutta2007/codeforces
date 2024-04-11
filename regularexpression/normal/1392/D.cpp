#include<bits/stdc++.h>
using namespace std;

void upd(int &x, int y) {
    if (y < x) x = y;
}

const int INF = 1e9 + 7;
const int N = 2e5 + 7;

int dp[N][2][3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) arr[i] = s[i] == 'L';
        int ans = INF;
        for (int st = 0; st < 3; ++st) {
            vector<int> a;
            for (int i = st; i < n; ++i) a.push_back(arr[i]);
            for (int i = 0; i < st; ++i) a.push_back(arr[i]);
            for (int fir = 0; fir < 2; ++fir) {
                for (int i = 0; i < n; ++i) {
                    for (int type = 0; type < 2; ++type) {
                        for (int len = 1; len <= 2; ++len) dp[i][type][len] = INF;
                    }
                }
                dp[0][fir][1] = fir != a[0];
                for (int i = 0; i + 1 < n; ++i) {
                    for (int type = 0; type < 2; ++type) {
                        for (int len = 1; len <= 2; ++len) {
                            if (dp[i][type][len] == INF) continue;
                            for (int ntype = 0; ntype < 2; ++ntype) {
                                int nlen = ntype == type ? len + 1 : 1;
                                if (nlen == 3) continue;
                                upd(dp[i + 1][ntype][nlen], dp[i][type][len] + (a[i + 1] != ntype));
                            }
                        }
                    }
                }
                for (int len = 1; len <= 2; ++len) upd(ans, dp[n - 1][!fir][len]);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}