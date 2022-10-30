#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
#define INF 0x3f3f3f3f
#define MOD 998244353LL //119*2^23+1
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 100005
int n, m;
ll c[MN];
pii bruh[MN];
vi e[MN];
int d[MN];
int p[MN];

vi cyc;
void gc(int bt, int tp){
    //cout << "getting " << bt << " " << tp << "\n";
    int mn = bt, mx = bt;
    int cur = bt;
    cyc.pb(bt);
    while(cur != tp){
        //cout << "on " << cur << "\n";
        cur = p[cur];
        cyc.pb(cur);
    }
}
bool dfs(int cn){ //find if odd cycle exists
    //cout << "doing " << cn << "\n";
    for(auto nn : e[cn]){
        if(d[nn] == -1){
            d[nn] = d[cn]+1;
            p[nn] = cn;
            if(dfs(nn)) return true;
        } else if(nn != p[cn] && d[nn] < d[cn]){
            if((d[nn]-d[cn])%2 == 0){
                gc(cn, nn);
                return true;
            }
        }
    }
    return false;
}

map<pii, ll> res;
void ae(int u, int v, ll ch){
    if(u > v) swap(u, v);
    //cout << "adding " << u << " " << v << " " << ch << "\n";
    res[{u, v}] += ch;
    c[u] += ch;
    c[v] += ch;
}

bool vis[MN];
void dfs2(int cn, int p){
    vis[cn] = true;
    for(auto nn : e[cn]){
        if(vis[nn]) continue;
        dfs2(nn, cn);
    }
    if(p != 0){
        ae(cn, p, -c[cn]);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    FOR(i, 1, n){
        int x;
        cin >> x;
        c[i] = -x;
    }
    F0R(i, m){
        int u, v;
        cin >> u >> v;
        if(u > v) swap(u, v);
        e[u].pb(v);
        e[v].pb(u);
        bruh[i] = {u, v};
    }
    memset(d, -1, sizeof d);
    d[1] = 0;
    
    bool hmm = dfs(1);
    int rt;
    if(hmm){
        rt = cyc[0];
        /*cout << "cycle found\n";
        for(auto u : cyc) cout << u << " ";
        cout << "\n";*/
    } else{
        rt = 1;
    }
    dfs2(rt, 0);
    if(!hmm){
        if(c[rt] != 0){
            cout << "NO\n";
        } else{
            cout << "YES\n";
            F0R(i, m){
                cout << res[bruh[i]] << "\n";
            }
        }
    } else{
        ll d = -c[rt]/2;
        F0R(i, cyc.size()-1){
            ae(cyc[i], cyc[i+1], d);
            d = -d;
        }
        ae(cyc[0], cyc[cyc.size()-1], d);
        cout << "YES\n";
        F0R(i, m){
            cout << res[bruh[i]] << "\n";
        }
    }

    return 0;
}