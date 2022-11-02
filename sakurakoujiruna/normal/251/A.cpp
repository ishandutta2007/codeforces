#include <bits/stdc++.h>
using namespace std;

const int N = 1e5L + 11;
int x[N];

using ll = long long;

int main() {
	ios :: sync_with_stdio(false);
	int n, d; cin >> n >> d;
	for(int i = 0; i < n; i ++)
		cin >> x[i];

	int p = 0; ll ans = 0;
	for(int i = 0; i < n; i ++) {
		if(p < i) p = i;
		while(p + 1 < n && x[p + 1] - x[i] <= d)
			p ++;
		if(p - i >= 2) {
			ll t = p - i;
			ans += t * (t - 1) / 2;
		}
	}
	cout << ans << '\n';
	return 0;
}