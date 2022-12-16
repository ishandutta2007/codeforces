// Never let them see you bleed...
// Shayan.P  2020-06-11

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;
typedef pair<ll, ll> pll;

const int maxn = 2010, mod = 1e9 + 7, inf = 2e9 + 10;

int dp[maxn][maxn], MX[maxn], bst[maxn];
vector<pii> v[maxn];
map<ll, ll> cof;
ll ans;

ld calc(pll A, pll B){
    return ld(B.S - A.S) / ld(A.F - B.F);
}
bool bad(pll A, pll B, pll C){
    return calc(A, B) >= calc(B, C);
}
void Do(pll p, ll l, ll r){
    p.F%=mod, p.S%=mod;
    ans= (ans + (r-l+1) * p.S) % mod;
    ans= (ans + ((l + r) * (r-l+1) / 2) % mod * p.F) % mod;    
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    for(int i = 0; i < maxn; i++)
	dp[0][i] = -inf;
    dp[0][1] = 0;
    
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 0; i < m; i++){
	int a, b, c;
	cin >> a >> b >> c;
	v[a].PB({b, c});
	v[b].PB({a, c});
	MX[a] = max(MX[a], c);
	MX[b] = max(MX[b], c);
    }
    for(int i = 1; i <= n; i++){
	cof[MX[i]] = -inf;
    }
    cof[MX[1]] = 0;
    
    for(int i = 1; i < n; i++){
	for(int j = 1; j <= n; j++){
	    dp[i][j] = -inf;
	    for(pii p : v[j])
		dp[i][j] = max(dp[i][j], dp[i-1][p.F] + p.S);
	    if(dp[i][j] >= 0){
		cof[MX[j]] = max(cof[MX[j]], 1ll * dp[i][j] - 1ll * MX[j] * i);
		bst[i] = max(bst[i], dp[i][j]);
	    }
	}
	if(i <= q)
	    ans= (ans + bst[i]) % mod;
    }
    vector<pll> vec, vec2;
    for(pll p : cof){
	if(p.S != -inf)
	    vec.PB(p);
    }
    sort(vec.begin(), vec.end());
    for(pll p : vec){
	while(sz(vec2) >= 2 && bad(vec2[sz(vec2)-2], vec2.back(), p))
	    vec2.pop_back();
	vec2.PB(p);
    }
    ll lst = n;
    for(int i = 0; i < sz(vec2)-1; i++){
	ll lstx = calc(vec2[i], vec2[i+1]);
	lstx = min(lstx, ll(q));
	if(lst <= lstx)
	    Do(vec2[i], lst, lstx);
	lst = max(lst, lstx+1);
    }
    if(lst <= q)
	Do(vec2.back(), lst, q);
    if(ans < 0)
	ans+= mod;
    return cout << ans << endl, 0;
}