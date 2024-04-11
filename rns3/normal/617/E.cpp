#include <bits/stdc++.h>
using namespace std;

#define N 101010
const int K = 550;

int a[N], n, m, k;

long long rlt[N];

int le[N], ri[N];

bool cmp(int i, int j) {
	return ri[i] < ri[j];
}

const int M = 1 << 20;

int cnt[M];
int L, R;
long long ans;

void add(int x, int d) {
	if (k) ans += d * cnt[x^k];
	else if (d > 0) ans += cnt[x];
	else ans -= (cnt[x] - 1);
	cnt[x] += d;
}

void go(int le, int ri) {
	while (ri > R) R ++, add(a[R], 1);
	while (le < L) L --, add(a[L], 1);
	while (ri < R) add(a[R], -1), R --;
	while (le > L) add(a[L], -1), L ++;
}

void solve(vector <int> &v, bool rv) {
	if (rv) sort(v.rbegin(), v.rend(), cmp);
	else sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i ++) {
		go(le[v[i]], ri[v[i]]);
		rlt[v[i]] = ans;
	}
}

vector <int> v[N];

int main() {
	//freopen("r.in", "r", stdin);
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]), a[i] ^= a[i-1];
	for (int i = 1; i <= m; i ++) {
		scanf("%d %d", &le[i], &ri[i]);
		le[i] --;
		v[le[i]/K].push_back(i);
	}
	L = 1, R = 0;
	bool rv = 1;
	for (int i = 0; i < N / K; i ++) if (!v[i].empty()) {
		rv = !rv;
		solve(v[i], rv);
	}
	for (int i = 1; i <= m; i ++) printf("%I64d\n", rlt[i]);

	return 0;
}