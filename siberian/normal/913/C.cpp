#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) (x).begin(),(x).end()

#define int ll

void chkmin(int & a, int b) {
	a = min(a, b);
}

const int INF = 1e18;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.precision(20);
	int n, l;
	cin >> n >> l;
	vector<int> c(31, INF);
	for (int i = 0; i < n; i++)
		cin >> c[i];
	for (int i = 0; i < 31; i++) {
		for (int j = i + 1; j < 31; j++) {
			chkmin(c[j], c[i] * (1LL << (j - i))); 
		}
	}
	int ans = 0;
	int fans = 1e18;
	for (int i = 30; i >= 0; i--) {
		if ((l >> i) & 1) ans += c[i];
		chkmin(fans, ans + c[i]);
		if ((1LL << i) >= l) chkmin(fans, c[i]);
	}
	cout << min(ans, fans);
	return 0;
}