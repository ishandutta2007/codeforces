#include <bits/stdc++.h>
using namespace std;
int read();

int n;
char t[102];
int w[102][102], rnk[102][102], pos[102];

vector<int> p[102];
queue<int> q;

void init(int t) {
    for (int i = 1; i <= n; ++i) {
        p[i].clear(), p[i + n].clear();
        for (int j = 1; j <= n; ++j)
            p[i].push_back(j + n), p[i + n].push_back(j);
        sort(p[i].begin(), p[i].end(),
             [&](int a, int b) { return w[i][a - n] > w[i][b - n] ^ t; });
        sort(p[i + n].begin(), p[i + n].end(),
             [&](int a, int b) { return w[a][i] < w[b][i] ^ t; });
        q.push(i), pos[i] = 0, pos[i + n] = n;
        for (int j = 0; j < n; ++j)
            rnk[j][p[i][j]] = j, rnk[i + n][p[i + n][j]] = j;
    }

    while (!q.empty()) {
        int u = q.front(), v;
        while (pos[v = p[u][pos[u]]] < rnk[v][u]) ++pos[u];
        if (pos[v] < n) q.push(p[v][pos[v]]);
        pos[v] = rnk[v][u], q.pop();
    }
}

int main() {
    for (int T = read(); T; --T) {
        n = read();
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j) w[i][j] = read();
        puts("B"), fflush(stdout), scanf("%s", t);
        if (t[0] == 'I')
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= n; ++j) w[i][j] = -w[i][j];
        int u;
        for (init((u = read()) > n); ~u; u = read())
            printf("%d\n", p[u][pos[u]]), fflush(stdout);
    }
    return 0;
}

int read() {
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') f = (c == '-') ? -1 : f, c = getchar();
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}