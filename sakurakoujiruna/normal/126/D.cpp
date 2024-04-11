#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 101;
const int F = 86;
ll fib[N];
ll f[N], g[N];
using vi = vector <int>;

int main() {
	ios :: sync_with_stdio(false);
	fib[1] = 1; fib[2] = 2;
	for(int i = 3; i < N; i ++) {
		fib[i] = fib[i - 1] + fib[i - 2];
	}
	int t; cin >> t;
	while(t --) {
		ll n; cin >> n;
		vi v;
		for(int i = F; i >= 1; i --)
			if(n >= fib[i]) {
				n -= fib[i];
				v.push_back(i);
			}
		reverse(v.begin(), v.end());
		memset(f, 0, sizeof(f));
		memset(g, 0, sizeof(g));
		int m = v.size();
		f[0] = 1; g[0] = (v[0] - 1) / 2;
		for(int i = 1; i < m; i ++) {
			f[i] = f[i - 1] + g[i - 1];
			g[i] = (v[i] - v[i - 1] - 1) / 2 * f[i - 1] +
				(v[i] - v[i - 1]) / 2 * g[i - 1];
		}
		cout << f[m - 1] + g[m - 1] << '\n';
	}
	return 0;
}