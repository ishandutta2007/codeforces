#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 0x3f3f3f3f
#define MOD 1000000007LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 100005
int n;
vi e[MN];
int rt;
int deg[MN];
int d[MN];
bool dp[MN][2]; //dir down, two down
int mx;
vi lf;
bool bad;
void dfs(int cn, int p){
    bool mt = false;
    for(auto nn : e[cn]) if(nn != p){
        d[nn] = d[cn]+1;
        dfs(nn, cn);
        if(deg[nn] == 1){
            if(mt) --mx;
            else mt = true;
            dp[cn][0] = true;
        }
        dp[cn][1] |= dp[nn][0];
    }
    if(dp[cn][0] && dp[cn][1]) bad = true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    F0R(_, n-1){
        int u, v;
        cin >> u >> v;
        e[u].pb(v);
        e[v].pb(u);
        ++deg[u]; ++deg[v];
    }
    FOR(i, 1, n) if(deg[i] == 1) lf.pb(i);
    FOR(i, 1, n) if(deg[i] != 1){rt = i; break;}
    mx = n-1;
    dfs(rt, 0);
    bool ok = true;
    for(auto u : lf){
        if(d[u]%2 != d[lf[0]]%2){
            ok = false;
            break;
        }
    }
    if(ok){
        cout << "1";
    } else{
        cout << "3";
    }
    cout << " " << mx << "\n";
    
    return 0;
}