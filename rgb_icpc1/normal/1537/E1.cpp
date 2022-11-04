#include <bits/stdc++.h>

using namespace std;

const int MX = 10005;

int N, K;
char str[MX];

const int LEN = MX * 3;

int r[LEN], sa[LEN];
int wa[LEN], wb[LEN], wv[LEN], ss[LEN];

#define F(x) ((x) / 3 + ((x) % 3 == 1 ? 0 : tb))
#define G(x) ((x) < tb ? (x) * 3 + 1 : ((x) - tb) * 3 + 2)

int c0(int *r, int a, int b) { return r[a] == r[b] && r[a + 1] == r[b + 1] && r[a + 2] == r[b + 2]; }

int c12(int k, int *r, int a, int b) {
	if (k == 2) return r[a] < r[b] || r[a] == r[b] && c12(1, r, a + 1, b + 1);
	return r[a] < r[b] || r[a] == r[b] && wv[a + 1] < wv[b + 1];
}

void sort(int *r, int *a, int *b, int n, int m) {
	for (int i = 0; i < n; i ++) wv[i] = r[a[i]];
	for (int i = 0; i < m; i ++) ss[i] = 0;
	for (int i = 0; i < n; i ++) ss[wv[i]] ++;
	for (int i = 1; i < m; i ++) ss[i] += ss[i - 1];
	for (int i = n - 1; i >= 0; i --) b[-- ss[wv[i]]] = a[i];
}

void DC3(int *r, int *sa, int n, int m) {
	int i, j, p;
	int *san = sa + n, *rn = r + n;
	int ta = 0, tb = (n + 1) / 3, tbc = 0;
	r[n] = r[n + 1] = 0;
	for (i = 0; i < n; i ++) if (i % 3 != 0) wa[tbc ++] = i;
	sort(r + 2, wa, wb, tbc, m);
	sort(r + 1, wb, wa, tbc, m);
	sort(r, wa, wb, tbc, m);
	for (p = 1, rn[F(wb[0])] = 0, i = 1; i < tbc; i ++)
		rn[F(wb[i])] = c0(r, wb[i - 1], wb[i]) ? p - 1 : p ++;
	if (p < tbc) DC3(rn, san, tbc, p);
	else for (i = 0; i < tbc; i ++) san[rn[i]] = i;
	for (i = 0; i < tbc; i ++) if (san[i] < tb) wb[ta ++] = san[i] * 3;
	if (n % 3 == 1) wb[ta ++] = n - 1;
	sort(r, wb, wa, ta, m);
	for (i = 0; i < tbc; i ++) wv[wb[i] = G(san[i])] = i;
	for (i = 0, j = 0, p = 0; i < ta && j < tbc; p ++)
		sa[p] = c12(wb[j] % 3, r, wa[i], wb[j]) ? wa[i ++] : wb[j ++];
	for ( ; i < ta; p ++) sa[p] = wa[i ++];
	for ( ; j < tbc; p ++) sa[p] = wb[j ++];
}

int rnk[MX], lcp[MX];

void calc_LCP(int *r, int *sa, int n) {
	int k = 0;
	for (int i = 0; i < n; i ++) rnk[sa[i]] = i;
	for (int i = 0; i < n - 1; lcp[rnk[i ++]] = k) {
		if (k) k --;
		for (int j = sa[rnk[i] - 1]; r[i + k] == r[j + k]; k ++);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("I", "r", stdin);
	freopen("O", "w", stdout);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int i, j;
	cin >> N >> K >> str;
	for (i = 0; i < N; i++) r[i] = str[i];
	r[N] = 'z' + 1, r[N + 1] = 0;
	N++;
	DC3(r, sa, N + 1, 256);
	calc_LCP(r, sa, N + 1);
	for (i = 0; i < N; i++) {
		if (rnk[i] > rnk[0]) break;
	}
	N = i;
	while (K) {
		int mn = min(N, K);
		for (i = 0; i < mn; i++) cout << str[i];
		K -= mn;
	}
	cout << '\n';

	return 0;

}