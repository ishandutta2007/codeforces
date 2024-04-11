//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 2e6+5;
const pii z = make_pair(0, 0);

int n, m;
pii dp[N];
vector<int> buc;
vector<pii> seg[N];
set<int> ans;
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}
struct Node {
	pii w, tag;
	Node(pii a=z, pii b=z) : w(a), tag(b) {}
	~Node() {}
}t[N<<2];
#define lc(u) (u<<1)
#define rc(u) (u<<1|1)
void pushup(int u) {t[u].w = max(t[lc(u)].w, t[rc(u)].w);}
void pushdown(int u) {
	if(t[u].tag == z) return;
	t[lc(u)].tag = t[rc(u)].tag = t[u].tag;
	t[lc(u)].w = t[rc(u)].w = t[u].tag;
	t[u].tag = z;
}
void modifyMax(int u, int l, int r, int ql, int qr, pii k) {
	if(ql <= l && r <= qr) {
		t[u].tag = t[u].w = k;
		return;
	}
	pushdown(u);
	int mid = (l + r) >> 1;
	if(ql <= mid) modifyMax(lc(u), l, mid, ql, qr, k);
	if(qr > mid) modifyMax(rc(u), mid+1, r, ql, qr, k);
	pushup(u);
}
pii queryMax(int u, int l, int r, int ql, int qr) {
	if(ql <= l && r <= qr) return t[u].w;
	pushdown(u);
	int mid = (l + r) >> 1;
	pii rs = z;
	if(ql <= mid) chkmax(rs, queryMax(lc(u), l, mid, ql, qr));
	if(qr > mid) chkmax(rs, queryMax(rc(u), mid+1, r, ql, qr));
	return rs;
}
int getId(int x) {return lower_bound(buc.begin(), buc.end(), x) - buc.begin() + 1;}
void prod() {
	sort(buc.begin(), buc.end());
	auto it = unique(buc.begin(), buc.end());
	buc.erase(it, buc.end());
	rep(i, 1, n) {
		int sz = seg[i].size();
		rep(j, 0, sz-1) {
			seg[i][j].first = getId(seg[i][j].first);
			seg[i][j].second = getId(seg[i][j].second);
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	rep(i, 1, n) ans.insert(i);
	rep(i, 1, m) {
		int p, l, r;
		scanf("%d%d%d", &p, &l, &r);
		buc.push_back(l);
		buc.push_back(r);
		buc.push_back(l+1);
		buc.push_back(r+1);
		seg[p].push_back(make_pair(l, r));
	}
	prod();
	rep(i, 1, n) {
		int sz = seg[i].size();
		rep(j, 0, sz-1) {
			int l = seg[i][j].first, r = seg[i][j].second;
			pii now = queryMax(1, 1, N-1, l, r);
			++now.first;
			chkmax(dp[i], now);
		}
		rep(j, 0, sz-1) {
			int l = seg[i][j].first, r = seg[i][j].second;
			pii now = make_pair(dp[i].first, i);
			modifyMax(1, 1, N-1, l, r, now);
		}
	}
	int now = 0;
	rep(i, 1, n) if(dp[i] > dp[now]) now = i;
	for(;now;now=dp[now].second) ans.erase(now);
	int sz = ans.size();
	printf("%d\n", sz);
	for(set<int>::iterator it=ans.begin();it!=ans.end();it++) printf("%d ", *it);
	puts("");
	return 0;
}