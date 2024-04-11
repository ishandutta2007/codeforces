#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
typedef long long ll;
namespace io {
	const int SIZE = (1 << 21) + 1;
	char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55]; int f, qr;
	#define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
	inline void flush () {fwrite (obuf, 1, oS - obuf, stdout); oS = obuf;}
	inline void putc (char x) {*oS ++ = x; if (oS == oT) flush ();}
	template <class I> inline void gi (I &x) {for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;}
	template <class I> inline void print (I x) {if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;while (x) qu[++ qr] = x % 10 + '0',  x /= 10;while (qr) putc (qu[qr --]);}
	struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
}
using io :: gi; using io :: putc; using io :: print;

struct Edge{
	int v;
	ll w;
	Edge(){}
	Edge(int _v, ll _w):v(_v), w(_w){}
};
const int N = 500005;
vector<Edge> G[N];
ll f[N], g[N];
int n, k;
bool cmp(Edge a, Edge b){
	return (g[a.v] + a.w - f[a.v]) > (g[b.v] + b.w - f[b.v]);
}

void dfs(int x, int fa){
	f[x] = g[x] = 0;
	for(auto e : G[x]){
		if(e.v == fa) continue;
		dfs(e.v, x);
	}
	sort(G[x].begin(), G[x].end(), cmp);
	int cnt = 0;
	for(auto e : G[x]){
		if(e.v == fa) continue;
		if(cnt < k && g[e.v] + e.w > f[e.v]) f[x] += g[e.v] + e.w;
		else f[x] += f[e.v];
		if(cnt < k-1 && g[e.v] + e.w > f[e.v]) g[x] += g[e.v] + e.w;
		else g[x] += f[e.v];
		++cnt;
	}
	// printf("f[%d] = %lld g[%d] = %lld\n", x, f[x], x, g[x]);
}

int main(){
	// File("c");
	int T;
	gi(T);
	while(T--){
		gi(n); gi(k);
		for(int i=1; i<=n; i++) G[i].clear();
		for(int i=1, x, y; i<n; i++){
			ll w;
			gi(x); gi(y); gi(w);
			G[x].emplace_back(y, w); G[y].emplace_back(x, w);
		}
		dfs(1, 0);
		printf("%lld\n", f[1]);
	}
	return 0;
}