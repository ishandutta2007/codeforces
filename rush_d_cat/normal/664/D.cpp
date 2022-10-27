#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstring>
#include <set>
#include <map>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define rd(x) scanf("%d", &x)
#define rd2(x, y) scanf("%d %d", &x, &y)
#define pb push_back
#define sz(x) (int)x.size()
#define rep(i, a, b) for (int i=(a);i<=(b);i++)
#define dd(x) cout << #x << " = " << x << endl;
#define max(x, y) (x > y ? x : y)
typedef pair<int, int> pii;
typedef long long LL;
const LL INF = 1000000007;
const LL MOD = 1000000007;
const int N = 100000+10;

int n, m, u, v, T;
vector<pii> g[N];
vector<int> del;
int ans[N][2][2], blk, state[N], vis[N];
char w[2];
void delet() {
    rep(i, 0, sz(del)-1) {
        vis[del[i]] = 0;
    }
    del.clear();
}
LL dfs(int x, int tar, int flag) {
    LL res = 0;
    vis[x] = 1; state[x] = flag;
    del.pb(x);

    //printf("x=%d %d %d\n", x, tar, flag);
    
    for (int i=0;i<g[x].size();i++) {
        int y = g[x][i].fi;
        int c = g[x][i].se;
        //printf("y=%d, c=%d\n", y, c);
        if (vis[y]) {
            if (state[x] != state[y] && c == tar)
                return INF;
            if (state[x] == state[y] && c != tar)
                return INF;

            continue;
        }
        
        if (c == tar) {
            res += dfs(y, tar, flag);
        } else {
            res += dfs(y, tar, !flag);
        }
    }
    return res + flag;
}

int par[N];
int find(int x) {
    return par[x] == x ? x : par[x] = find(par[x]);
}
void init() {
    rd2(n, m);
    rep(i, 1, n) par[i] = i;

    rep(i, 1, m) {
        scanf("%d %d %s", &u, &v, w);
        g[u].pb(mp(v, w[0]=='R'?0:1));
        g[v].pb(mp(u, w[0]=='R'?0:1));
        par[find(u)] = find(v);
    }   


    LL R = 0, B = 0;
    rep(i, 1, n) if (find(i) == i) {
        rep(col, 0, 1) {
            ans[i][col][0] = dfs(i, col, 0); delet(); 
            ans[i][col][1] = dfs(i, col, 1); delet();
            //cout << "!!!!!!!!!!!!" << ans[i][col][1] << endl;
            if (col == 0) R += min(ans[i][col][0], ans[i][col][1]);
            if (col == 1) B += min(ans[i][col][0], ans[i][col][1]);
        }
    }

    if (R > 2*n && B > 2*n) {
        printf("-1\n"); return;
    }
    if (R < B) {
        rep(i, 1, n) if (find(i) == i) {
            if (ans[i][0][0] < ans[i][0][1]) {
                dfs(i, 0, 0); delet();
            } else {
                dfs(i, 0, 1); delet();
            }
        }
    } else {
        rep(i, 1, n) if (find(i) == i) {
            if (ans[i][1][0] < ans[i][1][1]) {
                dfs(i, 1, 0); delet();
            } else {
                dfs(i, 1, 1); delet();
            }
        }        
    }

    int cnt = 0; rep(i, 1, n) cnt += state[i];
    printf("%d\n", cnt);
    rep(i, 1, n) if (state[i]) 
        printf("%d ", i);
}
int main() {
    init();
}