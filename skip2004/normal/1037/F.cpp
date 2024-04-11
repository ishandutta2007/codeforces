#include<bits/stdc++.h>
const int maxn = 1001000;
const int mod = 1e9 + 7;
using std::cin;
using std::cout;
typedef long long ll;

int st[20][maxn], lg[maxn];
int a[maxn];
int n, k;
inline int max(int x, int y) {
	return a[x] > a[y] ? x : y;
}
inline int gmax(int l, int r) {
	const int lg = ::lg[r - l + 1];
	return max(st[lg][l], st[lg][r - (1 << lg) + 1]);
}

inline ll sumr(int n, int x) {
	ll sum = n / (k - 1ll) * x, v = x - n;

	const int L = (-v + k - 2) / (k - 1), R = n / (k - 1);
	if(L <= R) sum -= v * (R - L + 1ll) + (L + R) * (R - L + 1ll) / 2 * (k - 1);
	return sum;
}
inline ll suml(int n, int x) {
	const int L = 1, R = (x - 1) / (k - 1);
	return (x - 1ll) * (R - L + 1) - (L + R) * (R - L + 1ll) / 2 * (k - 1);
}
inline ll solve(int l, int r) {
	if(l > r) return 0;
	int mid = gmax(l, r);
	ll ans = solve(l, mid - 1) + solve(mid + 1, r) + (sumr(r - l + 1, mid - l + 1) - suml(r - l + 1, mid - l + 1)) % mod * a[mid];
	return ans % mod;
}
int main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	cin >> n >> k;
	for(int i = 1;i <= n;++i) {
		cin >> a[i];
		st[0][i] = i;
	}
	for(int i = 1;i < 20;++i) {
		for(int j = 1;j + (1 << i) - 1 <= n;++j) {
			st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << i - 1)]);
		}
	}
	lg[0] = -1;
	for(int i = 1;i <= n;++i) {
		lg[i] = lg[i >> 1] + 1;
	}
	cout << solve(1, n) << '\n';
}