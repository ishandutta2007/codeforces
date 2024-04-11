// So when you feel like hope is gone, Look inside you and be strong, And you'll finally see the truth, That a hero lies in you ... 
 
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

const int maxn = 1e5 + 10, mod = 1e9 + 7;
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

int M;
vector<pii> v[maxn];
bool mark[maxn];
int SZ[maxn];

int pw[maxn], ipw[maxn];
map<int, int> mp;

ll ANS;

void dfs1(int u, int hsh, int par, int h = 1){
    hsh%=M;
    mp[hsh]++;
    for(auto [y, c] : v[u])
	if(y != par && mark[y] == 0)
	    dfs1(y, (1ll * hsh + 1ll * c * pw[h]) % M, u, h+1);
}
void dfs2(int u, int hsh, int par, int h = 1){
    hsh%=M;
    int num = 1ll * (M-1) * hsh % M * ipw[h] % M;
    if(mp.count(num))
	ANS+=mp[num];
    for(auto [y, c] : v[u])
	if(y != par && mark[y] == 0)
	    dfs2(y, (1ll * hsh * 10 + c) % M, u, h + 1);
}
void dfsSz(int u, int par = -1){
    SZ[u] = 1;
    for(auto [y,c] : v[u])
	if(y != par && mark[y] == 0)
	    dfsSz(y, u), SZ[u]+= SZ[y];
}
int center(int u, int N, int par = -1){
    for(auto [y,c] : v[u])
	if(y != par && mark[y] == 0 && SZ[y] > N)
	    return center(y, N, u);
    return u;
}
void solve(int u){
    dfsSz(u);
    u = center(u, SZ[u]/2);
    mp.clear();
    mp[0]++;
    for(auto [y,c] : v[u])
	if(mark[y] == 0)
	    dfs2(y, c, u), dfs1(y, c, u);
    mp.clear();
    reverse(v[u].begin(), v[u].end());
    for(auto [y,c] : v[u])
	if(mark[y] == 0)
	    dfs2(y, c, u), dfs1(y, c, u);
    ANS+= mp[0];
    mark[u] = 1;
    for(auto [y, c] : v[u])
	if(mark[y] == 0)
	    solve(y);
}

int Pow(int a, int b){
    int ans = 1;
    for(; b; b >>= 1, a = 1ll * a * a % M)
	if(b&1)
	    ans = 1ll * ans * a %M;
    return ans;
}
int phi(int n){
    if(n == 1)
	return 1;
    int ans = 1;
    for(int p = 2; p*p <= n; p++){
	if(n % p == 0){
	    n/=p;
	    while(n % p == 0)
		n/=p, ans*=p;
	    ans*= p-1;
	}
    }
    if(n > 1)
	ans*= n-1;
    return ans;
}
int inv(int x){
    return Pow(x, phi(M)-1);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();
    
    int n;
    cin >> n >> M;
    pw[0] = ipw[0] = 1;
    pw[1] = 10, ipw[1] = inv(10);
    for(int i = 1; i < maxn; i++)
	pw[i] = 1ll * pw[1] * pw[i-1] % M, ipw[i] = 1ll * ipw[1] * ipw[i-1] % M;
    for(int i = 0; i < n-1; i++){
	int a, b, c;
	cin >> a >> b >> c;
	v[a].PB({b, c});
	v[b].PB({a, c});
    }
    solve(0);
    return cout<<ANS << endl, 0;
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")