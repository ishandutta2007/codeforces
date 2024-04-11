#include <bits/stdc++.h>
using namespace std;

#define N 1005
#define M 100005

template <class T> void chkmax(T &a, T b) { if (a < b) a = b; }

int n, m, a, b;
int dega[N], degb[N];
int ans;
int clr[M];
int nxta[N][N], nxtb[N][N];
int uu[M], vv[M];
int c1, c2;
int stk[M], top;

void prep(int v, int side) {
    if (side == 0) {
        int x = v, id = nxta[x][c2];
        if (!id) return;
        int y = vv[id];
        prep(y, 1);
        stk[top++] = id;
    }
    else {
        int y = v, id = nxtb[y][c1];
        if (!id) return;
        int x = uu[id];
        prep(x, 0);
        stk[top++] = id;
    }
}

int main() {
    
    scanf("%d %d %d", &a, &b, &m);
    for (int i = 1; i <= m; i ++) {
        scanf("%d %d", &uu[i], &vv[i]);
        dega[uu[i]] ++;
        degb[vv[i]] ++;
    }
    for (int i = 1; i <= a; i ++) chkmax(ans, dega[i]);
    for (int i = 1; i <= b; i ++) chkmax(ans, degb[i]);
    for (int i = 1; i <= m; i ++) {
        int x = uu[i], y = vv[i];
        int xx = x;
        for (int j = 1; j <= ans && !clr[i]; j ++) if (!nxta[x][j] && !nxtb[y][j]) {
            clr[i] = j;
            nxta[x][j] = i, nxtb[y][j] = i;
        }
        if (clr[i]) continue;
        c1 = c2 = 0;
        for (int j = 1; j <= ans; j ++) {
            if (!nxta[x][j] && nxtb[y][j]) c1 = j;
            if (nxta[x][j] && !nxtb[y][j]) c2 = j;
        }
        top = 0;
        int side = 1, v = y;
        while (1) {
            if (side == 0) {
                int x = v;
                int id = nxta[x][c2];
                if (!id) break;
                stk[top++] = id;
                v = vv[id];
            }
            else {
                int y = v;
                int id = nxtb[y][c1];
                if (!id) break;
                stk[top++] = id;
                v = uu[id];
            }
            side ^= 1;
        }
        for (int j = 0; j < top; j ++) {
            int id = stk[j];
            int oclr = clr[id], nclr = c1 + c2 - oclr;
            int x = uu[id], y = vv[id];
            nxta[x][nclr] = nxtb[y][nclr] = id;
            clr[id] = nclr;
        }
        if (top & 1) {
            int id = stk[top-1];
            nxta[uu[id]][c1] = 0;
        }
        else {
            int id = stk[top-1];
            nxtb[vv[id]][c2] = 0;
        }
        clr[i] = c1;
        nxta[x][c1] = nxtb[y][c1] = i;
    }
    printf("%d\n", ans);
    for (int i = 1; i <= m; i ++) printf("%d ", clr[i]);
    return 0;
}