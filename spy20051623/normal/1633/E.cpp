#include <bits/stdc++.h>

using namespace std;

int a[500], b[500], w[500], fa[500];
long long A[100000], B[100000], q[10000005];

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> a[i] >> b[i] >> w[i];
	}

	vector<double> v;
	v.push_back(0);
	for (int i = 0; i < m; ++i) {
		v.push_back(w[i] + 0.1);
		for (int j = i + 1; j < m; ++j) {
			v.push_back((w[i] + w[j]) * 0.5 + 0.1);
		}
	}
	sort(v.begin(), v.end());
	int s = unique(v.begin(), v.end()) - v.begin();
	v.resize(s);

	for (int i = 0; i < s; ++i) {
		vector<int> e;
		for (int j = 0; j < m; ++j) e.push_back(j);
		for (int j = 1; j <= n; ++j) fa[j] = j;
		sort(e.begin(), e.end(), [&](int x, int y) { return abs(w[x] - v[i]) < abs(w[y] - v[i]); });
		for (int j: e) {
			if (find(a[j]) == find(b[j])) continue;
			if (w[j] <= v[i]) ++A[i], B[i] -= w[j];
			else --A[i], B[i] += w[j];
			fa[find(b[j])] = find(a[j]);
		}
	}

	int p, k, aa, bb, cc;
	cin >> p >> k >> aa >> bb >> cc;
	for (int i = 0; i < p; ++i) cin >> q[i];
	for (int i = p; i < k; ++i) q[i] = (q[i - 1] * aa + bb) % cc;

	long long ans = 0;
	for (int i = 0; i < k; ++i) {
		int d = upper_bound(v.begin(), v.end(), q[i]) - v.begin() - 1;
		long long cur = A[d] * q[i] + B[d];
		ans ^= cur;
	}

	cout << ans << '\n';
	return 0;
}