#include <bits/stdc++.h>
using namespace std;

#define N 111

int change(char *s) {
    return (s[0] - 'a') * 8 + s[1] - '1';
}

char s[][10] = {"LU", "U", "RU", "L", "R", "LD", "D", "RD"};
int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[] = {1, 1, 1, 0, 0, -1, -1, -1};

typedef pair <int, int> pii;

int dep[N];
pii p[N];

void bfs(int u) {
    queue <int> Q;
    Q.push(u), dep[u] = 0;
    while (!Q.empty()) {
        u = Q.front(); Q.pop();
        for (int i = 0; i < 8; i ++) {
            int x = dx[i], y = dy[i];
            int v = u + x * 8 + y;
            x += u >> 3, y += u & 7;
            if (min(x, y) < 0 || max(x, y) > 7) continue;
            if (dep[v] >= 0) continue;
            p[v] = pii(u, i); Q.push(v); dep[v] = dep[u] + 1;
        }
    }
}

char t[10];

int main() {
    memset(dep, -1, sizeof dep);
    scanf("%s", t); int x = change(t);
    scanf("%s", t); int y = change(t);
    bfs(x);
    printf("%d\n", dep[y]);
    vector <int> v;
    while (y != x) v.push_back(p[y].second), y = p[y].first;
    reverse(v.begin(), v.end());
    for (auto x : v) puts(s[x]);

    return 0;
}