#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cassert>
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
const int N = 5005, V = 5000;
bool np[N];
int p[N], pid[N], minFac[N], pc = 0;

void pre(){
	np[0] = np[1] = true;
	for(int i=2; i<=V; i++){
		if(!np[i]) p[++pc] = i, pid[i] = pc;
		for(int j=1; j<=pc && i * p[j] <= V; j++){
			np[i * p[j]] = true;
			minFac[i * p[j]] = p[j];
			if(i % p[j] == 0) break;
		}
	}
}

int fa[N * 2], len[N * 2], cnt[N];
int tr[N], sz[N*2];
void modify(int p){
	// printf("Modify %d\n", p);
	p = pc - p + 1;
	// assert(p > 0 && p <= pc);
	for(; p<=pc; p += p & -p) ++tr[p];
}
int query(int p){
	p = pc - p + 1;
	int res = 0;
	for(; p; p ^= (p & -p)) res += tr[p];
	return res;
}

struct Edge{
	int v, w;
	Edge(){}
	Edge(int _v, int _w) : v(_v), w(_w) {}
};
vector<Edge> G[N*2];

int nc = 1;
ll res = 0;
int Node[N], Sum[N];

int getDepth(int x){
	int res = 0;
	while(x != 1) res += len[x], x = fa[x];
	return res;
}

void build(){
	nc = 1; sz[nc] = cnt[1] + cnt[0];
	int facSum = 0;
	for(int i=2; i<=V; i++){
		if(!np[i]){
			int now = ++nc;
			fa[now] = 1; len[now] = ++facSum;
			sz[now] = cnt[i];
			modify(pid[i]);
			res += 1LL * facSum * cnt[i];
			continue;
		}
		int v = i, facCnt = 0;
		while(np[v]) v /= minFac[v], ++facCnt;
		++facCnt;
		int com = query(pid[v]), diff = facSum - com;
		int x = nc;
		while(diff >= len[x])
			diff -= len[x], x = fa[x];
		if(diff == 0){
			int now = ++nc;
			fa[now] = x;
			facSum += facCnt; len[now] = facSum - com;
			sz[now] = cnt[i];
		}
		else{
			int p = ++nc;
			fa[p] = fa[x]; len[p] = len[x] - diff;
			fa[x] = p; len[x] = diff;
			int now = ++nc;
			fa[now] = p;
			facSum += facCnt; len[now] = facSum - com;
			sz[now] = cnt[i];
		}
		v = i;
		while(np[v]) modify(pid[minFac[v]]), v /= minFac[v];
		modify(pid[v]);
		res += 1LL * facSum * cnt[i];
	}
}

void dfs(int x, int fa){
	for(const Edge &e : G[x]){
		if(e.v == fa) continue;
		dfs(e.v, x);
		sz[x] += sz[e.v];
	}
}

int main(){
	// File("cf1292d");
	int n;
	gi(n);
	for(int i=1, x; i<=n; i++) gi(x), ++cnt[x];
	pre();
	build();
	for(int i=nc; i>=2; i--) G[fa[i]].emplace_back(i, len[i]);
	dfs(1, 1);
	int p = 1;
	bool flag = true;
	while(flag){
		flag = false;
		for(const Edge &e : G[p]){
			if(sz[e.v] > (n >> 1)){
				res -= 1LL * e.w * ((sz[e.v] << 1) - n);
				p = e.v;
				flag = true;
				break;
			}
		}
	}
	printf("%lld\n", res);
	return 0;
}