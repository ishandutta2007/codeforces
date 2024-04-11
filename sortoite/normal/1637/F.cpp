#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 2e5 + 10;
LL hei[N], a[N], rad[N], mx[N], b[N], res, mh;
vector<int> son[N];
void smax(LL & a, const LL & b) {
	if(a < b) a = b;
}
void smin(LL & a, const LL & b) {
	if(a > b) a = b;
}
LL sch(int u, int fa) {
	for(auto v : son[u]) {
		if(v != fa) {
			a[u] += sch(v, u);
			smax(mx[u], mx[v]);
		}
	}
	if(hei[u] > mx[u]) {
		a[u] += hei[u] - mx[u];
	}
	smax(mx[u], hei[u]);
	return a[u];
}
void resch(int u, int fa) {
	LL x = 0, y = 0, z = 0, s = rad[u];
	for(auto v : son[u]) {
		if(v != fa) {
			s += a[v];
			smax(z, mx[v]);
			if(y < z) {
				swap(y, z);
			}
		}
	}
	for(auto v : son[u]) {
		if(v != fa) {
			x = y;
			if(mx[v] == y) x = z;
			x = max(x, b[u]);
			rad[v] = s - a[v];
			if(hei[u] > x) {
				rad[v] += hei[u] - x;
			}
			b[v] = max(hei[u], x);
			resch(v, u);
		}
	}
}
void fisch(int u, int fa) {
	LL p = b[u], s = rad[u] + mh;
	for(auto v : son[u]) {
		if(v != fa) {
			s += a[v];
			smax(p, mx[v]);
		}
	}
	if(hei[u] > p) {
		s += hei[u] - p;
	}
	smin(res, s);
	for(auto v : son[u]) {
		if(v != fa) {
			fisch(v, u);
		}
	}
}
LL solve() {
	res = 0x3f3f3f3f3f3f3f3f;
	int n; cin >> n;
	for(int i = 1; i <= n; i ++) {
		scanf("%I64d", hei + i);
		smax(mh, hei[i]);
	}
	for(int i = 1, u, v; i < n; i ++) {
		scanf("%d %d", & u, & v);
		son[u].push_back(v), son[v].push_back(u);
	}
	sch(1, - 1), resch(1, - 1), fisch(1, - 1);
	return res;
}
int main() {
#ifdef TRUE
	freopen("in.in", "r", stdin);
#endif
	cout << solve() << endl;
	return 0;
}