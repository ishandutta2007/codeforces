#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
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

#define MN 100005
int n;
vi e[MN];
int deg[MN];
int k;

vpii res;
void dfs(int cn, int p, int t){ //start time, end time = start time - 1
    int ct = t;
    int r = min(k, t+deg[cn]);
    for(auto nn : e[cn]) if(nn != p){
        if(ct == r){ct -= deg[cn]; res.pb({cn, ct}); }
        ++ct;

        res.pb({nn, ct});
        dfs(nn, cn, ct);
        res.pb({cn, ct});
    }
    if(cn != 1 && ct > t-1){
        res.pb({cn, t-1});
    }
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
        deg[u]++; deg[v]++;
    }
    FOR(i, 1, n) k = max(k, deg[i]);
    res.pb({1, 0});
    dfs(1, 0, 0);

    cout << res.size() << "\n";
    for(auto u : res){
        cout << u.f << " " << u.s << "\n";
    }

    return 0;
}