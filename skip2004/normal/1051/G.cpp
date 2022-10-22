#include<bits/stdc++.h>
const int maxn = 400200, N = maxn * 40;
using std::cin;
typedef long long ll;
int n;
int ls[N], rs[N], sum[N], tot;
ll s[N], ans;
inline void add(int & rt, int pos, int l = 1, int r = n) {
	if(!rt) rt = ++ tot;
	sum[rt] += 1;
	s[rt] += pos;
	if(l == r) return ;
	int mid = l + r >> 1;
	pos <= mid ? add(ls[rt], pos, l, mid) : add(rs[rt], pos, mid + 1, r);
}
inline int merge(int x, int y, int l = 1, int r = n) {
	if(!x || !y) return x | y;
	if(l == r) {
		ans -= s[x] * sum[y];
		sum[x] += sum[y], s[x] += s[y];
		return x;
	}
	int mid = l + r >> 1;
	ans -= s[rs[x]] * sum[ls[y]] + s[rs[y]] * sum[ls[x]];
	sum[x] += sum[y], s[x] += s[y];
	ls[x] = merge(ls[x], ls[y], l, mid);
	rs[x] = merge(rs[x], rs[y], mid + 1, r);
	return x;
}
int fa[maxn], rt[maxn];
inline int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	for(int i = 1;i < maxn;++i) {
		fa[i] = i;
	}
	cin >> n;
	for(int i = 1, a, b, c;i <= n;++i) {
		cin >> a >> b;
		ans += (ll) (find(a) - a) * b;
		a = find(a);
		int R = 0; add(R, b);
		ans += s[rt[a]];
		rt[a] = merge(rt[a], R);
		fa[a] = a + 1;
		ans += (ll) s[rt[a]] * (find(a) - a - 1);
		rt[find(a)] = merge(rt[find(a)], rt[a]);
		std::cout << ans << '\n';
	}
}