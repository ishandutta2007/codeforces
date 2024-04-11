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
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MAX_N 100005
int N, s;
vi edges[MAX_N];

/*int par[MAX_N];

void dfs(int node){
    F0R(i, edges[node]){
        int newNode = edges[node][i];
        if(newNode == par[node]) continue;

        dfs(newNode);
    }
}*/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> s;
    F0R(_, N-1){
        int u, v;
        cin >> u >> v;
        edges[u].pb(v);
        edges[v].pb(u);
    }

    int cnt = 0;
    FOR(i, 1, N){
        if(edges[i].size() == 1) cnt++;
    }

    cout << setprecision(8) << 2*s/(cnt+0.0);

    return 0;
}