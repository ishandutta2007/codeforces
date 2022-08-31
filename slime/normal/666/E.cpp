#include <bits/stdc++.h>
#define ll long long
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
struct ST {
	int l, r;
	ST *ch[2];
	pi mx; //  
}stp[20000005], *r[1300005];
int stcnt = 0;
void upd(ST *a) {
	a->mx = mp(0, -a->l);
	for (int i = 0; i < 2; i++)
		if (a->ch[i]) a->mx = max(a->mx, a->ch[i]->mx);
}
void copy(ST *a, ST *b, int l, int r) {
	a->l = l, a->r = r, a->mx = mp(0, -l);
	if (b) a->mx = b->mx, a->ch[0] = b->ch[0], a->ch[1] = b->ch[1];
}
void cha(ST *a, int pl) {
	// pl ++
	if (a->l == a->r) {
		a->mx.fi++;
		return ;
	}
	int mid = (a->l + a->r) >> 1; 
	ST *n1 = &stp[stcnt++];
	if (pl <= mid) copy(n1, a->ch[0], a->l, mid), a->ch[0] = n1;
	else copy(n1, a->ch[1], mid + 1, a->r), a->ch[1] = n1;
	cha(n1, pl);
	upd(a);
}
ST *merge(ST *a, ST *b) {
	if (!a) return b;
	if (!b) return a;
	ST* fn = &stp[stcnt++];
	copy(fn, a, a->l, a->r);
	if (a->l == a->r) {
		fn->mx = mp(a->mx.fi + b->mx.fi, a->mx.se);
		return fn;
	}
	fn->ch[0] = merge(a->ch[0], b->ch[0]);
	fn->ch[1] = merge(a->ch[1], b->ch[1]);
	upd(fn);
	return fn;
}
pi q(ST *a, int l, int r) {
//	cout << "!!" << l << ' ' << r << endl;
	if (!a) return mp(0, -l);
	if (a->l == l && a->r == r)
		return a->mx;
	int mid = (a->l + a->r) >> 1;
	if (r <= mid) return q(a->ch[0], l, r);
	else if (l > mid) return q(a->ch[1], l, r);
	else return max(q(a->ch[0], l, mid), q(a->ch[1], mid + 1, r));
}
int m;
namespace SAM {
	const int N = 1300005; // 2 * len
	int ch[N][27];
	int idcnt = 0;
	int pl[N]; // 1 ~ i 
	int id[N], len[N], fa[N], col[N]; // id
	int l = 0;
	int str[N]; //  
	void init() {
		idcnt++;
		pl[0] = idcnt, id[idcnt] = 0;
		len[idcnt] = 0;
	}
	void ins(int c, int co) {
		// id : -[1,i]   [1,i] 
		int nx = ++idcnt;
		l++; 
		len[nx] = l;
		col[l] = co; // col 
		str[l] = c; 
		pl[l] = nx, 
		id[nx] = l;
		int x = pl[l - 1];
		while (!ch[x][c] && x) {
			ch[x][c] = nx;
			x = fa[x];
		}
		if (!x) fa[nx] = 1; // imp
		else { 
			int t = ch[x][c];
			if (len[t] == len[x] + 1) fa[nx] = t;
			else {
				int nt = ++idcnt;
				len[nt] = len[x] + 1;
				fa[nt] = fa[t]; // imp
				memcpy(ch[nt], ch[t], sizeof(ch[nt]));
				fa[t] = nt, fa[nx] = nt;
				id[nt] = -abs(id[t]);
				int u = x;
				while (u) {
					if (ch[u][c] == t) ch[u][c] = nt;
					else break;
					u = fa[u];
				}
			}
		} 
	}
	vi eg[N];
	void Getfa() { //  
		for (int i = 2; i <= idcnt; i++)
			eg[fa[i]].pb(i);
	}
	int pre[N][21]; //  
	ST *root[N];
	void dfs(int a) { // DFS  
		root[a] = &stp[stcnt++];
		root[a]->l = 0, root[a]->r = m;
		root[a]->mx = mp(0, -1);
		if (id[a] > 0 && col[id[a]]) {
			cha(root[a], col[id[a]]); 
	//		cout << "CH" << a << ' ' << col[id[a]] << ' ' << fa[a] << endl;
		//	pi cur = q(root[a], 0, 2);
		//	cout << cur.fi << ' ' << cur.se << endl;
		}
		for (auto v : eg[a]) {
			pre[v][0] = a;
			for (int i = 1; i < 21; i++)
				pre[v][i] = pre[pre[v][i - 1]][i - 1];
			dfs(v);
			root[a] = merge(root[a], root[v]);
		}
	}
	pi ask(int id, int le, int l, int r) {
		id = pl[id];
		for (int i = 20; i >= 0; i--) {
			int v = pre[id][i];
			if (len[v] >= le) id = v; 
		}
	//	cout << "ASK" << id << ' ' << l << ' ' << r << endl;
		return q(root[id], l, r);
	}
} 
char s[500005];
int main() {
	SAM::init();
	scanf("%s", s + 1);
	int l = strlen(s + 1);
	for (int i = 1; i <= l; i++)
		SAM::ins(s[i] - 'a', 0);
	cin >> m;
	for (int i = 1; i <= m; i++) {
		scanf("%s", s + 1);
		SAM::ins(26, 0);
		int l = strlen(s + 1);
		for (int j = 1; j <= l; j++)
			SAM::ins(s[j] - 'a', i);
	}
	SAM::Getfa();
	SAM::dfs(1);
	int q;
	cin >> q;
	for (int i = 1; i <= q; i++) {
		int l, r, u, v;
		scanf("%d%d%d%d", &l, &r, &u, &v);
		pi cur = SAM::ask(v, v - u + 1, l, r);
		printf("%d %d\n", -cur.se, cur.fi);
	}
	return 0;
}
/*
ab
1
bb
2
1 1 2 2

*/