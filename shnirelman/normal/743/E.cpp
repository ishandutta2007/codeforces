//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
#define x first
#define y second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
//using matr

const li INF = 1e18 + 13;
const int N = 2e5 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;
const ld e = 1e-8;
const int LOGN = 20;
const int K = 8;

mt19937 rnd(0);

int dp[1 << K][K + 1];

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<vector<int>> b(8);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;

        b[a[i]].push_back(i);
    }

    int ans = 1;
    for(int x = 0; x <= n / 8; x++) {
//        cout << x << endl;

        for(int mask = 0; mask < (1 << K); mask++)
            for(int i = 0; i <= K; i++)
                dp[mask][i] = n;

//        cout << "sgd" << endl;

        dp[0][0] = -1;
        for(int mask = 0; mask < (1 << K); mask++) {
//            cout << mask << endl;
            for(int i = 0; i < K; i++)
                if(((mask >> i) & 1) == 0) {
                    int nmask = (1 << i) | mask;

                    for(int d = 0; d < K; d++) {
//                        cout << "d " << d << endl;
                        int cur = upper_bound(b[i].begin(), b[i].end(), dp[mask][d]) - b[i].begin();
//                        cout << "cur " << cur << endl;

                        if(cur + x <= b[i].size()) {
                            dp[nmask][d] = min(dp[nmask][d], (x > 0 ? b[i][cur + x - 1] : dp[mask][d]));
                        }

                        if(cur + x + 1 <= b[i].size()) {
                            dp[nmask][d + 1] = min(dp[nmask][d + 1], b[i][cur + x]);
                        }
                    }
                }
        }
//        cout << "end " << endl;


        for(int i = 0; i <= K; i++)
            if(dp[(1 << K) - 1][i] < n)
                ans = max(ans, x * 8 + i);
//        cout << "End " << endl;
    }

    cout << ans << endl;
}