#include <bits/stdc++.h>
using namespace std;

const int N = (int)2e5 + 11;
double fac[N];

int main() {
	for(int i = 1; i < N; i ++)
		fac[i] = fac[i - 1] + log(i);
	ios :: sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	if(k >= m)
		cout << 1 << '\n';
	else if(n + k < m)
		cout << 0 << '\n';
	else {
		double u = fac[n + m] - fac[m - k - 1] - fac[n + k + 1];
		double d = fac[n + m] - fac[n] - fac[m];
		double ans = 1 - exp(u - d);
		cout << fixed << setprecision(6) << ans << '\n';
	}
	return 0;
}