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
typedef pair<pii, pii> pi4;

const int maxn = 1e5 + 10, mod = 998244353;
const ll inf = 1e18;

int a[maxn], v[maxn], p[maxn][2], ip[maxn][2], n;
vector< pair<pii, pii> > vec;

int val[4 * maxn][2][2];

int Pow(int a, int b){
    int ans = 1;
    for(; b; b>>=1, a = 1ll * a * a %mod)
	if(b&1)
	    ans = 1ll * ans * a %mod;
    return ans;
}
void mrg(int id, int mid){
    memset(val[id], 0, sizeof val[id]);
    for(int i = 0; i < 2; i++)
	for(int j = 0; j < 2; j++)
	    for(int k = 0; k < 2; k++)
		val[id][i][k] = ( 1ll * val[id][i][k] + 1ll * val[2*id][i][j] * val[2*id+1][j][k] %mod * ip[mid][j] ) %mod;
}
void build(int l = 0, int r = n-1, int id = 1){
    if(r-l == 1){
	for(int i = 0; i < 2; i++)
	    for(int j = 0; j < 2; j++)
		val[id][i][j] = 1ll * p[l][i] * p[r][j] %mod;
	return;
    }
    int mid = (l+r) >> 1;
    build(l, mid, 2*id);
    build(mid, r, 2*id+1);

    for(int a = 0; a < 2; a++)
	for(int b = 0; b < 2; b++)
	    for(int c = 0; c < 2; c++)
		for(int d = 0; d < 2; d++)
		    val[id][a][d] = ( 1ll * val[id][a][d] + 1ll * val[2*id][a][b] * val[2*id+1][c][d] ) %mod;
    mrg(id, mid);
}
void del(int pos, int a, int b, int l = 0, int r = n-1, int id = 1){
    if(r-l == 1){
	val[id][a][b] = 0;
	return;
    }
    int mid = (l+r) >> 1;
    if(pos < mid)
	del(pos, a, b, l, mid, 2*id);
    else
	del(pos, a, b, mid, r, 2*id+1);
    mrg(id, mid);
}
int _ask(){
    int ans = 0;
    for(int i = 0; i < 2; i++)
	for(int j = 0; j < 2; j++)
	    ans = (ans + val[1][i][j]) %mod;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int iv = Pow(100, mod-2);
    
    cin>>n;
    if(n==1)
	return cout<<0<<endl,0;
    for(int i=0; i<n; i++){
	cin>>a[i]>>v[i]>>p[i][0];
	p[i][0] = 1ll * p[i][0] * iv %mod;
	p[i][1] = 1 - p[i][0];

	ip[i][0] = Pow( p[i][0], mod - 2);
	ip[i][1] = Pow( p[i][1], mod - 2);
    }
    for(int i=0; i<n-1; i++){
	vec.PB({ {a[i+1] - a[i], v[i+1] + v[i]}, {i, 0} });
	if(v[i] != v[i+1])
	    vec.PB({ {a[i+1] - a[i], abs(v[i+1] - v[i])}, {i, 1} });
    }
    sort(vec.begin(), vec.end(), [](pi4 a, pi4 b){ return 1ll*a.F.F * b.F.S < 1ll * b.F.F * a.F.S; } );

    build();
    
    int ans = 0;
    for(auto it : vec){
	ans = ( 1ll * ans + 1ll * _ask() * it.F.F %mod * Pow(it.F.S, mod-2) ) %mod;
	if(it.S.S == 0){
	    del(it.S.F, 0, 1);	    
	}
	else{
	    if(v[ it.S.F ] < v[ it.S.F +1 ])
		del(it.S.F, 1, 1);
	    else
		del(it.S.F, 0, 0);
	}
	ans = ( 1ll * ans - 1ll * _ask() * it.F.F %mod * Pow(it.F.S, mod-2) ) %mod;
    }
    if(ans < 0)
	ans+= mod;
    return cout << ans << endl, 0;
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")