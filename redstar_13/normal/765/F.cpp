#include<bits/stdc++.h>

#define inf 0x3f3f3f3f
#define pb push_back
#define sz(a) ((int)a.size())
#define x first
#define y second
#define bpt(x) (__builtin_popcount(x))
#define bit(x, y) (((x)>>(y))&1)
#define bclz(x) (__builtin_clz(x))
#define bctz(x) (__builtin_ctz(x))

using namespace std;

typedef double DO;
typedef long long INT;
typedef pair<int, int> pii;
typedef vector<int> VI;

template<typename T, typename U> inline void smin(T &a, U b) {if(a>b) a=b;}
template<typename T, typename U> inline void smax(T &a, U b) {if(a<b) a=b;}

template<class T>inline void gn(T &x) {char c, sg=0; while (c=getchar(), (c>'9' || c<'0') && c!='-');for((c=='-'?sg=1, c=getchar():0), x=0; c>='0' && c<='9'; c=getchar()) x=(x<<1)+(x<<3)+c-'0';if (sg) x=-x;}
template<class T>inline void print(T x) {if (x<0) {putchar('-');return print(-x);}if (x<10) {putchar('0'+x);return;} print(x/10);putchar(x%10+'0');}
template <class T> inline void println(T x) {print(x); putchar('\n');}

int power(int a, int b, int m, int ans=1) {
	for(; b; b>>=1, a=1LL*a*a%m) if(b&1) ans=1LL*ans*a%m;
	return ans;
}

#define NN 100011
int b[NN];
int n;
int *a[NN<<2];
int buf[NN*20], *cur=buf, *p;
int mn[NN<<2];
int now;

struct query{
	int l, r, id;
	void input(int i) {gn(l); gn(r); id=i;}
	bool operator < (const query &tmp) const {
		return r < tmp.r;
	}
} q[NN*3];

#define ls (u<<1)
#define rs (ls|1)
#define mid (st+ed>>1)

void build(int u, int st, int ed) {
	mn[u] = inf;
	if(ed-st==1) return ;
	a[u] = cur; cur+=ed-st;
	for(int i=st; i<ed; i++) a[u][i-st] = b[i];
	sort(a[u], a[u]+ed-st);
	build(ls, st, mid);
	build(rs, mid, ed);
}

inline bool meiyong(int *p, int &u, int &pos, int len) {
	if(p != a[u] and b[pos] < *(p-1)+now) return 0;
	if(p != a[u]+len and b[pos]+now>*p) return 0;
	return 1;
}

void update(int u, int st, int ed, int pos) {
	if(st>=pos) return ;
	if(ed == st+1) {
		smin(mn[u], abs(b[pos] - b[st]));
		smin(now, mn[u]);
		return ;
	}
	if(pos>=ed) {
		p=lower_bound(a[u], a[u]+ed-st, b[pos]);
		if(meiyong(p, u, pos, ed-st)) {
			smin(now, mn[u]);
			return ;
		}
	}
	if(mid<pos) update(rs, mid, ed, pos);
	update(ls, st, mid, pos);
	mn[u] = min(mn[ls], mn[rs]);
}

int calc(int u, int st, int ed, int l, int r) {
	smax(l, st); smin(r, ed);
	if(l >= r) return inf;
	if(l == st and r == ed) return mn[u];
	return min(calc(ls, st, mid, l, r), calc(rs, mid, ed, l, r ));
}

int ans[NN*3];

int solve() {
	cin >> n;
	for(int i=1; i<=n; i++) gn(b[i]);
	int m; cin >> m;
	for(int i=0; i<m; i++) q[i].input(i);
	sort(q, q+m);
	int pos=1;
	build(1, 1, n+1);
	for(int i=0; i<m; i++) {
		while(pos<=q[i].r) {
			now = inf;
			update(1, 1, n+1, pos);
			pos++;
		}
		ans[q[i].id] = calc(1, 1, n+1, q[i].l, q[i].r);
	}
	for(int i=0; i<m; i++) println(ans[i]);
}

int main() {
#ifndef	ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	solve();
	return 0;
}