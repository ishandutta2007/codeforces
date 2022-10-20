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
	char getc () {return gc();}
	inline void flush () {fwrite (obuf, 1, oS - obuf, stdout); oS = obuf;}
	inline void putc (char x) {*oS ++ = x; if (oS == oT) flush ();}
	template <class I> inline void gi (I &x) {for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;}
	template <class I> inline void print (I x) {if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;while (x) qu[++ qr] = x % 10 + '0',  x /= 10;while (qr) putc (qu[qr --]);}
	struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
}
using io :: gi; using io :: putc; using io :: print; using io :: getc;
template<class T> void upmax(T &x, T y){x = x>y ? x : y;}
template<class T> void upmin(T &x, T y){x = x<y ? x : y;}

const int N = 1000005;
vector<int> G[N];
int len[N], son[N], res[N];
int tp[N], *p = tp, *f[N];

void build(int x, int fa){
	for(int v : G[x]){
		if(v == fa) continue;
		build(v, x);
		if(len[v] > len[son[x]]) son[x] = v;
	}
	len[x] = len[son[x]] + 1;
}
void dfs(int x, int fa){
	f[x][0] = 1;
	if(!son[x]){
		res[x] = 0;
		return ;
	}
	f[son[x]] = f[x] + 1;
	dfs(son[x], x);
	res[x] = res[son[x]] + 1;
	for(int v : G[x]){
		if(v == fa || v == son[x]) continue;
		f[v] = p; p += len[v];
		dfs(v, x);
		for(int i=0; i<len[v]; i++){
			f[x][i+1] += f[v][i];
			if(f[x][i+1] > f[x][res[x]] || (f[x][i+1] == f[x][res[x]] && i + 1 < res[x])) res[x] = i + 1;
		}
	}
	if(f[x][res[x]] == 1) res[x] = 0;
}

int main(){
	// File("cf1009f");
	int n;
	gi(n);
	for(int i=1, u, v; i<n; i++) gi(u), gi(v), G[u].push_back(v), G[v].push_back(u);
	build(1, 1);
	f[1] = p; p += len[1];
	dfs(1, 1);
	for(int i=1; i<=n; i++) printf("%d ", res[i]);
	putchar('\n');
	return 0;
}