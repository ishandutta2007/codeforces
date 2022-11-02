#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 1000005
int t, n, m;
vi e[MN];
vi re[MN];
bool vis[MN];
vi order;
int comp[MN];
vi in, out;

void dfs1(int cn){
    vis[cn] = true;
    for(int nn : e[cn]){
        if(!vis[nn]){
            dfs1(nn);
        }
    }
    order.pb(cn);
}
void dfs2(int cn, int col){
    comp[cn] = col;
    for(int nn : re[cn]){
        if(comp[nn] == -1){
            dfs2(nn, col);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(comp, -1, sizeof comp);

    cin >> t;
    F0R(_, t){
        cin >> n >> m;
        F0R(_, m){
            int u, v;
            cin >> u >> v;
            --u; --v;
            e[u].pb(v);
            re[v].pb(u);
        }

        F0R(i, n){
            if(!vis[i]) dfs1(i);
        }
        int cc = 0;
        RFOR(i, n-1, 0){
            if(comp[order[i]] == -1){
                dfs2(order[i], ++cc);
            }
        }
        if(cc == 1){
            cout << "No\n";
        } else{
            cout << "Yes\n";
            F0R(i, n){
                if(comp[i] == 1){
                    out.pb(i);
                } else{
                    in.pb(i);
                }
            }
            cout << in.size() << " " << out.size() << "\n";
            for(auto u : in) cout << u+1 << " ";
            cout << "\n";
            for(auto u : out) cout << u+1 << " ";
            cout << "\n";
        }

        F0R(i, n){
            e[i].clear();
            re[i].clear();
            comp[i] = -1;
            vis[i] = false;
        }
        in.clear(); out.clear(); order.clear();
    }

    return 0;
}