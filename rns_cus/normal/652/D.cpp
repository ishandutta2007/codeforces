#include <bits/stdc++.h>
using namespace std;
#define N 400400

struct segment {
	int x, y, id;
	bool operator < (const segment &b) const {
		return x != b.x ? x < b.x : y < b.y;
	}
} p[N];

int n, z[N], f[N];
map <int, int> mp;

int a[N];

int add(int k) {
	while (k < N) {
		a[k] ++;
		k += k & -k;
	}
}

int calc(int k) {
	int rlt = 0;
	while (k) {
		rlt += a[k];
		k -= k & -k;
	}
	return rlt;
}

int main() {
//	freopen("d.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d %d", &p[i].x, &p[i].y), p[i].id = i;
	for (int i = 1; i <= n; i ++) z[i-1] = p[i].y;
	sort(z, z + n);
	int m = unique(z, z + n) - z;
	for (int i = 0; i < m; i ++) mp[z[i]] = i + 1;
	for (int i = 1; i <= n; i ++) p[i].y = mp[p[i].y];
	sort(p + 1, p + n + 1);
	for (int i = n; i >= 1; i --) {
		f[p[i].id] = calc(p[i].y);
		add(p[i].y);
	}
	for (int i = 1; i <= n; i ++) printf("%d\n", f[i]);
	return 0;
}