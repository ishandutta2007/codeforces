#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    string rr[] = {"RGB", "GBR", "BRG"};

    int q;
    cin >> q;
    while (q--) {
        int n, k;
        string s;
        cin >> n >> k >> s;

        vector<int> dp(3);
        for (int i=0; i<k; i++) {
            for (int j=0; j<3; j++) {
                dp[j] += (s[i] != rr[j][i%3]);
//                cerr << s[i] << ", " << rr[j][i%3] << ", " << j << "\n";
            }
        }
//        for (int i=0; i<3; i++)
//            cout << dp[i] << " ";
//        cout << "\n";
        int ret = min({dp[0], dp[1], dp[2]});

        for (int i=k; i<n; i++) {
            for (int j=0; j<3; j++) {
                dp[j] -= (s[i-k] != rr[j][(i-k)%3]);
                dp[j] += (s[i] != rr[j][i%3]);
                ret = min(ret, dp[j]);
            }

        }

        cout << ret << "\n";
    }

    return 0;
}