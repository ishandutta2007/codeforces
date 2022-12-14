#include <bits/stdc++.h>
using namespace std;

const int N = 50005;
typedef long long i64;

struct task {
	int t, s, p, id;
} a[N], b[N];

bool compareByT(const task &a, const task &b) { return a.t < b.t; }

bool operator<(const task &a, const task &b) { return a.p < b.p; }
int n, sp;
unordered_set<int> s;
i64 T, ddl[N];

bool check(int p) {
	for (int i = 1; i <= n; i++) {
		b[i] = a[i];
		if (a[i].p == -1) b[i].p = p;
	}
	priority_queue<task> q;
	for (int i = 1; i <= n; i++) {
		q.push(b[i]);
		i64 cur = b[i].t, lim = i == n ? 1e18 : b[i + 1].t;
		while (!q.empty() && (i == n || cur < lim)) {
			task t = q.top();
			q.pop();
			i64 delta = min((i64)t.s, lim - cur);
			t.s -= delta;
			cur += delta;
			if (t.s) q.push(t);
			else ddl[t.id] = cur;
		}
	}
	return ddl[a[sp].id] <= T;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &a[i].t, &a[i].s, &a[i].p);
		a[i].id = i;
		if (a[i].p != -1) s.insert(a[i].p), a[i].p *= 2;
	}
	sort(a + 1, a + 1 + n, compareByT);
	for (int i = 1; i <= n; i++) if (a[i].p == -1) sp = i;
	cin >> T;
	int l = 1, r = 1000000000;
	while (l < r) {
		int mid = l + r >> 1;
		if (check(2 * mid + 1)) r = mid;
		else l = mid + 1;
	}
	while (s.count(r)) r++;
	check(2 * r);
	printf("%d\n", r);
	for (int i = 1; i <= n; i++) printf("%I64d%c", ddl[i], " \n"[i == n]);
}