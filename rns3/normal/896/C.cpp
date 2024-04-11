#include <bits/stdc++.h>
using namespace std;

int n, m, seed, vmax;
const int mod = 1e9 + 7;

int rnd() {
	int rlt = seed;
	seed = (1ll * seed * 7 + 13) % mod;
	return rlt;
}

int expmod(int a, int b, int P) {
	int rlt = 1;
	while (b) {
		if (b & 1) rlt = 1ll * a * rlt % P;
		a = 1ll * a * a % P;
		b >>= 1;
	}
	return rlt;
}

#define N 101010

long long a[N], b[N];
int op, le, ri, x, y;

void get_query() {
	op = (rnd() % 4) + 1;
	le = (rnd() % n) + 1;
	ri = (rnd() % n) + 1;
	if (le > ri) swap(le, ri);
	if (op == 3) x = (rnd() % (ri - le + 1)) + 1;
	else x = (rnd() % vmax) + 1;
	if (op == 4) y = (rnd() % vmax) + 1;
}

void put_query() {
	printf("%d %d %d %d", op, le, ri, x);
	if (op == 4) printf(" %d\n", y);
	else puts("");
}

long long add[N<<2], to[N<<2];

void refresh(int id) {
	if (add[id] && to[id] != -1) to[id] += add[id], add[id] = 0;
}

void push_down(int id) {
	refresh(id);
	if (to[id] != -1) {
		to[id<<1] = to[id];
		add[id<<1] = 0;
		to[(id<<1)^1] = to[id];
		add[(id<<1)^1] = 0;
	}
	else {
		add[id<<1] += add[id];
		add[(id<<1)^1] += add[id];
		add[id] = 0;
	}
}

void build(int L, int R, int id) {
	if (L == R) {
		to[id] = a[L];
		return;
	}
	int mid = (L + R) >> 1;
	build(L, mid, id << 1);
	build(mid + 1, R, (id << 1) ^ 1);
}

void update(int le, int ri, int d, int L, int R, int id) {
	if (le > R || L > ri) return;
	if (le <= L && R <= ri) {
		refresh(id);
		if (to[id] != -1) {
			to[id] += d;
			return;
		}
		add[id] += d;
		return;
	}
	int mid = (L + R) >> 1;
	push_down(id);
	to[id] = -1;
	update(le, ri, d, L, mid, id << 1);
	update(le, ri, d, mid + 1, R, (id << 1) ^ 1);
}

void change(int le, int ri, int d, int L, int R, int id) {
	if (le > R || L > ri) return;
	if (le <= L && R <= ri) {
		refresh(id);
		add[id] = 0;
		to[id] = d;
		return;
	}
	int mid = (L + R) >> 1;
	push_down(id);
	to[id] = -1;
	change(le, ri, d, L, mid, id << 1);
	change(le, ri, d, mid + 1, R, (id << 1) ^ 1);
}

vector <pair <long long, int> > v;

void calc(int le, int ri, int L, int R, int id) {
	if (le > R || L > ri) return;
	if (to[id] != -1) {
		refresh(id);
		int len = min(R, ri) - max(L, le) + 1;
		v.push_back(make_pair(to[id], len));
		return;
	}
	int mid = (L + R) >> 1;
	push_down(id);
	to[id] = -1;
	calc(le, ri, L, mid, id << 1);
	calc(le, ri, mid + 1, R, (id << 1) ^ 1);
}

int main() {
	//freopen("r.in", "r", stdin);
	//freopen("11.out", "w", stdout);
	scanf("%d %d %d %d", &n, &m, &seed, &vmax);
	for (int i = 1; i <= n; i ++) a[i] = (rnd() % vmax) + 1;
	memset(to, -1, sizeof to);
	build(1, n, 1);
	while (m --) {
		get_query();
		//put_query();
		if (op == 1) {
			update(le, ri, x, 1, n, 1);
			continue;
		}
		if (op == 2) {
			change(le, ri, x, 1, n, 1);
			continue;
		}
		v.clear();
		calc(le, ri, 1, n, 1);
		sort(v.begin(), v.end());
		if (op == 3) {
			int tot = 0;
			for (int i = 0; i < v.size(); i ++) {
				tot += v[i].second;
				if (tot >= x) {
					printf("%I64d\n", v[i].first);
					break;
				}
			}
		}
		else {
			int ans = 0;
			long long g;
			int h;
			for (int i = 0; i < v.size(); ) {
				g = v[i].first;
				h = v[i].second;
				i ++;
				while (i < v.size() && g == v[i].first) {
					h += v[i].second;
					i ++;
				}
				ans = (ans + 1ll * expmod(g % y, x, y) * h) % y;
			}
			printf("%d\n", ans);
		}
	}


	return 0;
}