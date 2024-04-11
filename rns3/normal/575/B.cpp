#include <bits/stdc++.h>
using namespace std;
#define M 100100
typedef long long ll;
const int mod = 1000000007;

int n;
int from[M], to[M], cap[M];
vector<int> v[M];
int dep[M];
int dir[M];
int fa[20][M];
int up[M], down[M];
int p2[M * 10] = {1};

void dfs(int x, int f) {
    for (int y, i = 0; i < v[x].size(); i++) {
        int j = v[x][i];
        y = from[j] + to[j] - x;
        if (y == f) {
            continue;
        }
        fa[0][y] = x;
        //printf("fa[%d] = %d\n", y, x);
        dep[y] = dep[x] + 1;
        if (cap[j] == 0) {
            dir[y] = 0;
        } else if (y == from[j]) {
            dir[y] = 1;//up
        } else {
            dir[y] = -1;//down
        }
        dfs(y, x);
    }
}

void DFS(int x, int f) {
    for (int y, i = 0; i < v[x].size(); i++) {
        int j = v[x][i];
        y = from[j] + to[j] - x;
        if (y == f) {
            continue;
        }
        DFS(y, x);
        up[x] += up[y];
        down[x] += down[y];
    }
    //printf("dir[%d] = %d\n", x, dir[x]);
    //printf("up[%d] = %d, down[%d] = %d\n", x, up[x], x, down[x]);
}

int LCA(int x, int y) {
    //printf("x = %d, y = %d\n", x, y);
    //printf("dep = %d, %d\n", dep[x], dep[y]);
    if (dep[x] < dep[y]) {
        swap(x, y);
    }
    for (int i = 19; i >= 0; i--) if (dep[x] >= dep[y] + (1<<i)) {
        x = fa[i][x];
    }
    if (x == y) {
        return x;
    }
    //printf("~~~~x = %d, y = %d\n", x, y);
    for (int i = 19; i >= 0; i--) if (dep[x] >= (1<<i)) {
        if (fa[i][x] != fa[i][y]) {
            x = fa[i][x];
            y = fa[i][y];
        }
    }
    return fa[0][x];
}

int main() {
    //freopen("B.in", "r", stdin);
    //freopen("B.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i < 10 * M; i++) {
        p2[i] = p2[i-1] * 2 % mod;
    }
    for (int x, y, c, i = 1; i < n; i++) {
        scanf("%d %d %d", &x, &y, &c);
        //printf("x = %d, y = %d, c = %d\n", x, y, c);
        from[i] = x;
        to[i] = y;
        cap[i] = c;
        v[x].push_back(i);
        v[y].push_back(i);
    }
    dfs(1, 0);
    for (int i = 1; i <= 19; i++) {
        for (int j = 1; j <= n;  j++) {
            fa[i][j] = fa[i-1][fa[i-1][j]];
        }
    }

    int st, T, en;
    scanf("%d", &T);
    st = 1;

    while (T--) {
        scanf("%d", &en);
        if (st == en) {
            continue;
        }
        int z = LCA(st, en);
        //printf("st = %d, en = %d, z = %d\n", st, en, z);
        up[st]++;
        up[z]--;
        down[en]++;
        down[z]--;
        st = en;
    }
    DFS(1, 0);

    ll answer = 0;

    for (int i = 2; i <= n; i++) if (dir[i] != 0) {
        if (dir[i] == 1 && down[i] > 0) {
            answer += p2[down[i]] - 1;
            //fprintf(stderr, "~~%d\n", p2[down[i]] - 1);
        }
        if (dir[i] == -1 && up[i] > 0) {
            answer += p2[up[i]] - 1;
        }
        answer %= mod;
    }
    printf("%I64d\n", answer);
    return 0;
}