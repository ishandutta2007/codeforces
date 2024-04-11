#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

#define int ll

const int MAXN = 1e6 + 228;
int dp[MAXN];

int a, b, c, d;

void read() {
	cin >> a >> b >> c >> d;
}

void add(int l, int r) {
	dp[l]++;
	dp[r + 1]--;
	//for (int i = l; i <= r; i++) {
	//	dp[i]++;
	//}
}

void build() {
	for (int i = b; i <= c; i++) {
		add(i + a, i + b);
	}
	for (int i = 1; i < MAXN; i++)
		dp[i] += dp[i - 1];
}

int ans;

void run() {
	build();
	ans = 0;
	for (int i = MAXN - 1; i >= 0; i--)
		dp[i] += dp[i + 1];
	for (int i = c; i <= d; i++) {
		ans += dp[i + 1];
	}
}

void write() {
	cout << ans << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read();
	run();
	write();
	return 0;
}