#include<bits/stdc++.h>
using std::cin;
using std::cout;
typedef long long ll;
const int maxn = 500500;
int n, p[maxn], dep[maxn], rk[maxn];
inline int cmp0(int x, int y) { return dep[x] < dep[y]; }
int size[maxn], dfn[maxn], son[maxn], top[maxn], tot;
typedef long long ll;
struct bit {
	ll a[maxn], b[maxn];
	void add(int l, int r) {
		for(int i = l;i < maxn;i += i & -i) a[i] += 1, b[i] += l;
		for(int i = r + 1;i < maxn;i += i & -i) a[i] -= 1, b[i] -= r + 1;
	}
	ll ask(int l, int r) {
		ll ans = 0;
		for(int i = r;i;i &= i - 1) ans += a[i] * (r + 1) - b[i];
		for(int i = l - 1;i;i &= i - 1) ans -= a[i] * l - b[i];
		return ans;
	}
} bit;
ll ans[maxn];
inline void add(int x) { for(;x;x=p[top[x]]) bit.add(dfn[top[x]],dfn[x]); }
inline ll ask(int x){ ll a=0; for(;x;x=p[top[x]]) a+=bit.ask(dfn[top[x]],dfn[x]); return a; }
int head[maxn], next[maxn], rt;
inline void add(int fa, int x) {
	next[x] = head[fa], head[fa] = x;
}
inline void dfs(int x) {
	dep[x] = dep[p[x]] + 1, size[x] = 1;
	for(int i = head[x];i;i = next[i]) {
		dfs(i), size[x] += size[i];
		if(size[i]>size[son[x]])son[x]=i;
	}
}
void dfs1(int x, int tp) {
	top[x]=tp,dfn[x]=++tot;
	if(son[x])dfs1(son[x],tp);
	for(int i = head[x];i;i = next[i]) if(i!=son[x]) dfs1(i, i);
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;++i) {
		cin >> p[i];
		if(p[i]) add(p[i], i);
		else rt = i;
		rk[i] = i;
	}
	dfs(rt), dfs1(rt, rt);
	std::sort(rk + 1, rk + n + 1, cmp0);
	for(int i = 1, j = 1;i <= n;i = j) {
		for(;j <= n && dep[rk[j]] == dep[rk[i]];++j) add(rk[j]);
		for(;i < j;++i) ans[rk[i]] = ask(rk[i]);
	}
	for(int i = 1;i <= n;++i) cout << ans[i] - dep[i] << ' ';
}