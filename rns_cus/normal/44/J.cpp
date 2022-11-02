#include <bits/stdc++.h>
using namespace std;

#define N 1010

int n, m;
char s[N][N];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool vis[4];

bool solve() {
    for (int i = 2; i <= n + 1; i ++) {
        for (int j = 2; j <= m + 1; j ++) {
            if (s[i][j] == 'B') return 1;
            if (s[i][j] == 'W') {
                if (s[i][j+1] == 'B') {
                    if (s[i][j+2] != 'W') return 1;
                    memset(vis, 0, 4);
                    for (int k = 0; k < 4; k ++) {
                        for (int l = 0; l < 4; l ++) {
                            int x = i + dx[k] + dx[l], y = j + 1 + dy[k] + dy[l];
                            int c = s[x][y] - 'a';
                            if (0 <= c && c < 4) vis[c] = 1;
                        }
                    }
                    int k;
                    for (k = 0; ; k ++) if (!vis[k]) break;
                    s[i][j] = s[i][j+1] = s[i][j+2] = k + 'a';
                }
                else {
                    if (s[i+1][j] != 'B') return 1;
                    if (s[i+2][j] != 'W') return 1;
                    memset(vis, 0, 4);
                    for (int k = 0; k < 4; k ++) {
                        for (int l = 0; l < 4; l ++) {
                            int x = i + 1 + dx[k] + dx[l], y = j + dy[k] + dy[l];
                            int c = s[x][y] - 'a';
                            if (0 <= c && c < 4) vis[c] = 1;
                        }
                    }
                    int k;
                    for (k = 0; ; k ++) if (!vis[k]) break;
                    s[i][j] = s[i+1][j] = s[i+2][j] = k + 'a';
                }
            }
        }
    }
    return 0;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 2; i <= n + 1; i ++) scanf("%s", s[i] + 2);
    for (int i = 2; i <= n + 1; i ++) for (int j = 2; j <= m + 1; j ++) s[i][j] = toupper(s[i][j]);
    if (solve()) puts("NO");
    else {
        puts("YES");
        for (int i = 2; i <= n + 1; i ++) puts(s[i] + 2);
    }

    return 0;
}