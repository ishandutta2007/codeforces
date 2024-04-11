#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 2002;
typedef long long ll;
const int mod = 998244353;
inline ll pow(ll a,int b,int ans = 1) {
	for(;b;b >>= 1,a = a * a % mod) if(b & 1)
		ans = ans * a % mod;
	return ans;
}
inline ll inverse(int x){ return pow(x, mod - 2); }
double dp[maxn][maxn];
int cnt[maxn][maxn];
int n, A, B;
double p[maxn], u[maxn], a[maxn];
inline bool up(double & x, double y) {
	return x < y ? x = y, 1 : 0;
}
std::pair<double, int> get(double val) {
	rep(i, 0, n) rep(j, 0, i) dp[i][j] = -1e9;
	dp[0][0] = 0;
	for(int i = 0;i < n;++i) {
		for(int j = 0;j <= i && j <= A;++j) {
			if(up(dp[i + 1][j], dp[i][j])) cnt[i + 1][j] = cnt[i][j];
			if(up(dp[i + 1][j + 1], dp[i][j] + p[i + 1])) cnt[i + 1][j + 1] = cnt[i][j];
			if(up(dp[i + 1][j], dp[i][j] + u[i + 1] - val)) cnt[i + 1][j] = cnt[i][j] + 1;
			if(up(dp[i + 1][j + 1], dp[i][j] + a[i + 1] - val)) cnt[i + 1][j + 1] = cnt[i][j] + 1;
		}
	}
	return {dp[n][A], cnt[n][A]};
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> A >> B;
	rep(i, 1, n) {
		cin >> p[i];
	}
	rep(i, 1, n) {
		cin >> u[i];
		a[i] = 1 - (1 - p[i]) * (1 - u[i]);
	}
	double l = -0.1, r = 1.1;
	for(int i = 0;i <= 400;++i) {
		double mid = (l + r) / 2;
		if(get(mid).second <= B) {
			r = mid;
		} else {
			l = mid;
		}
	}
	auto ans = get(r);
	printf("%.8lf\n", ans.first + B * r);
}