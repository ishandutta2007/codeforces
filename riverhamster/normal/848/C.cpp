#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <set>
#include <cassert>
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
const bool Modify = true, Query = false;
struct Op{
	bool type;
	int l, r, id;
	Op(){}
	Op(int _type, int _l, int _r, int _id):type(_type), l(_l), r(_r), id(_id){}
}q[N*7], tp[N*7]; // modify : l->pre r->pos id->delta query : id->queryid
// 6+-1
ll res[N];
int qc = 0, n;

ll tr[N];
void modify(int p, int v){for(; p<=n; p+=(p&-p)) tr[p] += v;}
ll query(int p){ll r=0; for(; p; p^=(p&-p)) r += tr[p]; return r;}
void solve(int l, int r){
	if(l == r) return ;
	int mid = (l + r) >> 1;
	solve(l, mid); solve(mid+1, r);
	int p1 = l, p2 = mid+1, pt = 0;
	while(p1 <= mid && p2 <= r){
		if(q[p1].l >= q[p2].l){
			if(q[p1].type == Modify) modify(q[p1].r, q[p1].id * (q[p1].r - q[p1].l));
			tp[pt++] = q[p1++];
		}
		else{
			if(q[p2].type == Query) res[q[p2].id] += query(q[p2].r);
			tp[pt++] = q[p2++];
		}
	}
	while(p2 <= r){
		if(q[p2].type == Query) res[q[p2].id] += query(q[p2].r);
		tp[pt++] = q[p2++];
	}
	for(int i=l; i<p1; i++) if(q[i].type == Modify) modify(q[i].r, -q[i].id * (q[i].r - q[i].l));
	while(p1 <= mid) tp[pt++] = q[p1++];
	copy(tp, tp+r-l+1, q+l);
	// for(int i=0; i<=r-l; i++) q[l+i] = tp[i];
}

set<int> app[N];
int a[N];
int main(){
	// File("3540");
	// setbuf(stdout, NULL);
	int m;
	gi(n); gi(m);
	static int last[N];
	for(int i=1; i<=n; i++){
		gi(a[i]);
		if(last[a[i]]) q[++qc] = Op(Modify, last[a[i]], i, 1);
		app[a[i]].insert(i); last[a[i]] = i;
	}
	int Queries = 0;
	for(int i=1; i<=m; i++){
		int op, x, y; gi(op); gi(x); gi(y);
		if(op == 2) q[++qc] = Op(Query, x, y, ++Queries);
		else{
			set<int>::iterator p = app[a[x]].find(x), L, R;
			L = p == app[a[x]].begin() ? app[a[x]].end() : prev(p);
			R = next(p);
			if(L != app[a[x]].end()) q[++qc] = Op(Modify, *L, *p, -1);
			if(R != app[a[x]].end()) q[++qc] = Op(Modify, *p, *R, -1);
			if(L != app[a[x]].end() && R != app[a[x]].end()) q[++qc] = Op(Modify, *L, *R, 1);
			app[a[x]].erase(p);
			a[x] = y; p = app[a[x]].insert(x).first;
			L = p == app[a[x]].begin() ? app[a[x]].end() : prev(p);
			R = next(p);
			if(L != app[a[x]].end()) q[++qc] = Op(Modify, *L, *p, 1);
			if(R != app[a[x]].end()) q[++qc] = Op(Modify, *p, *R, 1);
			if(L != app[a[x]].end() && R != app[a[x]].end()) q[++qc] = Op(Modify, *L, *R, -1);
		}
	}
	solve(1, qc);
	for(int i=1; i<=Queries; i++) printf("%lld\n", res[i]);
	return 0;
}