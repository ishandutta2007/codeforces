#include <bits/stdc++.h>
using namespace std;

struct Query {
	int x, y, t;
	Query(int x = 0, int y = 0, int t = 0) : x(x), y(y), t(t) {}
};

int dist(Query q, int le, int ri) {
	return abs(le - q.x) + abs(ri - q.y);
}

#define N 101010

Query q[N], p[N];

int ans[N];

int n, Q, m, e;
int a[N], A[N];

int b[N<<1];
map <int, int> mp;

int flag[N];
vector <int> v;

int cnt[N<<1], gas[N];

void add(int x, int val = 1) {
	gas[cnt[x]] --;
	cnt[x] += val;
	gas[cnt[x]] ++;
}

int calc() {
	int rlt = 1;
	while (gas[rlt]) rlt ++;
	return rlt;
}

void init() {
	memset(cnt, 0, sizeof cnt);
	memset(gas, 0, sizeof gas);
}

void solve(int le, int ri) {
	for (int i = 1; i <= n; i ++) a[i] = A[i];
	init();
	int sz = v.size();
	for (int i = le; i <= ri; i ++) add(a[i]);
	int cur = 0;
	for (int k = 0, x, y; k <= m && cur < sz; k ++) {
		if (k) {
			x = p[k].x;
			y = p[k].y;
			if (x < le || x > ri) a[x] = y;
			else {
				add(a[x], -1);
				a[x] = y;
				add(y);
			}
		}
		while (cur < sz && q[v[cur]].t == k) {
			int L = q[v[cur]].x, R = q[v[cur]].y;
			if (L < le) for (int i = le - 1; i >= L; i --) add(a[i]);
			else for (int i = le; i < L; i ++) add(a[i], -1);
			if (R > ri) for (int i = ri + 1; i <= R; i ++) add(a[i]);
			else for (int i = ri; i > R; i --) add(a[i], -1);
			ans[v[cur]] = calc();
			if (L < le) for (int i = le - 1; i >= L; i --) add(a[i], -1);
			else for (int i = le; i < L; i ++) add(a[i]);
			if (R > ri) for (int i = ri + 1; i <= R; i ++) add(a[i], -1);
			else for (int i = ri; i > R; i --) add(a[i]);
			cur ++;
		}
	}
}

int main() {
//	freopen("r.in", "r", stdin);
	scanf("%d %d", &n, &Q);
	int cnt = 0;
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]), b[++cnt] = a[i];
	int x, y, type;
	while (Q --) {
		scanf("%d %d %d", &type, &x, &y);
		if (type == 1) q[++e] = Query(x, y, m);
		else {
			m ++;
			p[m] = Query(x, y, m);
			b[++cnt] = y;
		}
	}
	sort(b + 1, b + cnt + 1);
	int num = 0;
	for (int i = 1; i <= cnt; i ++)	if (i == 1 || b[i] > b[i-1]) mp[b[i]] = ++num;

	for (int i = 1; i <= n; i ++) A[i] = mp[a[i]];
	for (int i = 1; i <= m; i ++) p[i].y = mp[p[i].y];

	int u = 0;
	int K = min(n, max(3000, (int)sqrt(n)));
	for (int i = K; i < n; i += K) flag[++u] = i;
	flag[++u] = n;

	for (int i = 1, le; i <= u; i ++) {
		le = flag[i-1] + 1;
		for (int j = i, ri; j <= u; j ++) {
			ri = flag[j];
			for (int k = 1; k <= e; k ++) if (!ans[k] && dist(q[k], le, ri) <= K + 1) v.push_back(k);
			solve(le, ri);
			v.clear();
		}
	}
	for (int i = 1; i <= e; i ++) printf("%d\n", ans[i]);


	return 0;
}