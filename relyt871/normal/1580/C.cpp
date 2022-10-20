#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int MAXN = 200005;
const int LIM = 450;

template <typename T> inline void read(T &WOW) {
	T x = 0, flag = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') flag = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	WOW = flag * x;
}

int n, m, x[MAXN], y[MAXN], start[MAXN];
int cnt1[MAXN], cnt2[LIM + 5][LIM + 5];

void solve() {
	read(n); read(m);
	for (int i = 1; i <= n; ++i) {
		read(x[i]); read(y[i]);
	}
	for (int i = 1, op, k, p; i <= m; ++i) {
		cnt1[i] += cnt1[i - 1];
		read(op); read(k);
		p = x[k] + y[k];
		if (op == 1) {
			start[k] = i;
			if (p <= LIM) {
				for (int j = i + x[k]; j <= i + p - 1; ++j) {
					++cnt2[p][j % p];
				}
			} else {
				for (int j = i + x[k]; j <= m; j += p) {
					++cnt1[j];
					if (j + y[k] <= m) {
						--cnt1[j + y[k]];
					}
				}
			}
		} else {
			if (p <= LIM) {
				for (int j = start[k] + x[k]; j <= start[k] + p - 1; ++j) {
					--cnt2[p][j % p];
				}
			} else {
				int flag = 0;
				for (int j = start[k] + x[k]; j <= m; j += p) {
					--cnt1[j];
					flag += (j < i);
					if (j + y[k] <= m) {
						++cnt1[j + y[k]];
						flag -= (j + y[k] < i);
					}
				}
				cnt1[i] -= flag;
			}
		}
		int ans = cnt1[i];
		for (int j = 2; j <= LIM; ++j) {
			ans += cnt2[j][i % j];
		}
		printf("%d\n", ans);
	}
}

int main() {
	solve();
	return 0;
}