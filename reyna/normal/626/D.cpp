//In the name of God

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }


constexpr int N = 5e4 + 5, S = 2e4 + 2;

int read() { int x; cin >> x; return x; }

double cnt[N], dp[N];
int a[N];


int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) if (j != i) {
			cnt[abs(a[i] - a[j])] += 1;
		}
	}
	for (int i = 0; i < 5005; ++i) {
		cnt[i] = cnt[i] / n / (n - 1);
	}
	for (int i = 0; i < 5005; ++i)
		for (int j = 0; j < 5005; ++j)
			dp[i + j] += cnt[i] * cnt[j];
	double res = 0, sum = 0;
	for (int i = 0; i < N; ++i)
		res += cnt[i] * sum, sum += dp[i];
	cout << setprecision(7) << fixed << res;
	
	
}