#include <bits/stdc++.h>
using namespace std;

#define N 303030

const int INF = 2e9;

int n, m, a[N], k[N];

int le[N<<2], ri[N<<2];

vector <pair <int, int> > qr[N<<2], ql[N<<2];
vector <int> v[N];

void build(int L, int R, int id) {
	le[id] = L, ri[id] = R;
	if (L == R) return;
	int mid = (L + R) >> 1;
	build(L, mid, id << 1);
	build(mid + 1, R, (id << 1) ^ 1);
}

bool insert(int x, int y, int i, int id) {
	if (y < le[id] || x > ri[id]) return 0;
	int mid = (le[id] + ri[id]) >> 1;
	if (mid >= x && mid <= y) {
		qr[id].push_back(make_pair(y, i));
		ql[id].push_back(make_pair(x, i));
		return 1;
	}
	if (insert(x, y, i, id << 1)) return 1;
	if (insert(x, y, i, (id << 1) ^ 1)) return 1;
	//return 0;
}

int ans[N];
void put_ans() {
	for (int i = 1; i <= m; i ++) printf("%d\n", ans[i]);
}

int cnt[N], tot;
set <pair <int, int> > S;
set <pair <int, int> > :: iterator it;
void clear(int le, int ri) {
	S.clear();
	tot = 0;
	for (int i = le; i <= ri; i ++) cnt[a[i]] = 0;
}

void add(int x) {
	it = S.find(make_pair(-cnt[x], x));
	if (it != S.end()) S.erase(it);
	cnt[x] ++;
	tot ++;
	S.insert(make_pair(-cnt[x], x));
}

void calc(int id) {
	it = S.begin();
	int x;
	while (it != S.end()) {
		x = it -> second;
		if (cnt[x] * k[id] <= tot) break;
		v[id].push_back(x);
		it ++;
	}
}

void __solve(int id) {
	int L = le[id], R = ri[id], mid = (L + R) >> 1;

	sort(qr[id].begin(), qr[id].end());
	int i = 0, j = mid, sz = qr[id].size();
	do {
		while (i < sz && qr[id][i].first == j) {
			calc(qr[id][i].second);
			i ++;
		}
		j ++;
		add(a[j]);
	} while (j <= R && i < sz);
	clear(mid + 1, R);

	sort(ql[id].rbegin(), ql[id].rend());
	i = 0, j = mid + 1, sz = ql[id].size();
	do {
		while (i < sz && ql[id][i].first == j) {
			calc(ql[id][i].second);
			i ++;
		}
		j --;
		add(a[j]);
	} while (j >= L && i < sz);
	clear(L, mid);
}

void solve(int id) {
	__solve(id);
	if (le[id] == ri[id]) return;
	solve(id << 1);
	solve((id << 1) ^ 1);
}

vector <int> u[N];
int st[N], en[N];

int yourcount(int to, int x) {
	int rlt = lower_bound(u[x].begin(), u[x].end(), to + 1) - u[x].begin();
	return rlt;
}

int mycount(int st, int en, int x) {
	return yourcount(en, x) - yourcount(st - 1, x);
}

void calc_final() {
	for (int i = 1; i <= n; i ++) u[a[i]].push_back(i);
	for (int i = 1; i <= m; i ++) {
		ans[i] = INF;
		for (int j = 0, x, cnt; j < v[i].size(); j ++) {
			x = v[i][j];
			cnt = mycount(st[i], en[i], x);
			if (cnt * k[i] > en[i] - st[i] + 1) ans[i] = min(ans[i], x);
		}
		if (ans[i] == INF) ans[i] = -1;
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	build(1, n, 1);
	for (int i = 1, x, y; i <= m; i ++) {
		scanf("%d %d %d", &x, &y, &k[i]);
		insert(x, y, i, 1);
		st[i] = x, en[i] = y;
	}
	solve(1);
	calc_final();
	put_ans();

	return 0;
}