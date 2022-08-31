#include <bits/stdc++.h>
using namespace std;
#define maxn 300010
#define ll long long
#define db double
#define vi vector<int>
#define pb push_back
#define mod 998244353
#define pi pair<int, int>
#define fi first
#define se second
#define mp make_pair
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
// head
int t, tp[maxn], a[maxn], b[maxn];
int fa[maxn], vis[maxn];
pi seg[maxn];
int gfa(int a) {
	if (fa[a] == a) return a;
	return fa[a] = gfa(fa[a]);
}
struct ST {
	int l, r;
	ST *ch[2];
	vi tr;
}p[maxn << 1], *root;
int stcnt = 0;
void bdtree(ST *a, int l, int r) {
	a->l = l, a->r = r;
	if (l == r) return;
	int mid = (l + r) >> 1;
	a->ch[0] = &p[stcnt++], a->ch[1] = &p[stcnt++];
	bdtree(a->ch[0], l, mid), bdtree(a->ch[1], mid + 1, r);
}
void ch(ST *a, int l, int r, int id) {
	if (l > r) return ;
	if (a->l == l && a->r == r) {
		a->tr.pb(id);
		return ;
	}
	int mid = (a->l + a->r) >> 1;
	if (r <= mid) ch(a->ch[0], l, r, id);
	else if (l > mid) ch(a->ch[1], l, r, id);
	else ch(a->ch[0], l, mid, id), 
		ch(a->ch[1], mid + 1, r, id);
}
vi res;
void q(ST *a, int pl) {
	res.insert(res.end(), a->tr.begin(), a->tr.end());
	a->tr.clear();
	if (a->l == a->r) return ;
	int mid = (a->l + a->r) >> 1;
	if (pl <= mid) q(a->ch[0], pl);
	else q(a->ch[1], pl); 
}
pi re[maxn];
int id[maxn];
int idcnt = 0, ncnt = 0;
int main() {
	for (int i = 0; i < maxn; i++)
		fa[i] = i;
	int n;
	cin >> n;
	vi st;
	for (int i = 1; i <= n; i++)
		scanf("%d%d%d", &tp[i], &a[i], &b[i]), 
		st.pb(a[i]), st.pb(b[i]);
	
	sort(st.begin(), st.end());
	for (int i = 1; i <= n; i++)
		if (tp[i] == 1)
			a[i] = lower_bound(st.begin(), st.end(), a[i]) - st.begin(), 
			b[i] = lower_bound(st.begin(), st.end(), b[i]) - st.begin();
	root = &p[stcnt++];
	bdtree(root, 0, st.size());
	for (int i = 1; i <= n; i++) {
		if (tp[i] == 2) {
			int ans = 0;
			int ns = gfa(id[b[i]]);
			if (seg[ns].fi < re[a[i]].fi && seg[ns].se > re[a[i]].fi) ans = 1;
			if (seg[ns].fi < re[a[i]].se && seg[ns].se > re[a[i]].se) ans = 1;
			if (ans) printf("YES\n");
			else printf("NO\n");
		}
		else {
			re[++ncnt] = mp(a[i], b[i]);
			id[ncnt] = ++idcnt;
			seg[idcnt] = mp(a[i], b[i]);
			res.clear();
			q(root, a[i]), 
			q(root, b[i]);
			res.pb(idcnt);
			++idcnt;
			int nl = 1e9, nr = -1e9;
			for (int i = 0; i < res.size(); i++) {
				int nid = res[i];
				if (vis[nid]) continue;
				vis[nid] = 1;
				nl = min(nl, seg[nid].fi), nr = max(nr, seg[nid].se);
				fa[nid] = idcnt;
			}
			seg[idcnt] = mp(nl, nr);
			ch(root, nl + 1, nr - 1, idcnt);
		}
	}
	return 0;
}