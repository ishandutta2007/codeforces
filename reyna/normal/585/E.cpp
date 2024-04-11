//In the name of God
// Break through! I screamed forth from my soul!

#include <bits/stdc++.h>
using namespace std;

const int M = 1e7 + 9;
const int N = 5e5 + 9;
const int mod = 1e9 + 7;
int a[N], id[256], cnt[M], is[M], sp[M];
short sz[M];
int pw[N];
int pre[256];
int cur = 0;
int anskol = 0;

int do_pow(int a, int b) {
	return b? (do_pow((a * 1LL * a) % mod, b >> 1) * 1LL * (b & 1? a: 1)) % mod: 1;	
}

int fix(int x) {
	while (x >= mod)
		x = x - mod;
	while (x < 0)
		x = x + mod;
	return x;	
}

void add(int ind, int p) {
	vector<int> pr;
	int x = a[ind], z = x;
	while (z != 1) {
		pr.push_back(sp[z]);
		z /= sp[z];	
	}
	sort(pr.begin(), pr.end());
	pr.resize(unique(pr.begin(), pr.end()) - pr.begin());
	pre[0] = 1;
	for (int mask = 1; mask < (1 << (int) sz[x]); mask++) {
		pre[mask] = pre[mask - (mask & -mask)] * pr[id[mask & -mask]];
	}
	for (int mask = 0; mask < (1 << (int) sz[x]); mask++) {
		int y = pre[mask];
		if ((int) sz[y] & 1)
			cur = fix(cur + pw[cnt[y]]);
		else
			cur = fix(cur - pw[cnt[y]]);
		cnt[y] = cnt[y] + (p? 1: -1);
		if ((int) sz[y] & 1)
			cur = fix(cur - pw[cnt[y]]);
		else
			cur = fix(cur + pw[cnt[y]]);
	}
}

int32_t main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		pw[i] = do_pow(2, i) - 1;
	}
	pw[n] = do_pow(2, n) - 1;
	for (int i = 0; i < M; i++)
		cnt[i] = 1, is[i] = i;
	for (int i = 2; i * i < M; i++) {
		if (cnt[i] == 1)
			for (int j = i; j < M; j += i) {
				sz[j]++;
				sp[j] = i;
				cnt[j] = 0;
				while (is[j] % i == 0)
					is[j] = is[j] / i;
			}
	}
	memset(cnt, 0, sizeof cnt);
	for (int i = 2; i < M; i++)
		if (is[i] != 1) {
			sz[i]++, sp[i] = is[i];
		}
	for (int i = 0; (1 << i) < 256; i++)
		id[1 << i] = i;
	int res = 0;
	for (int i = 0; i < n; i++) {
		add(i, 1);
	}
	anskol = cur;
	for (int i = 0; i < n; i++) {
		add(i, 0);
		res = (res + 0LL + anskol - cur * 1LL * 2 + 100 * 1LL * mod) % mod;
		add(i, 1);	
	}
	cout << res << '\n';
}