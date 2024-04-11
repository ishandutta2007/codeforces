#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

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
#define MOD 998244353LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 300005
int n, m;
int d[MN];
vpii e[MN];
vi ok;
bool vis[MN];
bool dfs(int cn){
    //cout << "doing " << cn << "\n";
    vis[cn] = true;
    int amt = 0;
    for(auto u : e[cn]){
        int nn = u.f;
        if(vis[nn]) continue;
        if(dfs(nn)){ ++amt; ok.pb(u.s);}
    }
    if(amt % 2 == d[cn]){
        //cout << cn << " needs par\n";
        return false;
    } else{
        //cout << cn << " no need\n";
        return true;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    int fst = 0, sm = 0;
    FOR(i, 1, n){
        cin >> d[i];
        if(fst == 0 && d[i] == -1){
            fst = i;
        }
        if(d[i] != -1){
            sm += d[i];
        }
    }
    if(fst == 0 && sm%2 == 1){
        cout << "-1\n";
        return 0;
    }
    d[fst] = sm%2;
    FOR(i, 1, n) if(d[i] == -1) d[i] = 0;
    FOR(i, 1, m){
        int u, v;
        cin >> u >> v;
        e[u].pb({v, i});
        e[v].pb({u, i});
        //cout << "this edge " << u << " " << v << " " << i << "\n";
    }
    dfs(1);
    sort(ok.begin(), ok.end());
    cout << ok.size() << "\n";
    for(auto u : ok) cout << u << "\n";

    return 0;
}