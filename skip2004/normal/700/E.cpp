#include<bits/stdc++.h>
const int maxn = 400200;
const int mod = 998244353;
typedef long long ll;
inline ll pow(ll a,int b,ll ans = 1) {
	for(;b;b >>= 1,a = a * a % mod) if(b & 1) ans = ans * a % mod;
	return ans;
}
inline ll inverse(int x){ return pow(x, mod - 2); }
inline void reduce(int & x){ x += x >> 31 & mod; }
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
namespace tree {
	int ls[maxn * 40], rs[maxn * 40], val[maxn * 40], tot;
	inline void add(int & rt,int pos,int l = 1,int r = maxn) {
		if(!rt) rt = ++ tot;
		++val[rt];
		if(l == r) return ;
		int mid = l + r >> 1;
		if(pos <= mid) add(ls[rt], pos, l, mid);
		else add(rs[rt], pos, mid + 1, r);
	}
	inline int qry(int rt,int ql,int qr,int l = 1,int r = maxn) {
		if(ql <= l && r <= qr) return val[rt];
		int mid = l + r >> 1, ans = 0;
		if(ql <= mid) ans += qry(ls[rt], ql, qr, l, mid);
		if(mid < qr) ans += qry(rs[rt], ql, qr, mid + 1,r);
		return ans;
	}
	inline int merge(int x,int y) {
		if(!x || !y) return x | y;
		int z = ++ tot;
		val[z] = val[x] + val[y];
		ls[z] = merge(ls[x], ls[y]);
		rs[z] = merge(rs[x], rs[y]);
		return z;
	}
}
int mx[maxn], fa[maxn], c[maxn][26], la = 1, tot = 1;
int dp[maxn], right[maxn], rt[maxn];
char s[maxn];
std::vector<int> to[maxn];
inline void ins(int w,int id) {
	int p = la, now = la = ++ tot;
	mx[now] = mx[p] + 1; right[now] = id; tree::add(rt[now], id);
	for(;p && !c[p][w];p = fa[p]) c[p][w] = now;
	if(!p) fa[now] = 1;
	else {
		int q = c[p][w];
		if(mx[q] == mx[p] + 1) fa[now] = q;
		else {
			int x = ++tot; mx[x] = mx[p] + 1;
			memcpy(c[x], c[q], sizeof c[x]);
			right[x] = right[q]; fa[x] = fa[q], fa[q] = fa[now] = x;
			for(;p && c[p][w] == q;p = fa[p]) c[p][w] = x;
		}
	}
}
inline void dfs0(int x) { for(int i : to[x]) dfs0(i), rt[x] = tree::merge(rt[x], rt[i]); }
int up[maxn];
inline void dfs1(int x) {
	dp[x] = dp[fa[x]];
	if(int t = up[dp[x]])
		if(tree::qry(rt[t],right[x] - mx[x] + mx[t],right[x]) >= 2) 
			++ dp[x];
	if(x != 1 && !up[dp[x]]) up[dp[x]] = x;
	for(int i : to[x])
		dfs1(i);
	if(up[dp[x]] == x) up[dp[x]] = 0;
}
int main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> s >> s;
	for(int i = 0;s[i];++i) ins(s[i] - 'a', i + 1);
	for(int i = 2;i <= tot;++i) to[fa[i]].push_back(i);
	dfs0(1);
	dp[0] = 1;
	dfs1(1);
	std::cout << * std::max_element(dp + 1,dp + tot + 1) << '\n';
}