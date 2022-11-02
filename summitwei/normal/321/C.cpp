#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
#define INF 0x3f3f3f3f
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
#define MD 20
int n;
vi e[MN];

int ans[MN];

int sz[MN][MD];
void dfs(int cn, int d){
    sz[cn][d] = 1;
    F0R(i, e[cn].size()){
        int nn = e[cn][i];
        
        if(sz[nn][d] != 0 || ans[nn] != -1) continue;
        dfs(nn, d);
        sz[cn][d] += sz[nn][d];
    }
}

int fc(int cn, int d, int tot){ //tot = total number of nodes
    F0R(i, e[cn].size()){
        int nn = e[cn][i];
        
        if(ans[nn] != -1) continue;
        if(sz[cn][d] > sz[nn][d] && sz[nn][d] > tot/2){
            return fc(nn, d, tot);
        }
    }
    
    return cn;
}

void cd(int sn, int d){
    //cout << "doing cd " << sn << " " << d << "\n";
    dfs(sn, d);
    int cent = fc(sn, d, sz[sn][d]);

    ans[cent] = d;
    F0R(i, e[cent].size()){
        int nn = e[cent][i];
        if(ans[nn] != -1) continue;
        cd(nn, d+1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    memset(ans, -1, sizeof ans);
    
    cin >> n;
    F0R(_, n-1){
        int u, v;
        cin >> u >> v;
        e[u].pb(v);
        e[v].pb(u);
    }
    
    cd(1, 0);
    FOR(i, 1, n){
        cout << (char)('A'+ans[i]) << " ";
    }
    
    return 0;
}