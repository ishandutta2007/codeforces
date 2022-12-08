#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 6e5 + 5;
int n, a[N], m;
int head[N], tot;
int st1[N], tp1, st2[N], tp2, st[N], tp, id[N], cnt, L[N], R[N], M[N], typ[N], rt, son[N];

void add(int u, int v) { son[u]++; }

namespace RMQ {
	int lg[N];
	struct Node {
		int mn, mx;
		Node(int x = 0, int y = 0) { mn = x, mx = y; }
		Node operator +(Node b) const { return Node(min(mn, b.mn), max(mx, b.mx)); }
	} t[N][20];
	void init() {
		lg[0] = -1; for(int i = 1; i <= n; i++) lg[i] = lg[i >> 1] + 1, t[i][0] = Node(a[i], a[i]);
		for(int j = 1; j <= 19; j++)
			for(int i = 1; i + (1 << j) - 1 <= n; i++)
				t[i][j] = t[i][j - 1] + t[i + (1 << j - 1)][j - 1];
	}
	Node ask(int l, int r) {
		int len = lg[r - l + 1];
		return t[l][len] + t[r - (1 << len) + 1][len];
	}
}

namespace SMT {
	#define lc (u << 1)
	#define rc (u << 1 | 1)
	#define mid (l + r >> 1)
	int mx[N << 2], tag[N << 2];
	void pushup(int u) { mx[u] = min(mx[lc], mx[rc]); }
	void pusha(int u, int v) { mx[u] += v, tag[u] += v; }
	void pushdown(int u) { if(tag[u]) pusha(lc, tag[u]), pusha(rc, tag[u]), tag[u] = 0; }
	void update(int u, int l, int r, int a, int b, int v) {
		if(a == l && r == b) return pusha(u, v);
		pushdown(u);
		if(b <= mid) update(lc, l, mid, a, b, v);
		else if(a > mid) update(rc, mid + 1, r, a, b, v);
		else update(lc, l, mid, a, mid, v), update(rc, mid + 1, r, mid + 1, b, v);
		pushup(u);
	}
	int query(int u, int l, int r) {
		if(l == r) return l;
		pushdown(u);
		if(!mx[lc]) return query(lc, l, mid);
		else return query(rc, mid + 1, r);
	}
}

int judge(int l, int r) { return (RMQ::ask(l, r).mx - RMQ::ask(l, r).mn == r - l); }

void build() {
	for(int i = 1; i <= n; i++) {
		while(tp1 && a[i] <= a[st1[tp1]]) SMT::update(1, 1, n, st1[tp1 - 1] + 1, st1[tp1], a[st1[tp1]]), tp1--;
		while(tp2 && a[i] >= a[st2[tp2]]) SMT::update(1, 1, n, st2[tp2 - 1] + 1, st2[tp2], -a[st2[tp2]]), tp2--;
		SMT::update(1, 1, n, st1[tp1] + 1, i, -a[i]), st1[++tp1] = i;
		SMT::update(1, 1, n, st2[tp2] + 1, i, a[i]), st2[++tp2] = i;
		id[i] = ++cnt, L[cnt] = R[cnt] = i;
		int lst = SMT::query(1, 1, n), now = cnt;
		while(tp && L[st[tp]] >= lst) {
			if(typ[st[tp]] && judge(M[st[tp]], i)) R[st[tp]] = i, add(st[tp], now), now = st[tp--];
			else if(judge(L[st[tp]], i)) typ[++cnt] = i, L[cnt] = L[st[tp]], R[cnt] = i, M[cnt] = L[now], add(cnt, st[tp--]), add(cnt, now), now = cnt;
			else {
				add(++cnt, now);
				do {
					add(cnt, st[tp--]);
				} while(tp && !judge(L[st[tp]], i));
				L[cnt] = L[st[tp]], R[cnt] = i, add(cnt, st[tp--]), now = cnt;
			}
		}
		st[++tp] = now, SMT::update(1, 1, n, 1, i, -1);
	}
	rt = st[tp];
}

int main() {
	n = get();
	for(int i = 1; i <= n; i++) a[get()] = get();
	RMQ::init(), build();
	long long ans = 0;
	for(int i = 1; i <= cnt; i++) if(!typ[i]) ans++; else ans += 1ll * son[i] * (son[i] - 1) / 2;
	printf("%lld\n", ans);
	return 0;
}