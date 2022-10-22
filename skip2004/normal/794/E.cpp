#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 300200;
typedef long long ll;
const int mod = 998244353;
typedef int AI[maxn];
int n;
AI a, s0[20], s1[20];
inline int ask(AI * s, int l, int r) {
	const int lg = std::__lg(r - l + 1);
	return std::max(s[lg][l], s[lg][r - (1 << lg) + 1]);
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	int max = 0;
	rep(i, 1, n) {
		cin >> a[i];
		max = std::max(max, a[i]);
	}
	rep(i, 1, n) {
		s0[0][i] = std::max(a[i], a[i + 1]);
		s1[0][i] = std::min(a[i], std::max(a[i - 1], a[i + 1]));
	}
	for(int i = 1;i < 20;++i) {
		for(int j = 1;j + (1 << i) - 1 <= n;++j) {
			s0[i][j] = std::max(s0[i - 1][j], s0[i - 1][j + (1 << i - 1)]);
			s1[i][j] = std::max(s1[i - 1][j], s1[i - 1][j + (1 << i - 1)]);
		}
	}
	for(int i = 0;i + 1 < n;++i) {
		int left_mid = 1 + n - i >> 1, right_mid = 1 + n + i >> 1;
		cout << ask(n - i & 1 ? s1 : s0, left_mid, right_mid) << ' ';
	}
	cout << max << '\n';
}