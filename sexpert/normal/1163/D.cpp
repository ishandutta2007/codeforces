#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

const int INF = 1e9;
int dp[1005][55][55];

vi kmp(string s) {
    vector<int> pi(s.size());
    for(int i = 1, j = 0; i < s.size(); i++) {
        while(j && s[i] != s[j]) j = pi[j - 1];
        pi[i] = j += (s[i] == s[j]);
    }
    return pi;
}

void build_aut(string s, vector<vi> &aut) {
    aut.assign(s.size(), vi(26));
    vi pi = kmp(s);
    for(int c = 0; c < 26; c++)
        aut[0][c] = (s[0] == 'a' + c);

    for(int i = 1; i < s.size(); i++) {
        for(int c = 0; c < 26; c++) {
            if(s[i] == 'a' + c) aut[i][c] = i + 1;
            else aut[i][c] = aut[pi[i - 1]][c];
        }
    }
}

int main() {
    string code, s, t;
    cin >> code >> s >> t;
    s += '#';
    t += '#';
    for(int i = 0; i < 1005; i++)
        for(int j = 0; j < 55; j++)
            for(int k = 0; k < 55; k++)
                dp[i][j][k] = -INF;

    vector<vector<int>> saut, taut;
    build_aut(s, saut);
    build_aut(t, taut);
    dp[0][0][0] = 0;
    for(int i = 0; i < code.size(); i++) {
        for(int a = 0; a < s.size(); a++) {
            for(int b = 0; b < t.size(); b++) {
                for(int c = 0; c < 26; c++) {
                    if(code[i] != '*' && code[i] != 'a' + c) continue;
                    int x = saut[a][c], y = taut[b][c];
                    dp[i + 1][x][y] = max(dp[i + 1][x][y], dp[i][a][b] + (x == s.size() - 1) - (y == t.size() - 1));
                }
            }
        }
    }
    int ans = -INF;
    for(int a = 0; a < s.size(); a++)
        for(int b = 0; b < t.size(); b++)
            ans = max(ans, dp[code.size()][a][b]);
    cout << ans << '\n';
}