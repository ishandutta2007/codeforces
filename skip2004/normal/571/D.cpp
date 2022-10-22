#include<bits/stdc++.h>
const int maxn = 1000100;
typedef long long ll;
int n, m;
struct T { int tm, v, pos, id; };
std::vector<T> v;
char t[maxn];
int a[maxn], b[maxn], x[maxn];
int fa[maxn], max[maxn];
int id[maxn], size[maxn], qid;
ll sum[maxn], ans[maxn];
inline int find0(int x) {
	if(x == fa[x]) return x;
	find0(fa[x]);
	if(fa[fa[x]] != fa[x]) max[x] = std::max(max[x], max[fa[x]]);
	return fa[x] = fa[fa[x]];
}
inline int find1(int x) {
	if(x == fa[x]) return x;
	find1(fa[x]);
	if(fa[fa[x]] != fa[x]) sum[x] += sum[fa[x]];
	return fa[x] = fa[fa[x]];
}
inline void init() {
	auto find = find0;
	for(int i = 1;i <= n + m;++i) fa[i] = i;
	int tot = n;
	for(int i = 1;i <= m;++i) {
		if(t[i] == 'M') fa[a[i] = find(a[i])] = fa[b[i] = find(b[i])] = ++tot;
		if(t[i] == 'Z') x[i] = find(x[i]), max[x[i]] = std::max(max[x[i]], i);
		if(t[i] == 'Q') {
			id[i] = ++ qid;
			v.push_back({i, 1, x[i], i});
			find(x[i]);
			v.push_back({std::max(max[fa[x[i]]], max[x[i]]), -1, x[i], i});
		}
	}
}
inline void solve() {
	auto find = find1;
	for(int i = 1;i <= n + m;++i) fa[i] = i, size[i] = 1;
	int tot = n, i = 1;
	std::sort(v.begin(), v.end(), [](const T & x,const T & y){ return x.tm < y.tm; });
	for(auto x : v) if(x.tm) { 
		for(;i < x.tm;++i){
			if(t[i] == 'U') {
				fa[a[i] = find(a[i])] = fa[b[i] = find(b[i])] = ++tot;
				size[tot] = size[a[i]] + size[b[i]];
			}
			if(t[i] == 'A') {
				int o = find(::x[i]);
				sum[o] += size[o];
			}
		}
		find(x.pos);
		ans[id[x.id]] += x.v * (sum[x.pos] + (fa[x.pos] == x.pos ? 0 : sum[fa[x.pos]]));
	}
}
int main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m;
	for(int i = 1;i <= m;++i) {
		std::cin >> t[i];
		if(t[i] == 'U' || t[i] == 'M')
			std::cin >> a[i] >> b[i];
		else
			std::cin >> x[i];
	}
	init(), solve();
	for(int i = 1;i <= qid;++i) std::cout << ans[i] << '\n';
}