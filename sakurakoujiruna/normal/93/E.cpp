#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
using pii = pair <int, int>;

using ll = long long;
const int N = 121;
int a[N];

const int M = 7e6L + 11;
ll b[2][M], c[2][M];

int main() {
	ios :: sync_with_stdio(0);
	ll n; int m; cin >> n >> m;
	for(int i = 1; i <= m; i ++)
		cin >> a[i];
	sort(a + 1, a + m + 1, greater<int>());

	b[0][1] = n; c[0][1] = 1; n = 1;
	for(int i = 1; i <= m; i ++) {
		int now = i & 1 ^ 1, nxt = i & 1;
		int j = 1, k = 1, m = 0;
		auto add = [&](ll tb, ll tc) {
			if(m == 0 || b[nxt][m] != tb) {
				b[nxt][++ m] = tb;
				c[nxt][m] = 0;
			}
			c[nxt][m] += tc;
		};
		while(j <= n || k <= n) {
			if(k > n || j <= n && b[now][j] >= b[now][k] / a[i]) {
				add(b[now][j], c[now][j]);
				j ++;
			} else {
				add(b[now][k] / a[i], -c[now][k]);
				k ++;
			}
		}
		n = m;
	}
	ll ans = 0;
	for(int i = 1; i <= n; i ++)
		ans += b[m & 1][i] * c[m & 1][i];
	cout << ans << '\n';
}