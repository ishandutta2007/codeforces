#include <bits/stdc++.h>
using namespace std;

#define N 111

int n, k, a[11][N], vis[N], tar[N], clr[N*5], nxt[N*5], prv[N*5];

inline int id(int r, int c) {
    return r * (n + 1) + c;
}

inline pair <int, int> co(int id) {
    return pair <int, int> (id / (n + 1), id % (n + 1));
}

inline bool adj(int x, int y) {
    int r1, c1, r2, c2;
    tie(r1, c1) = co(x);
    tie(r2, c2) = co(y);
    return abs(r1 - r2) + abs(c1 - c2) <= 1;
}
vector < tuple <int, int, int> > vec;

inline void push(int i, int x) {
    int r, c;
    tie(r, c) = co(x);
    vec.emplace_back(i, r, c);
}

void print() {
    int sz = vec.size();
    printf("%d\n", sz);
    for (int i = 0; i < sz; i ++) printf("%d %d %d\n", get <0> (vec[i]), get <1> (vec[i]), get <2> (vec[i]));
    puts("");
}

bool solve() {
    while (1) {
        bool brk = 1;
        for (int i = 1; i <= k; i ++) {
            if (adj(vis[i], tar[i])) push(i, tar[i]), vis[i] = clr[vis[i]] = 0;
            if (vis[i]) brk = 0;
        }
        int fg = 0;
        for (int i = 2; i <= 3; i ++)
            for (int j = 1; j <= n; j ++)
                if (clr[id(i,j)] == 0) fg = id(i, j);
        if (!fg) return 1;
        if (brk) break;
        for (int i = prv[fg]; i != fg; i = prv[i]) {
            clr[nxt[i]] = clr[i];
            if (!clr[i]) continue;
            push(clr[i], nxt[i]);
            vis[clr[i]] = nxt[i];
        }
        clr[nxt[fg]] = 0;
    }
    print();
    return 0;
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= 4; i ++)
        for (int j = 1; j <= n; j ++) scanf("%d", &a[i][j]);
    for (int i = 1; i < n; i ++) nxt[id(2,i)] = id(2, i + 1), prv[id(2,i+1)] = id(2, i);
    for (int i = 1; i < n; i ++) nxt[id(3,i+1)] = id(3, i), prv[id(3,i)] = id(3, i + 1);
    nxt[id(2,n)] = id(3, n), nxt[id(3,1)] = id(2, 1), prv[id(3,n)] = id(2, n), prv[id(2,1)] = id(3, 1);
    for (int i = 2; i <= 3; i ++)
        for (int j = 1; j <= n; j ++) vis[a[i][j]] = id(i, j), clr[id(i,j)] = a[i][j];
    for (int i = 1; i <= 4; i += 3)
        for (int j = 1; j <= n; j ++) tar[a[i][j]] = id(i, j);
    if (solve()) puts("-1");
    return 0;
}