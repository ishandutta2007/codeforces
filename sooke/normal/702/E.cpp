#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>

typedef long long lol;
typedef long double lod;

void openFile() {
	freopen("graph.in", "r", stdin);
	freopen("graph.out", "w", stdout);
}
void closeFile() {
	fclose(stdin);
	fclose(stdout);
}

inline char readLetter() {
	char c = getchar();
	while ((c < 'A' || c > 'Z') && (c < 'a' || c > 'z')) { c = getchar(); }
	return c;
}
inline lol read() {
	char c = getchar(); lol n = 0; bool f = 0;
	while (c < '0' || c > '9') { if (c == '-') { f = 1; } c = getchar(); }
	while (c >= '0' && c <= '9') { n = (n << 1) + (n << 3) + (c & 15); c = getchar(); }
	return f ? -n : n;
}

const int maxInt = 2147483647;
const lol maxLongLong = 9223372036854775807LL;
const int maxN = 100005;

std::vector<int> lop[maxN];
int n, num, siz, a[maxN], val[maxN], st[19][maxN], vis[maxN], ansm[maxN];
lol m, pre[maxN], anss[maxN];
bool used[maxN];

struct List {
	int len, fst[maxN], nxt[maxN << 1], v[maxN << 1], w[maxN << 1];
	List() { memset(fst, -1, sizeof(fst)); len = 0; }
	inline void insert(int uu, int vv, int ww) { v[len] = vv, w[len] = ww, nxt[len] = fst[uu], fst[uu] = len++; }
} ls;

struct SegmentTree {
	lol	sum[maxN << 2];
	int min[maxN << 2];
	
	inline void pushUp(int u) { sum[u] = sum[u << 1] + sum[u << 1 | 1], min[u] = std::min(min[u << 1], min[u << 1 | 1]); }
	void modify(int u, int l, int r, int p, int k) {
		if (l == r) { sum[u] = min[u] = k; }
		else {
			int mid = l + r >> 1;
			if (p <= mid) { modify(u << 1, l, mid, p, k); }
			else { modify(u << 1 | 1, mid + 1, r, p, k); }
			pushUp(u);
		}
	}
	void query(int u, int l, int r, int pl, int pr, lol &ress, int &resm) {
		if (l == pl && r == pr) { ress += sum[u], resm = std::min(resm, min[u]); }
		else {
			int mid = l + r >> 1;
			if (pr <= mid) { query(u << 1, l, mid, pl, pr, ress, resm); }
			else if (pl > mid) { query(u << 1 | 1, mid + 1, r, pl, pr, ress, resm); }
			else {
				query(u << 1, l, mid, pl, mid, ress, resm);
				query(u << 1 | 1, mid + 1, r, mid + 1, pr, ress, resm);
			}
		}
	}
} tr;

void newLoop(int u, int s) {
	lop[num].push_back(u);
	used[u] = true;
	if (a[u] != s) { newLoop(a[u], s); }
}
void findLoop(int u, int s) {
	if (vis[u] == s) { num++, newLoop(u, u); return; }
	if (vis[u] > 0) { return; }
	vis[u] = s;
	findLoop(a[u], s);
}

void buildST() {
	int lg = floor(log(siz) / log(2.0));
	for (int i = 1; i <= lg; i++) {
		for (int j = 1; j <= siz - (1 << i) + 1; j++) {
			st[i][j] = std::min(st[i - 1][j], st[i - 1][j + (1 << i - 1)]);
		}
	}
}
inline void queryST(int l, int r, int &res) {
	int lg = floor(log(r - l + 1) / log(2.0));
	res = std::min(res, std::min(st[lg][l], st[lg][r - (1 << lg) + 1]));
}

inline void extraQuery(int pos, lol k, lol &ress, int &resm) {
	if (k >= siz) {
		ress += pre[siz] * (k / siz);
		queryST(1, siz, resm);
		k %= siz;
	}
	if (k == 0) { return; }
	if (k + pos - 1 > siz) {
		ress += pre[siz] - pre[pos - 1];
		queryST(pos, siz, resm);
		k -= siz - pos + 1;
		ress += pre[k];
		queryST(1, k, resm);
	} else {
		ress += pre[k + pos - 1] - pre[pos - 1];
		queryST(pos, k + pos - 1, resm);
	}
}
void dfs(int u, int s, int pos, int dep) {
	used[u] = true, ansm[u] = maxInt;
	if (dep >= m) {
		tr.query(1, 1, n, dep - m + 1, dep, anss[u], ansm[u]);
	} else {
		if (dep >= 1) { tr.query(1, 1, n, 1, dep, anss[u], ansm[u]); }
		extraQuery(pos, m - dep, anss[u], ansm[u]);
	}
	for (int i = ls.fst[u]; i != -1; i = ls.nxt[i]) {
		int v = ls.v[i];
		if (!used[v]) {
			tr.modify(1, 1, n, dep + 1, val[v]);
			dfs(v, s, pos, dep + 1);
			tr.modify(1, 1, n, dep + 1, 0);
		}
	}
}

int main() {
//	openFile();
	// 100 pts.
	n = read(), m = read();
	for (int i = 1; i <= n; i++) { a[i] = read() + 1; }
	for (int i = 1; i <= n; i++) { val[i] = read(); ls.insert(a[i], i, val[i]); }
	for (int i = 1; i <= n; i++) { if (!vis[i]) { findLoop(i, i); } }
	for (int numi = 1; numi <= num; numi++) {
		st[0][1] = pre[1] = val[lop[numi][0]];
		siz = lop[numi].size();
		for (int i = 1; i < siz; i++) {
			pre[i + 1] = pre[i] + val[lop[numi][i]];
			st[0][i + 1] = val[lop[numi][i]];
		}
		buildST();
		for (int i = 0; i < siz; i++) { dfs(lop[numi][i], lop[numi][i], i + 1, 0); }
	}
	for (int i = 1; i <= n; i++) { printf("%I64d %d\n", anss[i], ansm[i]); }
//	closeFile();
	return 0;
}