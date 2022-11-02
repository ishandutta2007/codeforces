#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
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
int n, k;
vi e[MN];
struct Node{
    int sz, dep, ind;
    int val;
};
Node ree[MN];
bool comp(Node a, Node b){
    if(a.sz != b.sz) return a.sz > b.sz;
    if(a.dep != b.dep) return a.dep < b.dep;
    return a.ind < b.ind;
}
int vals[MN];
void dfs(int cn, int p){
    ree[cn].sz = 1; ree[cn].ind = cn;
    for(auto nn : e[cn]) if(nn != p){
        ree[nn].dep = ree[cn].dep+1;
        dfs(nn, cn);
        ree[cn].sz += ree[nn].sz;
    }
    vals[cn] = ree[cn].sz-ree[cn].dep-1;
    //cout << cn << " " << vals[cn] << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k; k = n-k;
    F0R(_, n-1){
        int u, v;
        cin >> u >> v;
        e[u].pb(v);
        e[v].pb(u);
    }
    
    dfs(1, 0);
    sort(vals+1, vals+1+n, greater<int>() );
    ll sm = 0;
    FOR(i, 1, k){
        sm += vals[i];
    }
    cout << sm << "\n";
    
    return 0;
}