#include <bits/stdc++.h>
using namespace std;

#define N 202020

const int K = 600;

int n, Q;

int a[N];

struct query {
	int le, ri, id;
	void input(int i) {
		scanf("%d %d", &le, &ri);
		id = i;
	}

	bool operator < (const query &b) const {
		if ((le - 1) / K != (b.le - 1) / K) return (le - 1) / K < (b.le - 1) / K;
		return ri < b.ri;
	}
} q[N];

#define M 1010101

int cnt[M];
long long val;

void add(int k, int d) {
	val -= 1ll * cnt[k] * cnt[k] * k;
	cnt[k] += d;
	val += 1ll * cnt[k] * cnt[k] * k;
}

long long ans[N];

void solve() {
	int e = 1;
	for (int st, en = 0; en < n; ) {
		st = en + 1;
		en = min(en + K, n);
		int mid = (st + en + 1) >> 1;
		for (int i = st; i < mid; i ++) add(a[i], -1);
		for (int i = st; i <= n; i ++) {
			add(a[i], 1);
			while (e <= Q && q[e].ri == i) {
				if (q[e].le > mid) for (int j = mid; j < q[e].le; j ++) add(a[j], -1);
				else for (int j = mid - 1; j >= q[e].le; j --) add(a[j], 1);
				ans[q[e].id] = val;
				if (q[e].le > mid) for (int j = mid; j < q[e].le; j ++) add(a[j], 1);
				else for (int j = mid - 1; j >= q[e].le; j --) add(a[j], -1);
				e ++;
			}
		}
		for (int i = mid; i <= n; i ++) add(a[i], -1);
	}
}

int main() {
	//freopen("r.in", "r", stdin);
	scanf("%d %d", &n, &Q);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	for (int i = 1; i <= Q; i ++) {
		q[i].input(i);
	}
	sort(q + 1, q + Q + 1);
	solve();
	for (int i = 1; i <= Q; i ++) printf("%I64d\n", ans[i]);


	return 0;
}