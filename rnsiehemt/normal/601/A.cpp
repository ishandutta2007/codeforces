#include <bits/stdc++.h>
#define sz(x) ((int)((x).size()))
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int MaxN = 405;

int N, M, d[MaxN];
bool e[MaxN][MaxN], seen[MaxN];

int main()
{
    scanf("%d%d", &N, &M);
    bool flip = false;
    for (int i = 0; i < M; i++) {
        int u, v; scanf("%d%d", &u, &v); u--; v--;
        e[u][v] = e[v][u] = true;
        if (std::min(u, v) == 0 && std::max(u, v) == N-1) flip = true;
    }
    if (flip) for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
        e[i][j] = !e[i][j];
    }
    std::queue<int> q;
    seen[0] = true;
    q.push(0);
    while (!q.empty()) {
        int k = q.front(); q.pop();
        if (k == N-1) {
            printf("%d\n", d[k]);
            return 0;
        }
        for (int i = 0; i < N; i++) if (i != k && !seen[i] && e[i][k]) {
            seen[i] = true;
            d[i] = d[k] + 1;
            q.push(i);
        }
    }
    printf("-1\n");
}