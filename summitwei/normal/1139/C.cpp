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

#define MN 100005
int n, k;
int ccs[MN];
int ccc;
int sz[MN];
vi e[MN];

void dfs(int cn){
    if(ccs[cn] != 0) return;
    ccs[cn] = ccc;
    sz[ccc]++;

    F0R(i, e[cn].size()){
        int nn = e[cn][i];

        dfs(nn);
    }
}

ll modExp(ll b, ll ex){
    ll prod = 1;
    while(ex > 0){
        if(ex % 2 == 0){
            b = (b * b) % MOD;
            ex /= 2;
        } else{
            prod = (prod*b) % MOD;
            ex--;
        }
    }
    
    return prod;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;

    F0R(_, n-1){
        int u, v, x;
        cin >> u >> v >> x;
        if(x == 0){
            e[u].pb(v);
            e[v].pb(u);
        }
    }

    ll ans = modExp(n, k);
    FOR(i, 1, n){
        if(ccs[i] == 0){
            ccc++;
            dfs(i);
            ans -= modExp(sz[ccc], k);
            ans = (ans+MOD)%MOD;
        }
    }

    cout << ans << "\n";
    
    return 0;
}