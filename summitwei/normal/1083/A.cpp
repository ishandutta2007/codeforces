#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define MAX_N 300005
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

int N;
vpii edges[MAX_N];
ll buy[MAX_N];
ll best[MAX_N]; //stores best from this node

int par[MAX_N];

ll mx;

void dfs(int node){
    ll first = 0;
    ll second = 0;
    
    F0R(i, edges[node].size()){
        int newNode = edges[node][i].f;
        if(newNode == par[node]) continue;
        
        par[newNode] = node;
        dfs(newNode);
        
        ll cost = best[newNode]-edges[node][i].s;
        if(cost > first){
            second = first;
            first = cost;
        } else if(cost > second){
            second = cost;
        }
    }
    
    ll total = first+second+buy[node];
    mx = max(mx, total);
    best[node] = first+buy[node];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    FOR(i, 1, N){
        cin >> buy[i];
    }
    F0R(i, N-1){
        int u, v, c;
        cin >> u >> v >> c;
        edges[u].pb(mp(v, c));
        edges[v].pb(mp(u, c));
    }
    
    dfs(1);
    
    cout << mx << "\n";
    
    return 0;
}