#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 100005;
int k, n, m, a[N], t[N], p[N], b[N], mx[N];
bool del[N];

struct frac {
	ll x, y;
} v[N];
bool operator>(const frac &a, const frac &b) {
	return (a.x - a.y) * b.y > a.y * (b.x - b.y);
}
vector<int> add[N];

int main() {
	scanf("%d%d%d", &k, &n, &m);
	for (int i = 1; i <= k; ++i) scanf("%d", a + i);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d%d", t + i, p + i, b + i);
		if (t[i] == 1) {
			if (b[i] > b[mx[p[i]]]) mx[p[i]] = i;
		} else if (t[i] == 3)
			v[i] = (frac){b[i], 1};
	}
	vector<int> all;
	for (int i = 1; i <= n; ++i) {
		if (t[i] == 1) {
			if (mx[p[i]] != i) del[i] = true;
			else t[i] = -2, b[i] -= a[p[i]], add[p[i]].push_back(i);
		} else if (t[i] == 2)
			add[p[i]].push_back(i);
		if (!del[i]) all.push_back(i);
	}
	for (int i = 1; i <= k; ++i) {
		sort(add[i].begin(), add[i].end(), [](int x, int y) { return b[x] > b[y]; });
		ll now = a[i];
		for (int x : add[i])
			v[x] = (frac){now + b[x], now}, now += b[x];
	}
	sort(all.begin(), all.end(), [](int x, int y) { return v[x] > v[y]; });
	while (!all.empty() && !(v[all.back()] > (frac){1, 1})) all.pop_back();
	int l = min((int)all.size(), m);
	printf("%d\n", l);
	for (int i = 0; i < l; ++i)
		if (t[all[i]] == -2) printf("%d ", all[i]);
	for (int i = 0; i < l; ++i)
		if (t[all[i]] == 2) printf("%d ", all[i]);
	for (int i = 0; i < l; ++i)
		if (t[all[i]] == 3) printf("%d ", all[i]);
	puts("");
}