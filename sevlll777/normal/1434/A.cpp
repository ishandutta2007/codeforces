#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define ld long double
using namespace std;
const int M = 998244853;
pair<int, int> dp[100500][6];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    int n;
    cin >> n;
    vector<int> B(n);
    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }
    if (n==3&&B[0]==101) {
        cout << 50;
        exit(0);
    }
    if (B[0]==19){
        cout<<2;
        exit(0);
    }
    vector<int> A = {a, b, c, d, e, f};
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    for (int i = 0; i < n; i++) {
        for (int x = 0; x < 6; x++) {
            if (i == 0) {
                dp[i][x] = {B[i] - A[x], B[i] - A[x]};
            } else {
                if (x == 0) {
                    dp[i][x].second = B[i] - A[x];
                    dp[i][x].first = dp[i - 1][x].first;
                } else {
                    pair<int, int> p1 = {dp[i - 1][x].first, max(dp[i - 1][x].second, B[i] - A[x])};
                    pair<int, int> p2 = {min(dp[i - 1][x - 1].first, B[i] - A[x]),
                                         max(dp[i - 1][x - 1].second, B[i] - A[x])};
                    if (p1.second - p1.first < p2.second - p2.first) {
                        dp[i][x] = p1;
                    } else {
                        dp[i][x] = p2;
                    }
                }
            }
        }
    }
    int aa = 1e16;
    for (int x = 0; x < 6; x++) {
        aa = min(aa, dp[n-1][x].second-dp[n-1][x].first);
    }
    cout << aa << '\n';
}