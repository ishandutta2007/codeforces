#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int N = 1e5 + 13;
const int LOGN = 30;

int p[N][LOGN], sz[N][LOGN];

int getp(int x, int k) {
    return (x == p[x][k] ? x : getp(p[x][k], k));
}

void unite(int x, int y, int k) {
    x = getp(x, k);
    y = getp(y, k);

    if(x == y)
        return;

    if(sz[x][k] < sz[y][k])
        swap(x, y);

    sz[x][k] += sz[y][k];
    p[y][k] = x;
}

vector<pii> g[N];
//int mask[N];
bool is[N], is2[N];
bool used[N];

void dfs(int v, int k) {
    is2[v] = used[v] = true;

    for(pii p : g[v]) {
        if((p.s & (1 << k)) && !used[p.f])
            dfs(p.f, k);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int k = 0; k < LOGN; k++) {
            p[i][k] = i;
            sz[i][k] = 1;
        }
    }


    for(int i = 0; i < m; i++) {
        int v, u, w;
        cin >> v >> u >> w;

        v--;
        u--;

        for(int k = 0; k < LOGN; k++) {
            if(w & (1 << k))
                unite(v, u, k);
        }

        if((w & 1) == 0) {
            is[v] = is[u] = true;
//            mask[v] = (1 << LOGN) - 1;
//            mask[u] = (1 << LOGN) - 1;
        }

        g[v].emplace_back(u, w);
        g[u].emplace_back(v, w);
    }

    for(int k = 1; k < LOGN; k++) {
        for(int i = 0; i < n; i++)
            used[i] = false;

        for(int i = 0; i < n; i++) {
            if(is[i] && !used[i])
                dfs(i, k);
        }
    }

    int q;
    cin >> q;

    for(int i = 0; i < q; i++) {
        int v, u;
        cin >> v >> u;

        v--;
        u--;

        bool fl = false;
        for(int k = 0; k < LOGN; k++) {
            if(getp(v, k) == getp(u, k)) {
                fl = true;
//                cout << k << endl;
                break;
            }
        }

        if(fl)
            cout << 0 << '\n';
        else if(is2[v])
            cout << 1 << '\n';
        else
            cout << 2 << '\n';

//        cout << "----------------------" << endl;
    }

//    int t = 1;
//    cin >> t;
//
//    while(t--)
//        solve();
}