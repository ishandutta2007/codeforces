#include <bits/stdc++.h>
using namespace std;

const int M = 300001;

int n, m;
vector<int> v[M], w[M];
int a[M], b[M], c[M];
int col[M], q[M], sto[M];
const int inf = 1e9;


int can(int color) {
    for(int i = 1; i <= n; i ++) v[i].clear(), w[i].clear();
    memset(col, 0, sizeof(col));
    for(int i = 1; i <= m; i ++) {
        int x = a[i], y = b[i], z = c[i];
        if(z == color) {
            w[x].push_back(y);
            w[y].push_back(x);
        }
        else {
            v[x].push_back(y);
            v[y].push_back(x);
        }
    }

    for(int i = 1; i <= n; i ++) if(!col[i]) {
        int qt = 0;
        q[qt ++] = i;
        col[i] = 1;
        for(int qh = 0; qh < qt;) {
            int x = q[qh++];
            for(int j = 0; j < v[x].size(); j ++) {
                int y = v[x][j];
                if(col[y] == col[x]) return inf;
                if(col[y]) continue;
                q[qt++] = y;
                col[y] = 3 - col[x];
            }
            for(int j = 0; j < w[x].size(); j ++) {
                int y = w[x][j];
                if(col[y] == 3 - col[x]) return inf;
                if(col[y]) continue;
                q[qt ++] = y;
                col[y] = col[x];
            }
        }
        int cnt = 0;
        for(int j = 0; j < qt; j ++) if(col[q[j]] == 1) cnt ++;
        if(qt - cnt > cnt) {
            for(int j = 0; j < qt; j ++) col[q[j]] = 3 - col[q[j]];
        }
    }
    int cnt = 0;
    for(int i = 1; i <= n; i ++) if(col[i] == 2) cnt ++;
    return cnt;
}

void print() {
    int cnt = 0;
    for(int i = 1; i <= n; i ++) if(col[i] == 2) {
        sto[cnt ++] = i;
    }
    printf("%d\n", cnt);
    for(int i = 0; i < cnt; i ++) printf("%d ", sto[i]); puts("");
}

int main() {
    ///freopen("c.in", "r", stdin);
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i ++) {
        int x, y, z;
        char s[10];
        scanf("%d %d %s", &x, &y, s);
        if(s[0] == 'B') z = 0;
        else z = 1;
        a[i] = x; b[i] = y; c[i] = z;
    }
    int ans = inf, pos = -1;
    if(can(0) < ans) ans = can(0), pos = 0;
    if(can(1) < ans) ans = can(1), pos = 1;
    if(pos < 0) return puts("-1");
    can(pos);
    print();
}