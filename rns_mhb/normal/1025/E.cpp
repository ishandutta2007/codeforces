#include <bits/stdc++.h>
using namespace std;

#define N 55

int x[N], y[N];
int id[N][N];
int tx[N], ty[N];
int n, m;

int rk[N];
bool cmp(int i, int j) {
	if (tx[i] != tx[j]) return tx[i] > tx[j];
	return ty[i] > ty[j];
}

int e;
struct MOVE {
	int x, y, xx, yy;
	MOVE(int x = 0, int y = 0, int xx = 0, int yy = 0) : x(x), y(y), xx(xx), yy(yy) {}
	void print() {printf("%d %d %d %d\n", x, y, xx, yy);}
} mov[1010101];

void put_ans() {
	printf("%d\n", e);
	for (int i = 1; i <= e; i ++) mov[i].print();
}

bool move_x(int i, int d, bool iff = 0) {
	assert(id[x[i]][y[i]] == i);
	id[x[i]][y[i]] = 0;
	x[i] += d;
	if(id[x[i]][y[i]] == 0) {
		id[x[i]][y[i]] = i;
		mov[++e] = MOVE(x[i] - d, y[i], x[i], y[i]);
		return 1;
	}
	else {
		assert(iff);
		x[i] -= d;
		id[x[i]][y[i]] = i;
		return 0;
	}
}

bool move_y(int i, int d, bool iff = 0) {
	assert(id[x[i]][y[i]] == i);
	id[x[i]][y[i]] = 0;
	y[i] += d;
	if(id[x[i]][y[i]] == 0) {
		id[x[i]][y[i]] = i;
		mov[++e] = MOVE(x[i], y[i] - d, x[i], y[i]);
		return 1;
	}
	else {
		assert(iff);
		y[i] -= d;
		id[x[i]][y[i]] = i;
		return 0;
	}
}

int q[N];

void put_all_in_first_line() {
	int st = 1;
	for (int i = 1; i <= n; i ++) {
		int en = st - 1;
		for (int j = 1; j <= n; j ++) if (id[i][j]) q[++en] = id[i][j];
		for (int j = st; j <= en; j ++) {
			while (y[q[j]] > j) move_y(q[j], -1);
		}
		for (int j = en; j >= st; j --) {
			while (y[q[j]] < j) move_y(q[j], 1);
		}
		for (int j = st; j <= en; j ++) {
			while (x[q[j]] > 1) move_x(q[j], -1);
		}
		st = en + 1;
	}
}

void operate_from_3_to_n() {
	for (int k = 1; k <= m; k ++) {
		if (tx[rk[k]] < 3) break;
		move_x(rk[k], 1);
		while (y[rk[k]] < ty[rk[k]]) move_y(rk[k], 1);
		while (y[rk[k]] > ty[rk[k]]) move_y(rk[k], -1);
		while (x[rk[k]] < tx[rk[k]]) move_x(rk[k], 1);
	}
}

void operate_final() {
	int cnt = 0;
	for (int j = 1; j <= n; j ++) if (id[1][j]) q[++cnt] = id[1][j];
	for (int k = 1; k <= cnt; k ++) {
		while (y[q[k]] > k) move_y(q[k], -1);
	}
	for (int k = 1; k <= cnt; k ++) {
		int mn = k;
		for (int h = k + 1; h <= cnt; h ++) {
			if (ty[q[h]] < ty[q[mn]]) mn = h;
		}
		if (mn != k) {
			int tmp = q[mn];
			move_x(tmp, 1);
			while (y[tmp] > k) move_y(tmp, -1);
			for (int h = mn - 1; h >= k; h --) {
				move_y(q[h], 1);
				q[h+1] = q[h];
			}
			q[k] = tmp;
			move_x(tmp, -1);
		}
	}
	for (int k = 1; k <= cnt; k ++) if (tx[q[k]] == 2) move_x(q[k], 1);
	for (int k = 1; k <= cnt; k ++) {
		while (y[q[k]] > ty[q[k]]) move_y(q[k], -1);
	}
	for (int k = cnt; k >= 1; k --) {
		while (y[q[k]] < ty[q[k]]) move_y(q[k], 1);
	}
}

int X[N], Y[N];

bool check() {
	memset(id, 0, sizeof id);
	for (int i = 1; i <= m; i ++) x[i] = X[i], y[i] = Y[i], id[x[i]][y[i]] = i;
	for (int i = 1; i <= e; i ++) {
		int tmp = id[mov[i].x][mov[i].y];
		id[mov[i].x][mov[i].y] = 0;
		x[tmp] = mov[i].xx, y[tmp] = mov[i].yy;
		if (id[x[tmp]][y[tmp]]) return 0;
		id[x[tmp]][y[tmp]] = tmp;
	}
	for (int i = 1; i <= m; i ++) {
		if (tx[i] != x[i] || ty[i] != y[i]) return 0;
	}
	return 1;
}

int main() {
	//freopen("r.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i ++) scanf("%d %d", &x[i], &y[i]), id[x[i]][y[i]] = i, X[i] = x[i], Y[i] = y[i];
	for (int i = 1; i <= m; i ++) scanf("%d %d", &tx[i], &ty[i]), rk[i] = i;
	put_all_in_first_line();
	sort(rk + 1, rk + m + 1, cmp);
	operate_from_3_to_n();
	operate_final();
	put_ans();
	//assert(check());

	return 0;
}