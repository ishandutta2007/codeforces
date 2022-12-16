// They can't break me, as long as I know who I am...

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn = 2e6 + 10, mod = 1e9 + 7;
const ll inf = 1e18;

vector<pii> v[maxn];
int n, SZ[maxn];

ll ans1, ans2;

void dfs(int u, int par = -1){
    SZ[u] = 1;
    for(pii p : v[u])
	if(p.F != par)
	    dfs(p.F, u), SZ[u] += SZ[p.F], ans2+= 1ll * min(SZ[p.F], n - SZ[p.F]) * p.S, ans1 += SZ[p.F] & 1 ? p.S : 0;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int q;
    cin >> q;
    while(q--){
	cin >> n;
	n*=2;
	for(int i = 1; i <= 2*n; i++){
	    v[i].clear();
	}	
	for(int i = 0; i < n-1; i++){
	    int a, b, c;
	    cin >> a >> b >> c;
	    v[a].PB({b, c});
	    v[b].PB({a, c});
	}
	ans1 = ans2 = 0;
	dfs(1);
	cout << ans1 << " " << ans2 << "\n";
    }
    return 0;
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")