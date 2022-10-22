#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 100005;
typedef long long ll;
const int mod = 998244353;
inline ll pow(ll a,int b,int ans = 1) {
	for(;b;b >>= 1,a = a * a % mod) if(b & 1)
		ans = ans * a % mod;
	return ans;
}
inline ll inverse(int x){ return pow(x, mod - 2); }
int h[maxn], num;
int a[maxn], n;
int left[maxn], right[maxn];
int lb[20][maxn], rb[20][maxn];
typedef int AII[17][maxn];
AII min[17], max[17];
struct T { int l, r; };
inline int askmin(AII & a, int l, int r) { const int lg = std::__lg(r - l + 1); return std::min(a[lg][l], a[lg][r - (1 << lg) + 1]); }
inline int askmax(AII & a, int l, int r) {
	const int lg = std::__lg(r - l + 1);
	return std::max(a[lg][l], a[lg][r - (1 << lg) + 1]);
}
inline int qmin(AII & a, int l, int r) {
	if(l < 1) {
		if(r <= n) return std::min(askmin(a, std::max(l + n, 1), n) - n, askmin(a, 1, r));
		else return askmin(a, 1, n);
	} else {
		if(r <= n) return askmin(a, l, r);
		else return std::min(askmin(a, l, n), askmin(a, 1, std::min(r, r - n)) + n);
	}
}
inline int qmax(AII & a, int l, int r) {
	if(l < 1) {
		if(r <= n) return std::max(askmax(a, std::max(l + n, 1), n) - n, askmax(a, 1, r));
		else return askmax(a, 1, n);
	} else {
		if(r <= n) return askmax(a, l, r);
		else return std::max(askmax(a, l, n), askmax(a, 1, std::min(r, r - n)) + n);
	}
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	rep(i, 1, n) {
		cin >> a[i];
		lb[0][i] = i - a[i];
		rb[0][i] = i + a[i];
	}
	for(int i = 0;i < 17;++i) {
		if(i) for(int j = 1;j <= n;++j) {
			const int left = lb[i - 1][j], right = rb[i - 1][j];
			lb[i][j] = qmin(min[i - 1], left, right);
			rb[i][j] = qmax(max[i - 1], left, right);
		}
		rep(j, 1, n) min[i][0][j] = lb[i][j], max[i][0][j] = rb[i][j];
		for(int j = 1;j < 17;++j) for(int k = 1;k + (1 << j) - 1 <= n;++k) {
			min[i][j][k] = std::min(min[i][j - 1][k], min[i][j - 1][k + (1 << j - 1)]);
			max[i][j][k] = std::max(max[i][j - 1][k], max[i][j - 1][k + (1 << j - 1)]);
		}
	}
	if(n == 1) {
	  cout << 0 << '\n';
	  return 0;
	}
	for(int i = 1;i <= n;++i) {
		int l = i, r = i, ans = 1;
		for(int j = 16;j >= 0;--j) {
			int Min = qmin(min[j], l, r);
			int Max = qmax(max[j], l, r);
			if(Max - Min < n - 1) {
				l = Min;
				r = Max;
				ans += 1 << j;
			}
		}
		cout << ans << ' ';
	}
}