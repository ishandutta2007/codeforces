#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int n, m, a[N], b[N], f[N], pre[N], st[N], top, pos[N], pre_empty[N];
vector<int> v[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
		if (a[i - 1] == -1) pre_empty[i] = i - 1;
		else pre_empty[i] = pre_empty[i - 1];
	}
	a[n + 1] = 1000000001;
	scanf("%d", &m);
	for (int i = 1; i <= m; ++i)
		scanf("%d", b + i);
	multiset<int> ms(b + 1, b + 1 + m);
	sort(b + 1, b + 1 + m, greater<>());
	m = unique(b + 1, b + 1 + m) - b - 1;
	for (int i = 1; i <= n + 1; ++i) {
		if (a[i] == -1) {
			if (b[1] > st[top]) {
				st[f[i] = ++top] = b[1], pos[top] = i;
			} else {
				int j = f[i] = lower_bound(st + 1, st + 1 + top, b[1]) - st;
				pos[j] = i;
				st[j] = b[1];
			}
			for (int j = 2, k = top; j <= m; ++j) {
				while (st[k - 1] >= b[j]) --k;
				pos[k] = i;
				st[k] = b[j];
			}
		} else {
			if (a[i] > st[top]) {
				st[f[i] = ++top] = a[i], pos[top] = i;
				if (top > 1) pre[i] = pos[top - 1];
			} else {
				int j = f[i] = lower_bound(st + 1, st + 1 + top, a[i]) - st;
				if (j > 1) pre[i] = pos[j - 1];
				pos[j] = i;
				st[j] = a[i];
			}
			if (v[f[i]].empty() || a[i] < a[v[f[i]].back()])
				v[f[i]].push_back(i);
		}
	}
	bool empty = false;
	int now = n + 1;
	for (int i = top; i > 1; --i) {
		if (!empty) {
			if (a[pre[now]] == -1) {
				auto it = --ms.lower_bound(a[now]);
				a[pre[now]] = *it;
				empty = true;
				ms.erase(it);
			}
			now = pre[now];
		} else {
			auto it = lower_bound(v[i - 1].begin(), v[i - 1].end(), now);
			if (it != v[i - 1].begin() && a[*--it] < a[now]) {
				now = *it;
				empty = false;
			} else {
				auto it = --ms.lower_bound(a[now]);
				a[pre_empty[now]] = *it;
				now = pre_empty[now];
				ms.erase(it);
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (a[i] == -1) {
			a[i] = *ms.begin();
			ms.erase(ms.begin());
		}
		printf("%d%c", a[i], " \n"[i == n]);
	}
}