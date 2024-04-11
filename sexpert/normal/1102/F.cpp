    #include <bits/stdc++.h>
    using namespace std;
     
    const int MAXM = 1e4 + 5;
    int dp[(1 << 16)][16][16];
    int mat[16][MAXM];
    int cst[16][16], trans[16][16];
     
    int main() {
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        if(n == 1) {
            int ans = 2e9;
            for(int i = 1; i < m; i++)
                ans = min(ans, abs(mat[0][i] - mat[0][i - 1]));
            cout << ans << endl;
            return 0;
        }
        for(int s = 0; s < n; s++) {
            for(int e = 0; e < n; e++) {
                cst[s][e] = 2e9;
                trans[s][e] = 2e9;
                for(int i = 0; i < m; i++) {
                    cst[s][e] = min(cst[s][e], abs(mat[s][i] - mat[e][i]));
                    if(i < m - 1)
                        trans[s][e] = min(trans[s][e], abs(mat[s][i] - mat[e][i + 1]));
                }
            }
        }
        for(int msk = 1; msk < (1 << n); msk++) {
            for(int s = 0; s < n; s++) {
                for(int e = 0; e < n; e++) {
                    if(__builtin_popcount(msk) == 1)
                        continue;
                    if(s == e)
                        continue;
                    if(msk & (1 << s) == 0 || msk & (1 << e) == 0)
                        continue;
                    if(__builtin_popcount(msk) == 2) {
                        dp[msk][s][e] = cst[s][e];
                        continue;
                    }
                    int nms = msk ^ (1 << s);
                    for(int b = 0; b < n; b++) {
                        if(b == e)
                            continue;
                        if(nms & (1 << b))
                            dp[msk][s][e] = max(dp[msk][s][e], min(cst[s][b], dp[nms][b][e]));
                    }
                }
            }
        }
        int ans = 0;
        for(int s = 0; s < n; s++) {
            for(int e = 0; e < n; e++) {
                if(s == e)
                    continue;
                ans = max(ans, min(dp[(1 << n) - 1][s][e], trans[e][s]));
            }
        }
        cout << ans << endl;
    }