#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7, MAX = 205;
int nxt[MAX][2], n;
int dp[MAX][MAX][MAX][2];
string s;

vector<int> kmp(string s) {
    int m = s.size();
    vector<int> pi(m);
    for(int i = 1, j = 0; i < m; i++) {
        while(j && s[i] != s[j])
            j = pi[j - 1];
        pi[i] = j += s[i] == s[j];
    }
    return pi;
}

void init() {
    int m = s.size();
    vector<int> v = kmp(s);
    for(int i = 0; i <= m; i++) {
        for(int b = 0; b < 2; b++) {
            if(i == m || b != s[i] - '0')
                nxt[i][b] = (i ? nxt[v[i - 1]][b] : 0);
            else
                nxt[i][b] = i + 1;
        }
        //cout << i << " --0-> " << nxt[i][0] << '\n';
        //cout << i << " --1-> " << nxt[i][1] << '\n';
    }
}

void add(int &a, int b) {
    a += b;
    if(a >= MOD)
        a -= MOD;
}

int main() {
    cin >> n >> s;
    for(auto &c : s) {
        if(c == '(')
            c = '0';
        else
            c = '1';
    }
    init();

    // position, kmp state, balance, have seen string
    dp[0][0][0][0] = 1;
    for(int pos = 0; pos < 2*n; pos++) {
        for(int st = 0; st <= s.size(); st++) {
            for(int ba = 0; ba < 2*n; ba++) {
                for(int seen = 0; seen < 2; seen++) {
                    if(dp[pos][st][ba][seen] == 0)
                        continue;
                    int nst = nxt[st][0], nseen = (seen | (nst == s.size()));
                    add(dp[pos + 1][nst][ba + 1][nseen], dp[pos][st][ba][seen]);
                    if(ba > 0) {
                        nst = nxt[st][1], nseen = (seen | (nst == s.size()));
                        add(dp[pos + 1][nst][ba - 1][nseen], dp[pos][st][ba][seen]);
                    }
                }
            }
        }
    }
    int ans = 0;
    for(int st = 0; st <= s.size(); st++)
        add(ans, dp[2*n][st][0][1]);
    cout << ans << '\n';
}