#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 1000000000
#define MOD 998244353LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 200005
int n, m;
vi e[MN];
ll w[MN];

set<pii> br;
bool chk(int a, int b){
    if(a > b) swap(a, b);
    return br.count({a, b});
}

bool vis[MN];
int tin[MN], low[MN];
int t;

void dfs(int cn, int p = -1){
    //cout << "doing " << cn << "\n";
    vis[cn] = true;
    tin[cn] = low[cn] = t++;
    for(auto nn : e[cn]) if(nn != p){
        if(vis[nn]){
            low[cn] = min(low[cn], tin[nn]);
        } else{
            dfs(nn, cn);
            low[cn] = min(low[cn], low[nn]);
            if(low[nn] > tin[cn]){
                int u = cn, v = nn;
                if(u > v) swap(u, v);
                br.insert({u, v});
            }
        }
    }
}
ll wsm[MN];
int cc[MN];
int csz[MN];
int cbcc(int ccc, int cn, int p = -1){
    cc[cn] = ccc;
    ++csz[ccc];
    //cout << cn << " in " << ccc << "\n";
    wsm[ccc] += w[cn];
    for(auto nn : e[cn]){
        if(cc[nn] != 0) continue;
        if(chk(cn, nn)) continue;
        cbcc(ccc, nn, cn);
    }
}
vi ne[MN];

ll sm;
ll mx;
pair<ll, bool> dfs2(int cn, int p = -1){ //yescyc = true
    ll cmx = 0;
    bool fd = false;
    for(auto nn : ne[cn]) if(nn != p){
        auto val = dfs2(nn, cn);
        if(!val.s){
            cmx = max(cmx, val.f);
        } else{
            fd = true;
        }
    }
    if(fd || csz[cn] > 1){
        sm += wsm[cn];
        mx = max(mx, cmx);
        //cout << cn << " true!\n";
        return {0, true};
    } else{
        mx = max(mx, cmx+wsm[cn]);
        //cout << cn << " false " << cmx+wsm[cn] << "\n";
        return {cmx+wsm[cn], false};
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    FOR(i, 1, n){
        cin >> w[i];
    }
    F0R(_, m){
        int u, v;
        cin >> u >> v;
        e[u].pb(v);
        e[v].pb(u);
    }
    int s;
    cin >> s;

    //cout << "bruh\n";

    memset(vis, false, sizeof vis);
    memset(tin, -1, sizeof tin);
    memset(low, -1, sizeof low);
    FOR(i, 1, n){
        if(!vis[i]) dfs(i);
    }
    //cout << "bruh2\n";
    int col = 0;
    FOR(i, 1, n){
        if(cc[i] == 0){
            ++col;
            cbcc(col, i);
        }
    }
    //cout << "bruh3\n";
    for(auto u : br){
        ne[cc[u.f]].pb(cc[u.s]);
        ne[cc[u.s]].pb(cc[u.f]);
        //cout << "edge " << cc[u.f] << " " << cc[u.s] << "\n";
    }

    auto res = dfs2(cc[s]);
    cout << sm+mx << "\n";

    return 0;
}