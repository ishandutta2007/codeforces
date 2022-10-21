#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
typedef long long ll;
template<typename T> inline void in(T &x){ //Read Positive Integer.
	register char ch; x = 0;
	// register int f = 1;
	while(isspace(ch = getchar()));
	// if(ch == '-') ch = getchar(), f = -1;
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
	// x *= f;
}
const int N = 100005, E = 200005;
const ll mod = 1000000007;
int hd[N], to[E], nt[E], tot = 0;
bool vis[N];

ll qp(ll a, int b){
	ll ans = 1;
	while(b){
		if(b & 1) ans = (ans * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	return ans;
}
void addedge(int x, int y){
	++tot;
	to[tot] = y; nt[tot] = hd[x]; hd[x] = tot;
}

int dfs(int x){
	int ans = 1;
	for(int i=hd[x]; i; i=nt[i]){
		if(vis[to[i]]) continue;
		vis[to[i]] = true;
		ans += dfs(to[i]);
	}
	return ans;
}

int main(){
	// File("c");
	int n, k, x, y, type;
	in(n); in(k);
	ll ans = qp(n, k);
	for(int i=1; i<n; i++){
		in(x); in(y); in(type);
		if(type == 0) addedge(x, y), addedge(y, x);
	}
	for(int i=1; i<=n; i++)
		if(!vis[i]){
			vis[i] = true;
			ans = (ans + mod - qp(dfs(i), k)) % mod;
		}
	printf("%lld\n", ans);
	return 0;
}