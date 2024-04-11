#include <bitset>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define N 155

struct Matrix {
	bitset <N> v[N];
	Matrix() {
		for (int i = 0; i < N; i ++) v[i].reset();
	}
	void makeI() {
		for (int i = 0; i < N; i ++) v[i][i] = 1;
	}
} M;

Matrix operator * (const Matrix &a, const Matrix &b) {
	Matrix c, tmp;
	for (int i = 0; i < N; i ++) {
		for (int j = 0; j < N; j ++) {
			if (b.v[i][j]) tmp.v[j][i] = 1;
			else tmp.v[j][i] = 0;
		}
	}
	for (int i = 0; i < N; i ++) {
		for (int j = 0; j < N; j ++) {
			c.v[i][j] = (a.v[i] & tmp.v[j]).any();
		}
	}
	return c;
}

Matrix operator ^ (Matrix a, int p) {
	Matrix rlt;
	rlt.makeI();
	for (int i = p; i; i >>= 1) {
		if (i & 1) rlt = rlt * a;
		a = a * a;
	}
	return rlt;
}

bitset <N> operator * (const Matrix &a, bitset <N> v) {
	bitset <N> rlt;
	rlt.reset();
	for (int i = 0; i < N; i ++) if (v[i]) {
		rlt |= a.v[i];
	}
	return rlt;
}

int a[N], b[N], d[N];
int sto[N], cnt;

bitset <N> bit;

vector <int> V[N];
int Q[N];
int dist[N], n, m;

int BFS() {
	int h = 1, t = 0;
	for (int i = 0; i < n; i ++) if (bit[i]) {
		dist[i] = 0;
		Q[++ t] = i;
	}
	while (h <= t) {
		int cur = Q[h ++];
		if (cur == n - 1) return dist[cur];
		for (int i = 0; i < V[cur].size(); i ++) {
			int nxt = V[cur][i];
			if (dist[nxt] >= 0) continue;
			dist[nxt] = dist[cur] + 1;
			Q[++ t] = nxt;
		}
	}
	return -1;
}

main() {
	scanf("%d %d", &n, &m);
	sto[cnt ++] = 0;
	for (int i = 0; i < m; i ++) {
		scanf("%d %d %d", a + i, b + i, d + i);
		a[i] --, b[i] --;
		sto[cnt ++] = d[i];
	}

	sort(sto, sto + cnt);
	cnt = unique(sto, sto + cnt) - sto;
	bit.reset();
	bit[0] = 1;

	for (int i = 0, j; i < cnt - 1; i ++) {
		for (j = 0; j < n; j ++) {
			V[j].clear();
			dist[j] = -1;
		}
		for (j = 0; j < m; j ++) {
			if (d[j] <= sto[i]) {
				M.v[a[j]][b[j]] = 1;
				V[a[j]].push_back(b[j]);
			}
		}
		int tmp = BFS();
		if (tmp >= 0 && sto[i] + tmp < sto[i + 1]) {
			printf("%d\n", sto[i] + tmp);
			return 0;
		}
		bit = (M ^ (sto[i + 1] - sto[i])) * bit;
	}

	for (int i = 0; i < n; i ++) {
		V[i].clear();
		dist[i] = -1;
	}
	for (int i = 0; i < m; i ++) {
		V[a[i]].push_back(b[i]);
	}
	int tmp = BFS();
	if (tmp >= 0) printf("%d\n", sto[cnt - 1] + tmp);
	else puts("Impossible");
}