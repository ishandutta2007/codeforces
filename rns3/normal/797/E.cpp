#include <bits/stdc++.h>
using namespace std;

#define N 101010

int a[N], f[N];

int n, q;
int p[N], k[N];
const int K = 270;

int ans[N];

vector <int> v[K+1];

bool cmp(int i, int j) {
	return p[i] > p[j];
}

int main() {
	//freopen("r.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	scanf("%d", &q);
	for (int i = 1; i <= q; i ++) scanf("%d %d", &p[i], &k[i]);
	for (int i = 1; i <= q; i ++) {
		if (k[i] > K) {
			int now = p[i], rlt = 0;
			while (now <= n) rlt ++, now = now + a[now] + k[i];
			ans[i] = rlt;
		}
		else {
			v[k[i]].push_back(i);
		}
	}
	for (int k = 1; k <= K; k ++) {
		sort(v[k].begin(), v[k].end(), cmp);
		int cur = 0, sz = v[k].size();
		for (int i = n; i >= 1 && cur < sz; i --) {
			int j = i + a[i] + k;
			f[i] = (j > n) ? 1 : (1 + f[j]);
			while (cur < sz && p[v[k][cur]] == i) ans[v[k][cur]] = f[i], cur ++;
		}
	}
	for (int i = 1; i <= q; i ++) printf("%d\n", ans[i]);


	return 0;
}