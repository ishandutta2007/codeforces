#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;
const int INF = 1e9;
string r[3], s;
int nxt[MAXN][26], dp[255][255][255];
bitset<MAXN> used;

void upd(int i, int j, int k) {
    if(i + j + k == 0)
        return;
    if(i > 0 && i <= r[0].length() && dp[i - 1][j][k] < INF)
        dp[i][j][k] = min(dp[i][j][k], nxt[dp[i - 1][j][k]][r[0][i - 1] - 'a']);
    if(j > 0 && j <= r[1].length() && dp[i][j - 1][k] < INF)
        dp[i][j][k] = min(dp[i][j][k], nxt[dp[i][j - 1][k]][r[1][j - 1] - 'a']);
    if(k > 0 && k <= r[2].length() && dp[i][j][k - 1] < INF)
        dp[i][j][k] = min(dp[i][j][k], nxt[dp[i][j][k - 1]][r[2][k - 1] - 'a']);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q >> s;
    for(int c = 0; c < 26; c++) {
        int curpos = INF;
        for(int i = n; i >= 0; i--) {
            nxt[i][c] = curpos;
            if(i > 0 && s[i - 1] == 'a' + c) curpos = i;
        }
    }
    for(int i = 0; i < 255; i++) {
        for(int j = 0; j < 255; j++) {
            for(int k = 0; k < 255; k++) {
                dp[i][j][k] = INF;
            }
        }
    }
    dp[0][0][0] = 0;
    /*for(int i = 0; i < n; i++) {
        for(int c = 0; c < 4; c++)
            cout << nxt[i][c] << " ";
        cout << endl;
    }*/
    while(q--) {
        char c;
        int p;
        cin >> c >> p;
        p--;
        if(c == '-') {
            int l = r[p].length();
            if(p == 0) {
                for(int i = 0; i < 255; i++)
                    for(int j = 0; j < 255; j++)
                        dp[l][i][j] = INF;
            }
            if(p == 1) {
                for(int i = 0; i < 255; i++)
                    for(int j = 0; j < 255; j++)
                        dp[i][l][j] = INF;
            }
            if(p == 2) {
                for(int i = 0; i < 255; i++)
                    for(int j = 0; j < 255; j++)
                        dp[i][j][l] = INF;
            }
            r[p] = r[p].substr(0, l - 1);
        }
        else {
            char e;
            cin >> e;
            r[p] += e;
            int l = r[p].length();
            if(p == 0) {
                for(int i = 0; i < 255; i++) { 
                    for(int j = 0; j < 255; j++) {
                        upd(l, i, j);
                    }
                }
            }
            if(p == 1) {
                for(int i = 0; i < 255; i++) { 
                    for(int j = 0; j < 255; j++) {
                        upd(i, l, j);
                    }
                }
            }
            if(p == 2) {
                for(int i = 0; i < 255; i++) { 
                    for(int j = 0; j < 255; j++) {
                        upd(i, j, l);
                    }
                }
            }
        }
        //cout << r[0].length() << " " << r[1].length() << " " << r[2].length() << " " << dp[r[0].length()][r[1].length()][r[2].length()] << endl;
        if(dp[r[0].length()][r[1].length()][r[2].length()] < INF)
            cout << "YES\n";
        else
            cout << "NO\n";
        //cout << r[0] << " " << r[1] << " " << r[2] << endl;
    }
}