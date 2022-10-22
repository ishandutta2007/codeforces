#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
typedef long long ll;
const int mod = 1e9 + 7;
const int N = 13 << 4;
struct Mat {
	int a[N][N];
	inline Mat operator * (const Mat & b) const {
		Mat ret; memset(&ret, 0, sizeof ret);
		for(int i = 0;i < N;++i) for(int j = 0;j < N;++j) if(a[i][j]) {
			for(int k = 0;k < N;++k) {
				ret.a[i][k] = (ret.a[i][k] + (ll) a[i][j] * b.a[j][k]) % mod;
			}
		}
		return ret;
	}
} base, trans, I;
inline Mat pow(Mat a, int b) {
	Mat ans = I;
	for(;b;b >>= 1,a = a * a) {
		if(b & 1) {
			ans = ans * a;
		}
	}
	return ans;
}
int n, k, m;
inline int idx(int cnt, int s) { return cnt << m | s; }
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	for(int i = 0;i < N;++i) I.a[i][i] = 1;
	cin >> n >> k >> m;
	for(int i = 0;i <= k;++i) {
		for(int j = 0;j < 1 << m;++j) {
			trans.a[idx(i, j)][idx(i, j >> 1)] = 1;
			if(i != k) {
				trans.a[idx(i, j)][idx(i + 1, j >> 1 | 1 << m - 1)] = __builtin_popcount(j) + 1;
			}
		}
	}
	base.a[0][0] = 1;
	trans = base * pow(trans, n);
	ll ans = 0;
	for(int j = 0;j < 1 << m;++j) {
		ans += trans.a[0][idx(k, j)];
	}
	cout << ans % mod << '\n';
}