#include <bits/stdc++.h>
using namespace std;

const int N = 121;
using ll = long long;

ll w[N][N];

ll a[N], b[N];

int main() {
	ios :: sync_with_stdio(0);
	int n, m; cin >> n >> m;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
			cin >> w[i][j];

	ll k = 0;
	for(int i = 2; i <= n; i ++)
		for(int j = 2; j <= m; j ++) {
			ll t = w[1][j] + w[i][1] - w[1][1] - w[i][j];
			if(t) k = __gcd(k, abs(t));
		}
	if(!k) k = 1e10L;
	for(int i = 1; i <= n; i ++)
		a[i] = w[i][1] % k;
	for(int i = 1; i <= m; i ++)
		b[i] = ((w[1][i] - a[1]) % k + k) % k;

	bool f = 1;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
			if((a[i] + b[j]) % k != w[i][j]) f = 0;

	if(f) {
		cout << "YES\n";
		cout << k << '\n';
		for(int i = 1; i <= n; i ++) cout << a[i] << ' '; cout << '\n';
		for(int i = 1; i <= m; i ++) cout << b[i] << ' '; cout << '\n';
	} else
		cout << "NO\n";
}