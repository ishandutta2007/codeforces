#include <bits/stdc++.h>

#define f first
#define s second
//#define x first
//#define y second
//#define int li
#define err if(debug_out)cout

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using pld = pair<ld, ld>;

const int INF = 2e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 20;
const int LOGN = 20;
const int K = 22;
const int M = 1e9 + 7;
//const int M = 998244353;
const int A = 26;
const ld eps = 1e-8;

mt19937 rnd(45768);

/*
*/

void NO() {
    cout << "NO" << endl;
    exit(0);
}

int val[A];
int dp[N * 2][1 << N];
int mask[N * 2][A];

bool b[N][N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<string> s(n);
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }

    vector<vector<int>> a(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            a[i][j] = (s[i][j] == 'a' ? 1 : (s[i][j] == 'b' ? -1 : 0));
        }
    }

    val[0] = 1;
    val[1] = -1;

    for(int diag = 1; diag < n * 2; diag++) {
        int cur = 0;
        for(int i = 0; i < n; i++) {
            int j = diag - i - 1;
            if(0 <= j && j < n) {
                mask[diag][s[i][j] - 'a'] |= (1 << cur);
                cur++;
            }
        }

//        for(int x = 0; x < A; x++) if(mask[diag][x]) {
//            cout << "diag " << diag << " x " << x << " mask " << mask[diag][x] << endl;
//        }
    }

    dp[2 * n - 1][1] = a[n - 1][n - 1];

    for(int diag = 2 * n - 2; diag >= 1; diag--) {
        int sz = (diag < n ? diag : 2 * n - diag);
        for(int x = 0; x < A; x++) {
            for(int msk = mask[diag][x]; msk > 0; msk = (msk - 1) & mask[diag][x]) {
                dp[diag][msk] = (diag % 2 == 0 ? -INF : INF);

                int cur = 0;
                for(int i = 0; i < n; i++) {
                    int j = diag - i - 1;
                    if(0 <= j && j < n) {
                        if(msk & (1 << cur))
                            b[i][j] = true;
                        cur++;
                    }

                }

//                cout << "msk " << msk << endl;
//                for(int i = 0; i < n; i++) {
//                    for(int j = 0; j < n; j++) {
//                        cout << b[i][j];
//                    }
//                    cout << endl;
//                }

                int nmask = 0;
                cur = 0;
                for(int i = 0; i < n; i++) {
                    int j = diag - i;
                    if(0 <= j && j < n) {
//                        if(st.count(pii(i - 1, j)) || st.count(pii(i, j - 1))) {
                        if(i > 0 && b[i - 1][j] || j > 0 && b[i][j - 1]) {
                            nmask |= (1 << cur);
                        }
                        cur++;
                    }

                }

                for(int i = 0; i < n; i++) {
                    int j = diag - i - 1;
                    if(0 <= j && j < n)
                        b[i][j] = false;
                }

                for(int y = 0; y < A; y++) {
                    int next = (nmask & mask[diag + 1][y]);
                    if(next == 0)
                        continue;
//                    cout << "next " << next << endl;
                    if(diag % 2 == 0) {
                        dp[diag][msk] = max(dp[diag][msk], dp[diag + 1][next] + val[x]);
                    } else {
                        dp[diag][msk] = min(dp[diag][msk], dp[diag + 1][next] + val[x]);
                    }
                }
//                cout << "dp " << diag << ' ' << x << ' ' << msk << ' ' << dp[diag][msk] << " nmask " << nmask << endl;
            }
        }
    }

//    dp[0][0] += a[0][0];

    cout << (dp[1][1] > 0 ? "FIRST" : (dp[1][1] < 0 ? "SECOND" : "DRAW")) << endl;
}