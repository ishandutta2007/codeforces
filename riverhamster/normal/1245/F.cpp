#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
typedef long long ll;
template<typename T> inline void in(T &x){ //Read Positive Integer.
	char ch; x = 0;
	// int f = 1;
	while(isspace(ch = getchar()));
	// if(ch == '-') ch = getchar(), f = -1;
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
	// x *= f;
}

ll f[60][2][2];
int a[60], b[60];

ll dfs(int p, bool x, bool y){
	if(p == 32)
		return 1 + (int)(a[32] == 1 || x) + (int)(b[32] == 1 || y);
	ll &res = f[p][x][y];
	if(f[p][x][y] != -1) return f[p][x][y];
	res = 0;
	for(int i=0; i<2; i++)
		for(int j=0; j<2; j++){
			if(i == 1 && j == 1) continue;
			if(a[p] == 0 && !x && i == 1) continue;
			if(b[p] == 0 && !y && j == 1) continue;
			res += dfs(p+1, x || i < a[p], y || j < b[p]);
		}
	return res;
}

ll dp(ll x, ll y){
	// printf("dp %d %d\n", x, y);
	memset(a, 0, sizeof(a)); memset(b, 0, sizeof(b));
	for(int i=32; i>=0; i--){
		a[i] = x & 1;
		b[i] = y & 1;
		x >>= 1; y >>= 1;
	}
	memset(f, -1, sizeof(f));
	// printf("Return %lld\n", dfs(0, 0, 0));
	return dfs(0, 0, 0);
}

int main(){
	// File("f");
	int T;
	in(T);
	while(T--){
		ll l, r;
		in(l); in(r);
		if(l == 0) printf("%lld\n", dp(r, r));
		else printf("%lld\n", dp(r, r) - dp(l-1, r) * 2 + dp(l-1, l-1));
	}
	return 0;
}