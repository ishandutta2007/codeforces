#include <bits/stdc++.h>

#define mid (L+R>>1)

using namespace std;
typedef long long INT;

int E;
const int MM = 100010, NN = MM*5;
const int MOD = 1000000007, mod = 31;

int to[MM<<1], nxt[MM<<1], head[MM], Len[MM];
int len[MM], root[MM];

void add_edge(int u, int v) {
	to[++E]=v; nxt[E]=head[u]; head[u]=E;
	to[++E]=u; nxt[E]=head[v]; head[v]=E;
}

int cur, p[NN];
int val[NN*70], ls[NN*70], rs[NN*70];

int newnode(int v=0) {
	val[cur]=v;
	return cur++;
}

int push_up(int u, int L, int R) {
	val[u]=((INT)val[ls[u]]*p[R-mid]+val[rs[u]])%MOD;
}

int build(int L, int R, int k) {
	if (L+1==R) return newnode(k);
	int u = newnode();
	ls[u]=build(L, mid, k);
	rs[u]=build(mid, R, k);
	push_up(u, L, R);
	return u;
}

int comp(int u, int v, int L, int R) {
	if (val[u]==val[v]) return 0;
	if (L+1==R) return val[u]-val[v];
	if (val[ls[u]]!=val[ls[v]]) return comp(ls[u], ls[v], L, mid);
	return comp(rs[u], rs[v], mid, R);
}

struct cmp {
	bool operator () (const int &u, const int &v) {
		if (len[u]!=len[v]) return len[u]<len[v];
		int t=comp(root[u], root[v], 0, NN);
		if (t) return t<0;
		return u<v;
	}
};

int update(int u, int L, int R, int x, int y) {
	if (x<L || R<=x) return u;
	int now = newnode(val[u]);
	ls[now]=ls[u]; rs[now]=rs[u];
	if (L+1==R) return val[now]=y, now;
	ls[now]=update(ls[u], L, mid, x, y);
	rs[now]=update(rs[u], mid, R, x, y);
	push_up(now, L, R);
	return now;
	
}

int a[33];
int get(int u, int x) {
	int nn=0;
	while (x) a[nn++]=x%10, x/=10;
	int t = root[u];
	for (int i=0; i<nn; i++) t = update(t, 0, NN, len[u]+i, a[nn-1-i]);
	return t;
}

int tmp = 0;
void calc(int u, int L, int R, int m) {
	if (L>=m) return ;
	if (R<=m) {
		tmp = ((INT)tmp*p[R-L]+val[u])%MOD;
		return ;
	}
	calc(ls[u], L, mid, m);
	calc(rs[u], mid, R, m);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif

	int n, m, u, v;
	for (int i=p[0]=1; i<NN; i++) p[i]=p[i-1]*10LL%MOD;
	cin>>n>>m; E = 1;
	for (int i=0; i<m; i++) scanf("%d%d", &u, &v), add_edge(u, v);
	for (int i=1; i<10; i++) Len[i]=1;
	for (int i=10; i<100; i++) Len[i]=2;
	for (int i=100; i<1000; i++) Len[i]=3;
	for (int i=1000; i<10000; i++) Len[i]=4;
	for (int i=10000; i<100000; i++) Len[i]=5;
	Len[100000]=6;

	root[1]=build(0, NN, 0);
	root[0]=build(0, NN, 9);

	set<int, cmp> st;
	for (int i=2; i<=n; i++) root[i]=root[0], len[i]=NN;
	for (int i=1; i<=n; i++) st.insert(i);

	for (int i=1; i<=n; i++) {
		int u=*st.begin(); st.erase(st.begin());
		for (int e = head[u]; e; e=nxt[e]) {
			int v = to[e];
			root[n+1] = get(u, e>>1);
			len[n+1] = len[u]+Len[e>>1];
			if (cmp()(n+1, v)) {
				st.erase(v);
				len[v]=len[n+1];
				root[v]=root[n+1];
				st.insert(v);
			}
		}
	}

	for (int i=2; i<=n; i++) {
		tmp = 0;
		calc(root[i], 0, NN, len[i]);
		printf("%d\n", tmp);
	}

	return 0;
}