#include <bits/stdc++.h>
using namespace std;

int dp[1001][51][51], lpsS[50], lpsT[50], nxtS[51][26], nxtT[51][26];

void preprocess(string p, int m, int *lps, int nxt[][26]) {
    lps[0] = 0;
    int j = 0;
    for (int i=1; i<m; i++) {
        while (j != 0 && p[i] != p[j])
            j = lps[j-1];
        lps[i] = (j += (p[i] == p[j]));
    }

    for (int i=0; i<=m; i++)
        for (char c='a'; c<='z'; c++) {
            j = (i == m ? lps[m-1] : i);
            while (j != 0 && p[j] != c)
                j = lps[j-1];
            nxt[i][c-'a'] = (j += (p[j] == c));
        }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    string code, s, t;
    cin >> code >> s >> t;

    int n = code.length(), sl = s.length(), tl = t.length();
    memset(dp, 128, sizeof(dp));
    preprocess(s, sl, lpsS, nxtS);
    preprocess(t, tl, lpsT, nxtT);

    dp[0][0][0] = 0;
    for (int i=0; i<n; i++)
        for (int ks=0; ks<=sl; ks++)
            for (int kt=0; kt<=tl; kt++)
                for (char c='a'; c<='z'; c++)
                    if (code[i] == '*' || code[i] == c) {
                        int ns = nxtS[ks][c-'a'], nt = nxtT[kt][c-'a'];
                        dp[i+1][ns][nt] = max(dp[i+1][ns][nt], dp[i][ks][kt] + (ns == sl) - (nt == tl));
                    }

    int ret = INT_MIN;
    for (int ks=0; ks<=sl; ks++)
        for (int kt=0; kt<=tl; kt++)
            ret = max(ret, dp[n][ks][kt]);

    cout << ret << "\n";

    return 0;
}