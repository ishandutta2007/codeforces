#include <bits/stdc++.h>
using namespace std;

const int B = 26, N = (int)6e5 + 50;

struct upd{int i, b, val;};
vector<upd> St;
int res = 0;
int nxt[N][B];
int dep[N], sz[N];
int ncnt = 0;
vector<int> lev[N];

int n;

void dfs(int v, int d) {
    dep[v] = d;
    sz[v] = 1;
    lev[d].push_back(v);
    for(int j = 0; j < B; j++) {
        if(nxt[v][j] != -1) dfs(nxt[v][j], d + 1);
    }
}

int merge(int u, int v) {
    if(u == -1) return v;
    if(v == -1) return u;
    int cur = ncnt++;
    res++;
    for(int b = 0; b < B; b++) nxt[cur][b] = merge(nxt[u][b], nxt[v][b]);
    return cur;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(nxt, -1, sizeof(nxt));
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int u, v; char c; cin >> u >> v >> c;
        u--, v--;
        nxt[u][c - 'a'] = v;
    }
    dfs(0, 0);
    int fres = n, fp = -1;
    for(int d = 0; d < n; d++) {

        ncnt = n;
        res = 0;
        int add = 0;
        for(int x : lev[d]) {
            int fir = ncnt++;
            memset(nxt[fir], -1, sizeof(nxt[fir]));
            for(int j = 0; j < B; j++) {
                if(nxt[x][j] != -1) {
                    fir = merge(fir, nxt[x][j]);
                }
            }
        }
        while(!St.empty()) {
            auto p = St.back(); St.pop_back();
            nxt[p.i][p.b] = p.val;
        }
        if(n - res < fres) {
            fres = n - res;
            fp = d + 1;
        }
    }
    cout << fres << endl;
    cout << fp << endl;

}