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
#define pb push_back
#define sz(x) (int)x.size()
#define rep(i, a, b) for (int i=(a);i<=(b);i++)
#define dd(x) cout << #x << " = " << x << endl;
typedef pair<int, int> pii;
typedef long long LL;
const int N = 500000+10;

int n, m, q, k, x, T;
int u[N], v[N], w[N];
vector< pair<int, int> > g[N], que[N];

int par[N], fat[N], mt[N], wa[N];
int find1(int x) {
    return par[x] == x ? x : par[x] = find1(par[x]);
}
int find2(int x) {
    if (mt[x] != T) mt[x] = T, fat[x] = par[x]; 
    return fat[x] == x ? x : fat[x] = find2(fat[x]);
}

void init() {
    scanf("%d %d", &n, &m);
    rep(i, 1, n) par[i] = fat[i] = i;
    rep(i, 1, m) {
        scanf("%d %d %d", &u[i], &v[i], &w[i]);
        g[ w[i] ].pb(mp(u[i],v[i]));
    }
    scanf("%d", &q);
    rep(i, 1, q) {
        scanf("%d", &k);
        rep(j, 1, k) {
            scanf("%d", &x);
            que[ w[x] ].pb(mp(i, x));
        }
    }
    rep(i, 1, N-1) {
        sort(que[i].begin(), que[i].end());
        rep(j, 0, sz(que[i])-1) {
            if (j == 0 || que[i][j].fi != que[i][j-1].fi)
                T ++;
            if (find2(u[ que[i][j].se ]) == find2( v[ que[i][j].se ] ))
                wa[ que[i][j].fi ] = 1;
            fat[ find2(u[ que[i][j].se ]) ] = find2( v[ que[i][j].se ] );
        } 
        rep(j, 0, sz(g[i])-1) {
            par[find1(g[i][j].fi)] = find1(g[i][j].se);
        }
    }
    rep(i, 1, q) printf("%s\n", wa[i] ? "NO" : "YES");
}

int main() {
    init();
}