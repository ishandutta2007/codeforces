#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 305;
typedef long long ll;
const int mod = 998244353;
inline ll pow(ll a,int b,int ans = 1) {
	for(;b;b >>= 1,a = a * a % mod) if(b & 1)
		ans = ans * a % mod;
	return ans;
}
inline ll inverse(int x){ return pow(x, mod - 2); }
int n;
int x[maxn], y[maxn];
ll dp[6][maxn][maxn];
struct pr { int a, b; };
inline double val(const pr &o) { return std::atan2(x[o.a] - x[o.b], y[o.a] - y[o.b]); }
inline int cmp0(const pr & a,const pr & b) { return val(a) < val(b); }
std::vector<pr> v;
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	rep(i, 1, n) cin >> x[i] >> y[i], dp[0][i][i] = 1;
	rep(i, 1, n) rep(j, 1, n) if(i != j) {
		v.push_back((pr) {i, j});
	}
	sort(v.begin(), v.end(), cmp0);
	for(pr i : v) {
		rep(j, 0, 4) {
			rep(k, 1, n) {
				dp[j + 1][k][i.b] += dp[j][k][i.a];
			}
		}
	}
	ll ans = 0;
	rep(i, 1, n) ans += dp[5][i][i];
	cout << ans << '\n';
}