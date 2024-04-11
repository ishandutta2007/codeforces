
#include <bits/stdc++.h>
using namespace std;

#define N 222

const int mod = 1e9 + 7;

int n, ssz;
string s;
int len[N][2];
int dp[N][N][N][2];

int calc(const string &t) {
    int tsz = t.size();
    for (int i = tsz; i > 0; i --) {
        if (s.substr(0, i) == t.substr(tsz - i, i)) return i;
    }
    return 0;
}

void add(int &a, int b) {
    a += b;
    if (a >= mod) a -= mod;
    if (a < 0) a += mod;
}

int main() {
    cin >> n >> s;
    ssz = s.size();
    if (s[0] == '(')
        len[0][0] = 1;
    else
        len[0][1] = 1;
    string pref;
    for (int i = 0; i < ssz; i ++) {
        pref += s[i];
        pref += '(';
        len[i + 1][0] = calc(pref);
        pref.pop_back();
        pref += ')';
        len[i + 1][1] = calc(pref);
        pref.pop_back();
    }
    dp[0][0][0][0] = 1;
    for (int i = 0; i < 2 * n; i ++) {
        for (int j = 0; j <= n; j ++) {
            for (int pos = 0; pos <= ssz; pos ++) {
                for (int f = 0; f < 2; f ++) {
                    if (dp[i][j][pos][f] == 0) continue;
                    if (j + 1 <= n) add(dp[i + 1][j + 1][len[pos][0]][f | (len[pos][0] == ssz)], dp[i][j][pos][f]);
                    if (j > 0) add(dp[i + 1][j - 1][len[pos][1]][f | (len[pos][1] == ssz)], dp[i][j][pos][f]);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= ssz; i ++) add(ans, dp[2 * n][0][i][1]);
    cout << ans << endl;
    return 0;
}