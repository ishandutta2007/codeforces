#include <bits/stdc++.h>
using namespace std;

#define N 101000

int st[N], fa[20][N], pa[N], dep[N], rev[N];
vector<int> v[N];

int n, fin;

void DFS(int x, int p) {
    //printf("A %d %d\n", x, p);
    st[x] = ++fin;
    rev[fin] = x;
    for(int i = 0; i < v[x].size(); i ++) {
        int y = v[x][i];
        if(y == p) continue;
        dep[y] = dep[x] + 1;
        pa[y] = x;
        DFS(y, x);
    }
    return ;
}

void RMQ() {
    for(int i = 1; i <= n; i ++) fa[0][i] = pa[i];
    for(int i = 1; i < 20; i ++) for(int j = 1; j <= n; j ++) fa[i][j] = fa[i - 1][fa[i - 1][j]];
    return ;
}

int Fa(int x, int h) {
    for(int i = 0; i < 20; i ++) if((h >> i) & 1) x = fa[i][x];
    return x;
}

int Lca(int x, int y) {
    if(dep[x] < dep[y]) swap(x, y);
    x = Fa(x, dep[x] - dep[y]);
    if(x == y) return x;
    int pp;
    for(int i = 19; i >= 0; i --) {
        if(fa[i][x] == fa[i][y]);
        else x = fa[i][x], y = fa[i][y];
    }
    return pa[x];
}
set<int> S;
set<int> :: iterator it;

int insert(int x) {
    if(S.empty()) return 1;
    it = S.lower_bound(st[x]);
    if(S.size() == 1) {
        it = S.begin();
        int p = *it;
        p = rev[p];
        int xx = Lca(x, p);
        //printf("AA%d %d %d\n", x, p, xx);
        return dep[x] + dep[p] - dep[xx] * 2;
    }
    int p, p1;
    if(it == S.begin()) {
        p = *it;
        p = rev[p];
        it = S.end();
        it --;
        p1 = *it;
        p1 = rev[p1];
    } else if(it == S.end()){
        it --;
        p = *it;
        p = rev[p];
        it = S.begin();
        p1 = *it;
        p1 = rev[p1];
    } else {
        p = *it;
        p = rev[p];
        it --;
        p1 = *it;
        p1 = rev[p1];
    }
    int xx = Lca(x, p);
    int yy = Lca(x, p1);
    int zz = Lca(p, p1);
    //if(x == 5) printf("B%d %d %d %d %d %d\n", p, xx, p1, yy, p, zz);
    return dep[x] - dep[xx] - dep[yy] + dep[zz];
}

int main() {
    //freopen("2.in", "r", stdin);
    int K, x, y;
    scanf("%d%d", &n, &K);
    for(int i = 1; i < n; i ++) {
        scanf("%d%d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    fin = 0;
    pa[1] = 1;
    DFS(1, 0);
    //for(int i = 1; i <= n; i ++) printf("%d %d\n", i, st[i]);
    RMQ();

    int j = 1;
    int kk = 0;
    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        while(1) {
            if(j > n) break;
            int t = insert(j);
            //if(j == 5 && i == 1) printf("A%d\n", t);
            if(kk + t > K) break;
            S.insert(st[j]);
            kk += t;
            //printf("%d %d %d\n", i, j, kk);
            ans = max(ans, j - i + 1);
            j ++;
        }

        S.erase(st[i]);
        int t = insert(i);
        kk -= t;
    }
    printf("%d\n", ans);
    return 0;
}