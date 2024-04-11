//Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 500005 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

using namespace std;
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
int dep[maxn], dfn[maxn], sz[maxn];
int fa[maxn][20];

const int S = maxn * 2;
int id[maxn], scnt = 0; 
int xx[S];
int lg2[S];
int st[20][S];

inline char nc() {
	static char buf[100000],*p1,*p2;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
int red() {
	int x=0; char s=nc();
	while(s<'0'||s>'9') s=nc();
	while(s>='0'&&s<='9') x=((x+(x<<2))<<1)+s-'0',s=nc();
	return x;
}
int rc() {
	char s=nc();
	while(s!='C'&&s!='R'&&s!='Q') s=nc();
	return s;
}
void initlca() {
	for(int i = 0; i < 20; i++)
		for(int j = 1; j <= scnt + 1 - (1 << i); j++)
		{
			if(!i) st[i][j] = xx[j];
			else st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
		}
	for(int i = 0; i < 20; i++)
		for(int j = (1 << i); j <= scnt && j < (1 << (i + 1)); j++)
			lg2[j] = i;
}
int qmin(int a, int b)
{
	int l = b - a + 1;
	int bs = lg2[l];
	int ans = min(st[bs][a], st[bs][b - (1 << bs) + 1]);
	return ans;
}
int dis(int a, int b) {
	if (id[a] > id[b]) swap(id[a], id[b]);
	return dep[a] + dep[b] - 2 * qmin(id[a], id[b]);
}
struct lk {
	int u[2], len;
	lk(){u[0] = u[1] = -1, len = -1e9;}
	lk uni(lk h) {
		int nl = -1e9;
		int s[2] = {-1, -1};
		if (chkmax(nl, len)) s[0] = u[0], s[1] = u[1];
		if (chkmax(nl, h.len)) s[0] = h.u[0], s[1] = h.u[1];
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++) {
				if (u[i] == -1 || h.u[j] == -1) continue;
				if (u[0] == u[1] && i == 1) continue;
				if (h.u[0] == h.u[1] && j == 1) continue;
				int hl = dis(u[i], h.u[j]);
				if (chkmax(nl, hl))
					s[0] = u[i], s[1] = h.u[j];
			}
		lk cur;
		cur.len = nl;
		cur.u[0] = s[0], cur.u[1] = s[1];
		return cur;
	}
};
void otp(lk s) {
	cout << s.len << ' ' << s.u[0] << ' ' << s.u[1] << endl;
}
struct ST {
	ST *ch[2];
	lk h[2];
	int l, r, lz;
}p[maxn << 1], *root;
int col[maxn];
void upd(ST *a) {
	for (int i = 0; i < 2; i++)
		a->h[i] = a->ch[0]->h[i].uni(a->ch[1]->h[i]);
}
int tr[maxn];
int stcnt = 0;
void bdtree(ST *a, int l, int r) {
	a->l = l, a->r = r, a->lz = 0;
	if (l == r) {
		int id = col[tr[l]];
		a->h[id].u[0] = a->h[id].u[1] = tr[l], a->h[id].len = 0;
		return ;
	}
	int mid = (l + r) >> 1;
	a->ch[0] = &p[stcnt++], a->ch[1] = &p[stcnt++];
	bdtree(a->ch[0], l, mid), 
	bdtree(a->ch[1], mid + 1, r);
	upd(a);
}
void actlz(ST *a) {
	a->lz ^= 1;
	swap(a->h[0], a->h[1]);
}
void pushdown(ST *a) {
	if (a->lz) {
		a->lz = 0;
		for (int i = 0; i < 2; i++)
			actlz(a->ch[i]);
	}
}
void push(ST *a, int l, int r) {
	if (a->l == l && a->r == r) {
		actlz(a);
		return ;
	}
	pushdown(a);
	int mid = (a->l + a->r) >> 1;
	if (r <= mid) push(a->ch[0], l, r);
	else if (l > mid) push(a->ch[1], l, r);
	else push(a->ch[0], l, mid), push(a->ch[1], mid + 1, r);
	upd(a);
}
vector<pi> eg[maxn];
int ur[maxn][2];
int dfcnt = 0;
void dfs(int a) {
	xx[++scnt] = dep[a];
	id[a] = scnt;
	dfn[a] = ++dfcnt;
	tr[dfn[a]] = a;
	sz[a] = 1;
	for (auto s : eg[a]) {
		int v = s.fi;
		if (v == fa[a][0]) continue;
		col[v] = col[a] ^ s.se;
		fa[v][0] = a;
		for (int i = 1; i < 20; i++)
			fa[v][i] = fa[fa[v][i - 1]][i - 1];
		dep[v] = dep[a] + 1;
		dfs(v);
		sz[a] += sz[v];
		xx[++scnt] = dep[a];
	}
}
int main() {
	int n = red();
	for (int i = 1; i < n; i++) {
		int u, v, w;
		u = red(), v = red(), w = red();
		ur[i][0] = u, ur[i][1] = v;
		eg[u].pb(mp(v, w)), eg[v].pb(mp(u, w));
	}
	dep[1] = 1;
	dfs(1);
	initlca();
	for (int i = 1; i < n; i++)
		if (dep[ur[i][0]] < dep[ur[i][1]])
			swap(ur[i][0], ur[i][1]);
	int m;
	m = red();
	root = &p[stcnt++];
	bdtree(root, 1, n);
	for (int i = 1; i <= m; i++) {
		int x;
		x = red();
		x = ur[x][0];
		push(root, dfn[x], dfn[x] + sz[x] - 1);
		printf("%d\n", max(root->h[0].len, root->h[1].len));
	//	otp(root->h[0]), otp(root->h[1]);
	}
	return 0;
}