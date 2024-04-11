#include <bits/stdc++.h>
using namespace std;

const int N = 100011;
using ll = long long;

struct DS {
	int p[N];
	ll sum[N];
	void init() {
		iota(p, p + N, 0);
		memset(sum, 0, sizeof(sum));
	}
	int find(int x) {
		if(p[x] == x) return x;
		return p[x] = find(p[x]);
	}
	void merge(int a, int b) {
		sum[find(a)] += sum[find(b)];
		p[find(b)] = find(a);
	}
}ds;

long long p[N], ans[N];
bool v[N];

int main() {
	ios :: sync_with_stdio(false);
	int n; cin >> n;
	ds.init();
	for(int i = 1; i <= n; i ++)
		cin >> ds.sum[i];
	ll t = 0;
	for(int i = 1; i <= n; i ++)
		cin >> p[i];
	for(int i = n; i >= 1; i --) {
		ans[i] = t;
		v[p[i]] = true;
		if(v[p[i] - 1]) ds.merge(p[i] - 1, p[i]);
		if(v[p[i] + 1]) ds.merge(p[i] + 1, p[i]);
		t = max(t, ds.sum[ds.find(p[i])]);
	}
	for(int i = 1; i <= n; i ++)
		cout << ans[i] << '\n';
	return 0;
}