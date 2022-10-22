#include<bits/stdc++.h>
using std::cin;
using std::cout;
const int maxn = 10100;
int n, ans;
int sum = 0;
struct edge { int u, v, w; } a[maxn];
int fa[maxn], size[maxn], can[maxn];
inline int find(int x) { return fa[x] == x ? fa[x] : fa[x] = find(fa[x]); }
inline int cmp0(const edge & x, const edge & y) { return x.w < y.w; }
inline int check(int x){ return size[find(x)] > sum - can[find(x)]; }
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	for(int i = 1;i < n;++i) {
		cin >> a[i].u >> a[i].v >> a[i].w;
	}
	for(int i = 1;i <= n;++i) {
		cin >> can[i];
		sum += can[i];
		fa[i] = i;
		size[i] = 1;
	}
	std::sort(a + 1, a + n, cmp0);
	for(int i = 1;i <= n;++i) {
		ans += check(i);
	}
	for(int i = 1;i < n;++i){
		int x = find(a[i].u), y = find(a[i].v);
		ans -= check(x) + check(y);
		fa[x] = y;
		size[y] += size[x];
		can[y] += can[x];
		ans += check(x);
		if(ans) {
			cout << a[i].w << '\n';
			return 0;
		}
	}
	cout << a[n - 1].w << '\n';
}