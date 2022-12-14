//In the name of God

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)

const int N = 1e5 + 5;
long long dp[N];
int a[N], b[N], n;
int read() { int x; cin >> x; return x; }

long long update(int i, int j) {
	if (i > j)
		swap(i, j);
	return dp[i] + b[i] * 1LL * a[j];
}

int when(int i, int j) {
	if (i > j)
		swap(i, j);
	int bl = j, br = n;
	while (bl < br - 1) {
		int bm = bl + br >> 1;
		if (update(j, bm) <= update(i, bm))
			br = bm;
		else
			bl = bm;
	}
	return br;
}

int h, t, s[N];

int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	n = read();
	rep(i, n)
		a[i] = read();
	rep(i, n)
		b[i] = read();
	dp[0] = 0;
	s[t++] = 0;
	for (int i = 1; i < n; ++i) {
		while (t - h > 1 && when(s[h], s[h + 1]) <= i)
			h++;
		dp[i] = update(s[h], i);
		while (t - h > 1 && when(s[t - 1], s[t - 2]) >= when(s[t - 1], i))
			t--;
		s[t++] = i;
	}
	cout << dp[n - 1];
}