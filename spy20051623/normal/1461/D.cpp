#include <bits/stdc++.h>
using namespace std;
map<int, int> m;
set<long long> s;
#define T tr[n]
int cnt;

struct tree {
	int l, r;
	long long sum;
	int ls, rs;
} tr[400000];

bool build(int n, int l, int r) {
	auto it1 = m.lower_bound(l);
	T.l = it1->first;
	auto it2 = m.upper_bound(r);
	if (it2 != m.begin())
		--it2;
	T.r = it2->first;
	if (T.l > r)
		return false;
	if (T.l == T.r) {
		T.sum = 1LL * m[T.l] * T.l;
		s.insert(T.sum);
		return true;
	}
	int m = T.l + T.r >> 1;
	T.ls = cnt++;
	if (!build(T.ls, l, m))
		T.ls = 0;
	T.rs = cnt++;
	if (!build(T.rs, m + 1, r))
		T.rs = 0;
	T.sum = 0;
	if (T.ls)
		T.sum += tr[T.ls].sum;
	if (T.rs)
		T.sum += tr[T.rs].sum;
	s.insert(T.sum);
	return true;
}

int main() {
//	freopen("in.txt", "r", stdin);
	long long t, n, q, i, j, k;
	cin >> t;
	while (t--) {
		m.clear();
		s.clear();
		memset(tr, 0, sizeof(tr));
		cin >> n >> q;
		for (i = 0; i < n; ++i) {
			cin >> j;
			++m[j];
		}
		cnt = 1;
		build(0, 1, 1e9 + 1);
		while (q--) {
			cin >> j;
			cout << (s.find(j) != s.end() ? "YES" : "NO") << endl;
		}
	}
	return 0;
}