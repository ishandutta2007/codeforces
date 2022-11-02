#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
#define INF 0x3f3f3f3f
#define MOD 1000000007LL
#define EPS 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 100005
int n, m;
int f[MN];
vi e[MN];
vi re[MN];
int vis[MN];
void dfs1(int cn){
    if(vis[cn] & 1) return;
    vis[cn] |= 1;
    //if(f[cn] == 2) return;
    for(auto nn : e[cn]){
        dfs1(nn);
    }
}
void dfs2(int cn){
    if(vis[cn] & 2) return;
    vis[cn] |= 2;
    if(f[cn] == 1) return;
    for(auto nn : re[cn]){
        dfs2(nn);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    FOR(i, 1, n) cin >> f[i];
    F0R(_, m){
        int u, v;
        cin >> u >> v;
        e[u].pb(v);
        re[v].pb(u);
    }
    FOR(i, 1, n){
        if(f[i] == 1){
            dfs1(i);
        } else if(f[i] == 2){
            dfs2(i);
        }
    }
    FOR(i, 1, n){
        if(vis[i] == 3){
            cout << "1\n";
        } else{
            cout << "0\n";
        }
    }

    return 0;
}