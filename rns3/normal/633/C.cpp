#include <bits/stdc++.h>

using namespace std;

#define N 100005

char s[N], tmp[N];

string p[N];
map <string, int> M;
int rlt[N], cnt = 0;
bool vis[N];
int dp[N];

bool Find(int cur, int n) {
    if (cur == n) return 1;
    if (vis[cur]) return dp[cur];
    vis[cur] = 1;
    string S = "";
    for (int i = cur; i < n; i ++) {
        S += s[i];
        if (M.count(S)) {
            if (Find(i + 1, n)) {
                rlt[cnt ++] = M[S];
                return dp[cur] = 1;
            }
        }
    }
    return dp[cur] = 0;
}

main() {
    int n, m;
    scanf("%d\n", &n);
    gets(s);
    scanf("%d", &m);
    for (int i = 0; i < m; i ++) {
        cin >> p[i];
        int len = 0;
        for (int j = 0; j < p[i].length(); j ++) {
            char c = p[i][j];
            if ('A' <= c && c <= 'Z') c -= 'A' - 'a';
            tmp[len ++] = c;
        }
        tmp[len] = 0;
        reverse(tmp, tmp + len);
        string t = tmp;
        M[t] = i;
    }
    Find(0, n);
    for (int i = cnt - 1; i >= 0; i --) {
        cout << p[rlt[i]];
        if (i) putchar(' ');
    }
}