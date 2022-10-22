#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 1010;
typedef long long ll;
const int mod = 998244353;
struct ints { int a[26]; };
ints s[maxn][maxn];
const int N = 300300;
int n, m, k;
int a[N], b[N], c[N], d[N];
char buf[maxn][maxn];
typedef ll AI[maxn][maxn];
AI val, sum[26];
char ch[N];
inline ll getsum(const AI & a, int x0, int y0, int x1, int y1) {
	return a[x1][y1] - a[x1][y0 - 1] - a[x0 - 1][y1] + a[x0 - 1][y0 - 1];
}

int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	rep(i, 1, n) {
		cin >> buf[i] + 1;
	}
	rep(i, 1, k) {
		cin >> a[i] >> b[i] >> c[i] >> d[i] >> ch[i];
		ch[i] -= 'a';
		s[a[i] + 0][b[i] + 0].a[ch[i]] += 1;
		s[c[i] + 1][d[i] + 1].a[ch[i]] += 1;
		s[a[i] + 0][d[i] + 1].a[ch[i]] -= 1;
		s[c[i] + 1][b[i] + 0].a[ch[i]] -= 1;
	}
	ll su = 0;
	rep(i, 1, n) {
		rep(j, 1, m) {
			rep(k, 0, 25) {
				s[i][j].a[k] += s[i - 1][j].a[k] + s[i][j - 1].a[k] - s[i - 1][j - 1].a[k];
			}
		}
	}
	rep(i, 1, n) {
		rep(j, 1, m) {
			buf[i][j] -= 'a';
			int c0 = 0;
			rep(k, 0, 25) {
				c0 += s[i][j].a[k];
			}
			s[i][j].a[buf[i][j]] += k - c0;
			rep(k, 0, 25) {
				rep(l, 0, 25) {
					sum[k][i][j] += std::abs(k - l) * s[i][j].a[l];
				}
			}
			su += val[i][j] = sum[buf[i][j]][i][j];
		}
	}
	rep(k, 0, 25) {
		rep(i, 1, n) {
			rep(j, 1, m) {
				sum[k][i][j] += sum[k][i - 1][j] + sum[k][i][j - 1] - sum[k][i - 1][j - 1];
			}
		}
	}
	rep(i, 1, n) {
		rep(j, 1, m) {
			val[i][j] += val[i - 1][j] + val[i][j - 1] - val[i - 1][j - 1];
		}
	}
	ll ans = 1e18;
	rep(i, 1, k) {
		ans = std::min(ans, su - getsum(val, a[i], b[i], c[i], d[i]) + getsum(sum[ch[i]], a[i], b[i], c[i], d[i]));
	}
	cout << ans << '\n';
}