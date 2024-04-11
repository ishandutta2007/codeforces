#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int MAXN = 3e5 + 5;
const int MX = 3e3 + 5;
int r, c, n;
int fa[MX * MX * 2];
bool G[MX][MX * 2];
stack<PII> stk;
inline int id(int x, int y) { return (x - 1) * c * 2 + y; }
void I() {
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= 2 * c; j++) {
            int k = id(i, j);
            fa[k] = k;
            G[i][j] = false;
        }
    }
}
int F(int x) {
    if (x == fa[x]) return x;
    stk.push(PII(x, fa[x]));
    return fa[x] = F(fa[x]);
}
void U(int a, int b) {
    a = F(a), b = F(b);
    if (a == b) return;
    stk.push(PII(a, fa[a]));
    stk.push(PII(b, fa[b]));
    fa[b] = a;
}
int DIR[8][2] = {{ -1, -1}, { -1, 0}, { -1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
bool check(int x, int y) {
    while (!stk.empty()) stk.pop();
    int p[2][2] = {{x, y}, {x, y + c}};
    for (int z = 0; z < 2; z++) {
        for (int i = 0; i < 8; i++) {
            int xx = p[z][0] + DIR[i][0];
            int yy = p[z][1] + DIR[i][1];
            if (xx < 1 || xx > r) continue;
            if (yy < 1) yy = 2 * c;
            else if (yy > 2 * c) yy = 1;
            if (G[xx][yy] == false) continue;
            U(id(p[z][0], p[z][1]), id(xx, yy));
        }
    }

    if (F(id(p[0][0], p[0][1])) == F(id(p[1][0], p[1][1]))) {
        while (!stk.empty()) {
            PII tp = stk.top(); stk.pop();
            fa[tp.first] = tp.second;
        }
        return false;
    }
    G[x][y] = G[x][y + c] = true;
    return true;
}
int main() {
    int x, y, ans = 0;
    scanf("%d %d %d", &r, &c, &n); I();

    while (n --) {
        scanf("%d %d", &x, &y);
        if (check(x, y)) ans ++;
    }
    if (c <= 1) ans = 0;
    printf("%d\n", ans);
    return 0;
}