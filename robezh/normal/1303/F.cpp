#include <bits/stdc++.h>
using namespace std;

const int N = 305, Q = (int)2e6 + 50;

struct Qry {
    int x, y, c;

    void read() {
        cin >> x >> y >> c;
        x--, y--;
    }
} qry[Q];

int n, m, q;
int mp[N][N];
int f[N * N];
int dx[] = {0, 0, -1, 1}, dy[] = {1, -1, 0, 0};
int ch[Q], off[Q];
int ans[Q];

inline int gid(int i, int j) {
    return i * m + j;
}

int find(int x) {
    return f[x] == x ? x : f[x] = find(f[x]);
}

int cur;

void unite(int x, int y) {
    x = find(x), y = find(y);
    if(x != y) cur--;
    f[x] = y;
}


bool in_bound(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(int u, int v, int val) {
    f[u * m + v] = val;
    for(int d = 0; d < 4; d++) {
        int nx = u + dx[d], ny = v + dy[d];
        if(in_bound(nx, ny) && mp[nx][ny] == mp[u][v] && f[nx * m + ny] == -1) dfs(nx, ny, val);
    }
}

int build(int val, int ig) {
    for(int k = 0; k < n * m; k++) {
        f[k] = -1;
    }
    int ccnt = 0;

    for(int ki = 0; ki < n; ki++) {
        for(int kj = 0; kj < m; kj++) {
            if(ig != -1 && (!((mp[ki][kj] == val) ^ ig))) {
                f[ki * m + kj] = ki * m + kj;
                continue;
            }
            if(f[ki * m + kj] != -1) continue;
            dfs(ki, kj, ki * m + kj);
            ccnt++;
        }
    }
    return ccnt;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> q;
    for(int i = 0; i < q; i++) qry[i].read();
    int r = 0;
    for(int i = 0; i < q; i = r) {
        while(r < q && qry[r].c == qry[i].c) r++;

        build(qry[i].c, 0);
        cur = 0;
        for(int j = i; j < r; j++) {
            int x = qry[j].x, y = qry[j].y;
            ch[j] = mp[x][y];
            if(mp[x][y] != qry[j].c) cur++;
            mp[x][y] = qry[j].c;
            if(x >= 1 && mp[x-1][y] == mp[x][y]) unite(gid(x-1, y), gid(x, y));
            if(y >= 1 && mp[x][y-1] == mp[x][y]) unite(gid(x, y-1), gid(x, y));
            if(x < n - 1 && mp[x+1][y] == mp[x][y]) unite(gid(x+1, y), gid(x, y));
            if(y < m - 1 && mp[x][y+1] == mp[x][y]) unite(gid(x, y+1), gid(x, y));
            off[j] += cur;
        }

        cur = 0;
        build(qry[i].c, 1);
        for(int j = r - 1; j >= i; j--) {
            off[j] += cur;
            int x = qry[j].x, y = qry[j].y;
            if(mp[x][y] != ch[j]) {
                cur++;
                mp[x][y] = ch[j];
                if(x >= 1 && mp[x-1][y] == mp[x][y]) unite(gid(x-1, y), gid(x, y));
                if(y >= 1 && mp[x][y-1] == mp[x][y]) unite(gid(x, y-1), gid(x, y));
                if(x < n - 1 && mp[x+1][y] == mp[x][y]) unite(gid(x+1, y), gid(x, y));
                if(y < m - 1 && mp[x][y+1] == mp[x][y]) unite(gid(x, y+1), gid(x, y));
            }

        }
        int ccnt = build(qry[i].c, -1);
        for(int j = i; j < r; j++) {
            ans[j] = ccnt - cur + off[j];
        }
        for(int j = i; j < r; j++) {
            int x = qry[j].x, y = qry[j].y;
            mp[x][y] = qry[j].c;
        }
    }

    for(int i = 0; i < q; i++) cout << ans[i] << '\n';

}