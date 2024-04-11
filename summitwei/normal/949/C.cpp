#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 100005
int n, m, h;
int t[MN];
vi e[MN];
vi re[MN];

bool vis[MN];
stack<int> o;
void dfs1(int cn){
    if(vis[cn]) return;

    vis[cn] = true;
    F0R(i, e[cn].size()){
        int nn = e[cn][i];

        dfs1(nn);
    }
    o.push(cn);
}

int scc[MN];
int sz[MN];
void dfs2(int cn, int ccc){
    if(scc[cn] != 0) return;

    scc[cn] = ccc;
    sz[ccc]++;
    F0R(i, re[cn].size()){
        int nn = re[cn][i];

        dfs2(nn, ccc);
    }
}

bool ino[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> h;
    FOR(i, 1, n){
        cin >> t[i];
    }
    F0R(_, m){
        int u, v;
        cin >> u >> v;
        int hu = t[u];
        int hv = t[v];
        if((hu+1)%h==hv){
            e[u].pb(v);
            re[v].pb(u);
        }
        if((hv+1)%h==hu){
            e[v].pb(u);
            re[u].pb(v);
        }
    }

    FOR(i, 1, n){
        if(!vis[i]){
            dfs1(i);
        }
    }

    int cur = 0;
    while(!o.empty()){
        int top = o.top();
        o.pop();

        if(scc[top] == 0){
            cur++;
            dfs2(top, cur);
        }
    }

    FOR(i, 1, n){
        int u = scc[i];
        F0R(a, e[i].size()){
            int j = e[i][a];
            int v = scc[j];

            if(u == v) continue;
            ino[u] = true;
        }
    }

    int mn = n;
    int num = 1;
    FOR(i, 1, cur){
        if(!ino[i]){
            if(sz[i] < mn){
                mn = sz[i];
                num = i;
            }
        }
    }

    /*FOR(i, 1, n){
        cout << scc[i] << " ";
    }
    cout << "\n\n";*/

    cout << mn << "\n";
    FOR(i, 1, n){
        if(scc[i] == num) cout << i << " ";
    }

    return 0;
}