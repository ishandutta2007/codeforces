#include <bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
#define db double
#define vi vector<int>
#define pb push_back
#define mod 998244353
#define fi first
#define pi pair<int, int>
#define se second
#define mp make_pair
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
// head#include <iostream>
ll dep[maxn];
int ch[maxn][2], mpl[maxn], fa[maxn], rev[maxn];
int to[maxn]; //  
void upd(int a)
{
	mpl[a] = a;
	for(int i = 0; i < 2; i++)
		if(ch[a][i] && dep[mpl[ch[a][i]]] < dep[mpl[a]])
			mpl[a] = mpl[ch[a][i]];		
}
bool isr(int a)
{
	return !(ch[fa[a]][0] == a || ch[fa[a]][1] == a);
} 
void rotate(int a)
{
	int f = fa[a], gf = fa[f];
	int tp = ch[f][1] == a;
	int son = ch[a][tp ^ 1];
	if(!isr(f)) 
		ch[gf][ch[gf][1] == f] = a;	
	fa[a] = gf;
	
	ch[f][tp] = son;
	if(son) fa[son] = f;
	
	ch[a][tp ^ 1] = f, fa[f] = a;
	upd(f), upd(a); 
}
void splay(int a)
{
	while(!isr(a))
	{
		int f = fa[a], gf = fa[f];
		if(isr(f)) rotate(a);// cout<<"RT"<<" "<<fa[4]<<" "<<a<<" "<<isr(4)<<" "<<ch[0][0]<<" "<<ch[0][1]<<endl;
		else
		{
			int t1 = ch[gf][1] == f, t2 = ch[f][1] == a;
			if(t1 == t2) rotate(f), rotate(a);
			else rotate(a), rotate(a);	
		} 
	} 
}
vector<pair<ll, ll> > res;
int ppr[maxn];
int mx[maxn * 5];
void up(int a) {
	mx[a] = max(mx[a * 2], mx[a * 2 + 1]);
}
void chd(int a, int l, int r, int pl, int x) {
	if (l == r) {
		mx[a] = x;
		return ;
	} 
	int mid = (l + r) / 2;
	if (pl <= mid) chd(a * 2, l, mid, pl, x);
	else chd(a * 2 + 1, mid + 1, r, pl, x);
	up(a);
} 
int q(int a, int l, int r, int ql, int qr) {
	if (l == ql && r == qr) return mx[a];
	int mid = (l + r) / 2;
	if (qr <= mid) return q(a * 2, l, mid, ql, qr);
	else if (ql > mid) return q(a * 2 + 1, mid + 1, r, ql, qr);
	else return max(q(a * 2, l, mid, ql, mid), q(a * 2 + 1, mid + 1, r, mid + 1, qr));
}
int dfn[maxn], sz[maxn];
int n;
void access(int a, int t)
{
	int pr = a;
	splay(a);
	ch[a][1] = 0;
	upd(a);
	while(1)
	{
		if(!fa[a]) break; 
		int u = fa[a];
		int ex = mpl[a];
	
		if (to[u] != ex) {	
			ll lt = dep[u] + q(1, 1, n, dfn[u] + 1, dfn[u] + sz[u] - 1);
			if (lt == dep[u]) lt = 1;
			res.pb(mp(lt + 1, t + dep[u]));
		//	cout << "PUSH" << t + dep[ppr[u]] + 1 << ' ' << t + dep[u] << endl;
			to[u] = ex;
		}
		splay(u);
		ch[u][1] = a, upd(u);
		a = u;
	}
	splay(pr);
}
vi eg[maxn], w[maxn];
int dfcnt = 0;
void dfs(int a) {
	dfn[a] = ++dfcnt;
	sz[a] = 1;
	for (int j = 0; j < eg[a].size(); j++) {
		int v = eg[a][j];
		dep[v] = dep[a] + w[a][j];
		dfs(v);
		sz[a] += sz[v];
	}
}
int main() {
	int m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		mpl[i] = i;
		
	for (int i = 1; i < n; i++) {
		int u, v, d;
		scanf("%d%d%d", &u, &v, &d);
		to[u] = v;
		fa[v] = u;
		ppr[v] = u;
		eg[u].pb(v), w[u].pb(d);
	}
	dep[1] = 1;
	dfs(1);
	for (int j = 1; j <= m; j++) {
		int s, t;
		scanf("%d%d", &s, &t);
		access(s, t);
		chd(1, 1, n, dfn[s], t);
	}
	vector<pair<ll, ll> >q = res; 
	sort(q.begin(), q.end());
	priority_queue <ll> u;
	ll t = 1;
	int pl = 0;
	while (1) {
		while (pl < q.size() && q[pl].fi <= t) {
			u.push(-q[pl].se);
			pl++;
		}
		if (u.empty()) {
			if (pl == q.size()) {
				cout << -1 << ' ' << q.size() << endl;
				return 0;
			}
			else t = q[pl].fi;
		}
		else {
			ll r = -u.top(); u.pop();
			if (r < t) {
				ll ans = r - 1;
				int tot = 0;
				for (int j = 0; j < q.size(); j++)
					if (q[j].se <= ans) tot++;
				cout << ans << ' ' << tot << endl;
				return 0;
			}
			t++;
		}
	}
	return 0;
}