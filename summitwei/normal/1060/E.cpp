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

#define MN 200005
int n;
vi e[MN];
int sz[MN];
int d[MN];
int od, ev;
ll tot;

void dfs(int cn, int p){
    sz[cn] = 1;
    if(d[cn] % 2 == 0) ++ev;
    else ++od;
    for(auto nn : e[cn]) if(nn != p){
        d[nn] = d[cn]+1;
        dfs(nn, cn);
        sz[cn] += sz[nn];
    }
    tot += 1LL*sz[cn]*(n-sz[cn]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    F0R(i, n-1){
        int u, v;
        cin >> u >> v;
        e[u].pb(v);
        e[v].pb(u);
    }
    dfs(1, 0);
    cout << (tot+1LL*od*ev)/2 << "\n";
    
    return 0;
}