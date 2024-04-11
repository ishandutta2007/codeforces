#include<bits/stdc++.h>

using std::cin;
using std::cout;
typedef long long ll;
const int maxn = 1001;
int n, m, s, t;
struct pr { int a, b, k; };
std::vector<pr> vector;

ll dp[maxn];
inline int cmp0(const pr & x, const pr & y) {
	return x.b < y.b;
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	for(int i = 1, a, b, k;i <= n;++i) {
		cin >> a >> b >> k;
		vector.push_back((pr){ a, b, k });
	}
	sort(vector.rbegin(), vector.rend(), cmp0);
	for(const auto & x : vector) {
		for(int j = n;j >= 1;--j) {
			dp[j] = std::max(dp[j - 1] + std::max<ll>(0, x.a - (j - 1ll) * x.b), dp[j] + std::max<ll>(0, x.a - (ll) x.b * x.k));
		}
		* dp += std::max<ll>(0, x.a - (ll) x.b * x.k);
	}
	cout << *std::max_element(dp, dp + n + 1) << '\n';
}