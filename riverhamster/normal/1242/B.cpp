#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_set>
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
const int N = 100005;
unordered_set<int> G[N];
bool vis[N];
int fa[N];
int find(int x){
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
void merge(int x, int y){
	int fx = find(x), fy = find(y);
	if(fx != fy) fa[fx] = fy;
}

void dfs(int x){
	vis[x] = true; merge(x, x+1);
	for(int i=find(1); i; i=find(i)){
		if(G[x].count(i)){
			i = find(i+1);
			continue;
		}
		dfs(i);
	}
}

int main(){
	// File("cf1242b");
	int n, m, x, y;
	gi(n); gi(m);
	for(int i=1; i<=m; i++){
		gi(x); gi(y);
		G[x].insert(y); G[y].insert(x);
	}
	int res = -1;
	for(int i=1; i<=n; i++) fa[i] = i;
	for(int i=1; i<=n; i++){
		if(!vis[i]){
			dfs(i);
			++res;
		}
	}
	printf("%d\n", res);
	return 0;
}