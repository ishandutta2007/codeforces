#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e7 + 11;
using ll = long long;

int p[N];

struct DSU {
	int p[N];
	void init() {
		iota(p, p + N, 0);
	}
	int find(int x) {
		if(p[x] == x) return x;
		return p[x] = find(p[x]);
	}
	bool query(int a, int b) {
		return find(a) == find(b);
	}
	void merge(int a, int b) {
		p[find(a)] = find(b);
	}
}dsu;

int a[N];

map <int, int> mp;
void dfs(map <int, int> :: iterator it, int d, int n, int &ans) {
	if(it == mp.end()) {
		int nd = n / d; ll t;
		if(d > n / d) {
			if((t = ll(d) * d - ll(nd) * nd) < N && a[t]) {
				if(__gcd((int)t, 2 * n) == 1 && !dsu.query(t, 2 * n)) {
					dsu.merge(t, 2 * n);
					ans --;
				}
			}
			if((t = ll(d) * d + ll(nd) * nd) < N && a[t]) {
				if(__gcd((int)t, 2 * n) == 1 && !dsu.query(t, 2 * n)) {
					dsu.merge(t, 2 * n);
					ans --;
				}
			}
		}
	} else {
		for(int i = 0; i <= it -> second; i ++) {
			dfs(next(it), d, n, ans);
			d *= it -> first;
		}
	}
}

int main() {
	iota(p, p + N, 0);
	for(int i = 2; i < N; i ++) if(p[i] == i) {
		for(int j = i; j < N; j += i) p[j] = i;
	}

	int n; scanf("%d", &n);
	for(int i = 0; i < n; i ++) {
		int x; scanf("%d", &x);
		a[x] = 1;
	}
	int ans = n;

	int s, t;
	dsu.init();
	for(int i = 1; i * i < N; i ++)
		for(int j = 1; (s = i * i + j * j) < N && i > j; j ++) {
			t = i * i - j * j;
			if(a[s] && a[t] && __gcd(s, t) == 1 && !dsu.query(s, t)) {
				ans --;
				dsu.merge(s, t);
			}
		}
	for(int i = 1; i < N; i ++) if(a[i] && i % 2 == 0) {
		mp.clear();
		for(int t = i / 2; t > 1; t /= p[t])
			mp[p[t]] ++;
		dfs(mp.begin(), 1, i / 2, ans);
	}
	cout << ans << '\n';
	return 0;
}