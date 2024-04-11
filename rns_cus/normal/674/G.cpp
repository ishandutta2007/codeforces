#include <bits/stdc++.h>

using namespace std;

#define N 150010
typedef pair<int, int> pii;
typedef vector<pii> VI;

int a[N], n, m, p;
int vis[N], T, sz[N];
int setv[N << 2], K;
VI v[N << 2];

void push_down(int id, int len) {
	if(setv[id]) {
		setv[id << 1] = setv[id];
		v[id << 1].clear(); v[id << 1].push_back(pii(setv[id], (len + 1) >> 1));
		for(int i = 1; i < K; i ++) v[id << 1].push_back(pii(0, 0));
		setv[id << 1 | 1] = setv[id];
		v[id << 1 | 1].clear(); v[id << 1 | 1].push_back(pii(setv[id], len >> 1));
		for(int i = 1; i < K; i ++) v[id << 1 | 1].push_back(pii(0, 0));
		setv[id] = 0;
	}
}

int buf[11];

VI merge(VI a, VI b, int len) {
	for(int j = 0; j < K; j ++) if(b[j].first) {
		int t;
		for(t = 0; t < K; t ++) if(a[t].first == b[j].first) break;
		if(t < K) {
			a[t].second += b[j].second;
			continue;
		}
		int mn = 1e9;
		for(int i = 0; i < K; i ++) {
			if(mn > a[i].second) mn = a[i].second;
		}
		if(mn >= b[j].second) {
			for(int i = 0 ;i < K; i ++) a[i].second -= b[j].second;
		} else {
			for(int i = 0; i < K; i ++) a[i].second -= mn;
			for(int i = 0; i < K; i ++) if(a[i].second == 0) {
				a[i].second = b[j].second - mn;
				a[i].first = b[j].first;
				break;
			}
		}
	}
	return a;
}

void push_up(int id, int len) {
	v[id] = merge(v[id << 1], v[id << 1 | 1], len);
}

void build(int L, int R, int id) {
	if(L == R) {
		v[id].push_back(pii(a[L], R - L + 1));
		for(int i = 1; i < K; i ++) v[id].push_back(pii(0,0));
		return;
	}
	int md = (L + R) >> 1;
	build(L, md, id << 1);
	build(md + 1, R, id << 1 | 1);
	push_up(id, R - L + 1);
}

void modify(int L, int R, int id, int l, int r, int val) {
	if(l <= L && R <= r) {
		setv[id] = val;
		v[id].clear();
		v[id].push_back(pii(val, R - L + 1));
		for(int i = 1; i < K; i ++) v[id].push_back(pii(0,0));
		return;
	}
	push_down(id, R - L + 1);
	int md = (L + R) >> 1;
	if(l <= md) modify(L, md, id << 1, l, r, val);
	if(r > md) modify(md + 1, R, id << 1 | 1, l, r, val);
	push_up(id, R - L + 1);
}

VI ans;
int len;

void query(int L, int R, int id, int l, int r) {
	if(l <= L && R <= r) {
		len += R - L + 1;
		ans = merge(ans, v[id], len);
		return;
	}
	push_down(id, R - L + 1);
	int md = (L + R) >> 1;
	if(l <= md) query(L, md, id << 1, l, r);
	if(r > md) query(md + 1, R, id << 1 | 1, l, r);
}

int main() {
	//freopen("in.txt", "r", stdin);
	scanf("%d%d%d", &n, &m, &p);
	K = 100 / p;
	for(int i = 1; i <= n; i ++) scanf("%d", a + i);
	build(1, n, 1);
	while(m --) {
		int type, l, r, v;
		scanf("%d%d%d", &type, &l, &r);
		if(type == 1) {
			scanf("%d", &v);
			modify(1, n, 1, l, r, v);
		} else {
			len = 0;
			ans.clear();
			for(int i = 0; i < K; i ++) ans.push_back(pii(0, 0));
			query(1, n, 1, l, r);
			printf("%d", (int)ans.size());
			for(int i = 0; i < (int)ans.size(); i ++) printf(" %d", ans[i].first); puts("");
		}
	}
	return 0;
}