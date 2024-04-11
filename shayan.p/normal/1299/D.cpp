// So when you feel like hope is gone, Look inside you and be strong, And you'll finally see the truth, That a hero lies in you ... 
 
#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)
#define bit5(n,k) (((n)>>(5*k))&31)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn = 1e5, Max = 1500, mod = 1e9 + 7;
const ll inf = 1e18;

template<typename A, typename B> ostream& operator << (ostream& out, pair<A, B> p){
    out << "{ " << p.F << ", " << p.S <<" }";
    return out;
}
template<typename T> ostream& operator << (ostream& out, vector<T> v){
    out << "[ ";
    for(int i = 0; i < sz(v); i++){
	out << v[i];
	if(i != sz(v)-1)
	    out << " ,";
    }
    out << " ]";
    return out;
}

int to[Max][Max];
map<int, int> mp;

bool add(int &a, int msk){
    for(int i = 0; i < 5; i++){
	if(bit(msk, i))
	    msk^= bit5(a, i);
    }
    if(msk == 0)
	return 0;
    int id = __builtin_ctz(msk);
    for(int i = 0; i < 5; i++)
	if(bit(msk, i))	    
	    a|= 1<<(5*id + i);
    for(int i = 0; i < 5; i++){
	if(i == id)
	    continue;
	if(bit( bit5(a, i), id )){
	    for(int j = 0; j < 5; j++)
		a^= bit(msk, j) << (5 * i + j);
	}	    
    }
    return 1;
}
int f(int a, int b){
    for(int i = 0; i < 5; i++){
	if(bit5(a, i) != 0)
	    if( !add(b, bit5(a, i)) )
		return -1;	
    }
    return b;
}

int xr[maxn], col[maxn], h[maxn], Cl;
int grd[maxn];
bool bad[maxn];
vector<pii> extr[maxn];
vector<pii> v[maxn];

void dfs(int u, int par = 1){
    col[u] = Cl;
    h[u] = h[par] + 1;
    for(pii p : v[u]){
	if(col[p.F] == 0){
	    xr[p.F] = xr[u] ^ p.S;
	    dfs(p.F, u);
	}
	else if(h[p.F] < h[u]){
	    if(p.F == 1)
		extr[Cl].PB({u, p.S});
	    else if(par != p.F)
		bad[Cl]|= !add(grd[Cl], xr[u] ^ xr[p.F] ^ p.S);
	}
    }
}

int dp[Max];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int C = 0;
    
    for(int msk = 0; msk < (1<<25); msk++){
	int MSK = 0;
	for(int i = 0; i < 5; i++){
	    if(bit5(msk, i) != 0 && bit(msk, 5*i + i) == 0)
		goto Hell;
	    if(bit(msk, 5*i + i))
		MSK|= 1<<i;	    
	}
	for(int i = 0; i < 5; i++){
	    if(__builtin_popcount(bit5(msk, i) & MSK) >1)
		goto Hell;	    
	}
	mp[msk] = C++;
    Hell:;
    }
    for(auto x : mp){
	for(auto y : mp){
	    int num = f(x.F, y.F);
	    if(num == -1)
		to[x.S][y.S] = -1;
	    else
		to[x.S][y.S] = mp[num];
	}
    }

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
	int a, b, c;
	cin >> a >> b >> c;
	v[a].PB({b, c});
	v[b].PB({a, c});
    }
    
    xr[1] = 0;
    col[1] = -1;
    for(auto p : v[1]){
	if(col[p.F] == 0){
	    xr[p.F] = p.S;
	    Cl++;
	    dfs(p.F);
	}
    }
    dp[0] = 1;
    for(int i = 1; i <= Cl; i++){
	int id = mp[ grd[i] ];
	if(bad[i])
	    continue;
	vector<pii> tdo;
	if(sz(extr[i]) == 1){
	    for(int j = 0; j < sz(mp); j++){
		if(to[j][id] != -1 && dp[j] != 0)
		    tdo.PB( {to[j][id], dp[j]} );
	    }
	}
	else{
	    for(int j = 0; j < sz(mp); j++)
		if(to[j][id] != -1 && dp[j] != 0)
		    tdo.PB( {to[j][id], 2ll * dp[j] %mod} );
	    int msk = 0;
	    add(msk, xr[ extr[i][0].F ] ^ xr[ extr[i][1].F ] ^ extr[i][0].S ^ extr[i][1].S);
	    int x = to[id][ mp[msk] ];
	    if(x != -1 && msk != 0)
		for(int j = 0; j < sz(mp); j++)
		    if(to[j][x] != -1)
			tdo.PB( {to[j][x], dp[j]} );	    
	}
	for(auto x : tdo)
	    dp[x.F] = (dp[x.F] + x.S) %mod;
    }
    int ans = 0;
    for(int i = 0; i < sz(mp); i++)
	ans = (ans + dp[i]) %mod;
    return cout << ans << endl, 0;
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")