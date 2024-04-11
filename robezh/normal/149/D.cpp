#include <bits/stdc++.h>
using namespace std;



typedef long long ll;
const int N = 705, mod = (int)1e9 + 7;

struct P {
    int a, b;
};

int n;
ll dp[N][N][3][3];
stack <int> S;
int nxt[N];
string str;
vector<P> good;
vector<int> three;

#define forgood(x, y) for(int iii = 0, x, y; iii < good.size() && (true | (x = good[iii].a) | (y = good[iii].b)); iii++)

bool bad(int a, int b) {
    return a > 0 && a == b;
}

bool exact(int a, int b) {
    return ((a == 0) != (b == 0));
}

int main() {
    for(int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) if (!bad(i, j)) good.push_back({i, j});
        three.push_back(i);
    }
    cin >> str;
    n = str.length();
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == '(') S.push(i);
        else {
            nxt[S.top()] = i, S.pop();
            nxt[i] = -1;
        }
    }

    for(int i = 0; i < n; i++)
        if(nxt[i] == i + 1) {
            forgood(k1, k2) {
                if(exact(k1, k2)) dp[i][i+1][k1][k2] = 1;
            }
        }
    for(int d = 2; d < n; d++) {
        for(int i = 0; i + d < n; i++) {
            if(str[i] != '(' || str[i+d] != ')') continue;
            if(nxt[i] == i + d) {
                forgood(kl, k1) {
                    forgood(kr, k2) {
                        if (!exact(kl, kr)) continue;
                        dp[i][i + d][kl][kr] += dp[i + 1][i + d - 1][k1][k2];
                        dp[i][i + d][kl][kr] %= mod;
                    }
                }
            }
            else {
                int nxtr = nxt[i] + 1;
                for(int kl : three) for(int kr : three)
                        forgood(k1, k2) {
                            dp[i][i+d][kl][kr] += dp[i][nxtr-1][kl][k1] * dp[nxtr][i+d][k2][kr];
                            dp[i][i+d][kl][kr] %= mod;
                        }
            }
        }
    }
    ll res = 0;
    for(int i : three) for(int j : three) {
        res += dp[0][n-1][i][j];
    }
    cout << res % mod << endl;
}