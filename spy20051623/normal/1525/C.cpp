#include <bits/stdc++.h>

using namespace std;

struct ro {
	int a, b, c, id;
} r[300005];

int cmp(ro x, ro y) {
	return x.a < y.a;
}

int s[300005];

void solve() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &r[i].a);
		r[i].id = i;
	}
	for (int i = 1; i <= n; ++i) {
		getchar();
		if (getchar() == 'R')
			r[i].b = 1;
		else
			r[i].b = -1;
	}
	sort(r + 1, r + n + 1, cmp);
	deque<int> q[2];
	for (int i = 1; i <= n; ++i) {
		int k = r[i].a % 2;
		if (q[k].empty()) {
			q[k].push_back(i);
		} else {
			int p = q[k].back();
			if (r[i].b == -1 && r[p].b == 1) {
				r[i].c = r[p].c = (r[i].a - r[p].a) / 2;
				q[k].pop_back();
			} else {
				q[k].push_back(i);
			}
		}
	}
	for (auto &k : q) {
		while (k.size() >= 2) {
			int i = k.front();
			if (r[i].b == 1)
				break;
			k.pop_front();
			int j = k.front();
			if (r[j].b == 1) {
				k.push_front(i);
				break;
			}
			r[i].c = r[j].c = (r[i].a + r[j].a) / 2;
			k.pop_front();
		}
		while (k.size() >= 2) {
			int i = k.back();
			if (r[i].b == -1)
				break;
			k.pop_back();
			int j = k.back();
			if (r[j].b == -1) {
				k.push_back(i);
				break;
			}
			r[i].c = r[j].c = (m - r[i].a + m - r[j].a) / 2;
			k.pop_back();
		}
		if (k.size() == 1) {
			int i = k.front();
			r[i].c = -1;
		}
		if (k.size() == 2) {
			int i = k.front();
			int j = k.back();
			r[i].c = r[j].c = (r[i].a + m + m - r[j].a) / 2;
		}
	}
	for (int i = 1; i <= n; ++i) {
		s[r[i].id] = r[i].c;
	}
	for (int i = 1; i <= n; ++i) {
		printf("%d ", s[i]);
	}
	printf("\n");
}

int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}