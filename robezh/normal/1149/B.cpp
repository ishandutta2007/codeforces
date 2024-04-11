#include <bits/stdc++.h>
using namespace std;

const int N = (int)255, INF = (int)1e9, L = (int)1e5 + 50;

int n, q;
string str;
string s[3];
int dp[N][N][N];
int nxt[L][26];
int pos[26];

void umin(int &to, int x) {
    to = min(to, x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    cin >> str;
    fill(pos, pos + 26, -1);
    for(int i = n - 1; i >= 0; i--) {
        pos[str[i]-'a'] = i;
        for(int j = 0; j < 26; j++) nxt[i][j] = pos[j];
    }
    int x[3] = {0, 0, 0};
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0][0] = 0;
    while(q--) {
        char op, c; int k;
        cin >> op >> k; k--;

        int il = 0, jl = 0, tl = 0;
        int id = 0, jd = 0, td = 0;
        int ir = s[0].length(), jr = s[1].length(), tr = s[2].length();
        if(k == 0) il = ir, id++;
        if(k == 1) jl = jr, jd++;
        if(k == 2) tl = tr, td++;

        if(op == '+') {
            cin >> c;
            s[k].push_back(c);
            for(int i = il; i <= ir + id; i++) {
                for(int j = jl; j <= jr + jd; j++) {
                    for(int t = tl; t <= tr + td; t++) {
                        int curloc = dp[i][j][t];
                        if(curloc >= n) continue;
                        if(i < s[0].length() && nxt[curloc][s[0][i]-'a'] != -1) {
                            umin(dp[i+1][j][t], nxt[curloc][s[0][i]-'a'] + 1);
                        }
                        if(j < s[1].length() && nxt[curloc][s[1][j]-'a'] != -1) {
                            umin(dp[i][j+1][t], nxt[curloc][s[1][j]-'a'] + 1);
                        }
                        if(t < s[2].length() && nxt[curloc][s[2][t]-'a'] != -1) {
                            umin(dp[i][j][t+1], nxt[curloc][s[2][t]-'a'] + 1);
                        }
                    }
                }
            }
        }
        else {
            for(int i = il; i <= ir; i++) {
                for(int j = jl; j <= jr; j++) {
                    for(int t = tl; t <= tr; t++) {
                        dp[i][j][t] = INF;
                    }
                }
            }
            s[k].pop_back();

        }
        cout << (dp[s[0].length()][s[1].length()][s[2].length()] < INF ? "YES" : "NO") << "\n";
    }
}