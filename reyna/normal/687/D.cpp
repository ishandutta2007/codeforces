// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; ++i)

const int N = 1005, M = (1 << 20) + 105, S = 5e4 + 4, B = 505, mod = 0;
int n, res[M] , m, q, fr[M], to[M], ln[M];
pair<int, int> sr[M];


struct dsu {
    int par[N], h[N], dead;
    vector<int> comp[N];
    dsu(int x = 0) {
        for (int i = 0; i < N; ++i)
            par[i] = i, comp[i].push_back(i), h[i] = 0;
        dead = 0;
    }
    bool add(int e) {
        int u = fr[e], v = to[e];
        if (par[u] == par[v] && (h[u] ^ h[v]) == 0) {
            dead = 1;
            return 0;
        }
        if (par[u] != par[v]) {
            if (comp[par[u]].size() > comp[par[v]].size())
                swap(u, v);
            int c = h[u], pp = par[u];
            for (int x : comp[pp]) {
                par[x] = par[v];
                h[x] = (c ^ h[v] ^ h[x] ^ 1);
                comp[par[v]].push_back(x);
            }
            comp[pp].clear();
            return 1;
        }
        return 0;
    }
};

vector<int> contain[M];
int ql[N], qr[N];
dsu qd[N], block[B];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(res, -1, sizeof res);
    cin >> n >> m >> q;
    for (int i = 0; i < m; ++i) {
        cin >> fr[i] >> to[i] >> ln[i];
        fr[i]--;
        to[i]--;
        sr[i] = make_pair(ln[i], i);
    }
    for (int i = 0; i < q; ++i) {
        qd[i] = dsu();
        cin >> ql[i] >> qr[i];
        ql[i]--;
        /*
        for (int j = ql[i]; j < min(qr[i], ((ql[i] - 1) / S + 1) * S); ++j)
            if (j < m)
                contain[j].push_back(i);
        for (int j = max((qr[i] / S) * S, ql[i]); j < qr[i]; ++j)
            if (j < m)
                contain[j].push_back(i);
        */
        contain[ql[i] / S].push_back(i);
        contain[qr[i] / S].push_back(i);
    }
    sort(sr, sr + m);
    reverse(sr, sr + m);
    for (int pp = 0; pp < m; ++pp) {
        int e = sr[pp].second;
        for (auto x : contain[e / S]) if (!qd[x].dead && ql[x] <= e && e < qr[x]) {
            qd[x].add(e);
            if (qd[x].dead)
                res[x] = sr[pp].first;
        }
        int bl = e / S;
        if (!block[bl].dead) {
            int flag = block[bl].add(e);
            flag |= block[bl].dead;
            if (flag) {
                int xl = bl * S, xr = (bl + 1) * S;
                for (int x = 0; x < q; ++x) if (!qd[x].dead) {
                    if (ql[x] <= xl && xr <= qr[x]) {
                        qd[x].add(e);
                        if (qd[x].dead)
                            res[x] = sr[pp].first;
                    }
                }
            }
        }
    }
    for (int i = 0; i < q; ++i)
        cout << res[i] << '\n';
}