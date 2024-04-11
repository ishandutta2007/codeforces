#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;
typedef pair <pii, int> ppp;

int a[100010];
vector <int> fac[100010];
int prime[100010], minp[100010], mine[100010], vis[100010], tot;
int cnt[100010], ccc[100010], maxj, ans[100010];
ppp qry[100010];
int f[100010][17];

void precalc(int N = 100000) {
	for (int i = 2; i <= N; i++) {
		if (!vis[i]) prime[tot++] = i, minp[i] = i, mine[i] = i;
		for (int j = 0; j < tot && i * prime[j] <= N; j++) {
			vis[i * prime[j]] = 1, minp[i * prime[j]] = mine[i * prime[j]] = prime[j];
			if (i % prime[j] == 0) {
				mine[i * prime[j]] = mine[i] * prime[j];
				break;
			}
		}
	}
}

void GetFac(int n, vector <int> &fac) {
	while (n != 1) fac.push_back(minp[n]), n /= mine[n];
}

void Modify(int x, int flag) {
	for (auto p : fac[x]) {
		int &c = cnt[p];
		ccc[c]--, c += flag, ccc[c]++;
		maxj = max(maxj, c);
		if (!ccc[maxj]) maxj--;
	}
}

int main() {
	precalc();
	int n, q; scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), GetFac(a[i], fac[i]);
	ccc[0] = tot;
	int pos = 0;
	for (int i = 1; i <= n; i++) {
		while (pos <= n && maxj <= 1) Modify(++pos, 1);
		f[i][0] = pos, Modify(i, -1);
	}
	f[n + 1][0] = n + 1;
	for (int j = 1; j < 17; j++) for (int i = 1; i <= n + 1; i++) f[i][j] = f[f[i][j - 1]][j - 1];
	for (int i = 1; i <= q; i++) {
		int l, r, cnt = 0; scanf("%d%d", &l, &r);
		for (int j = 16; j >= 0; j--) if (f[l][j] <= r) cnt += 1 << j, l = f[l][j];
		printf("%d\n", cnt + 1);
	}
	return 0;
}