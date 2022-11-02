#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1e4L + 11;
ll x[N], y[N];

int main() {
	ios :: sync_with_stdio(0);
	cout << fixed << setprecision(9);
	int n; ll w, v, u;
	cin >> n >> w >> v >> u;
	for(int i = 0; i < n; i ++)
		cin >> x[i] >> y[i];

	bool l = 0, r = 0;
	for(int i = 0; i < n; i ++) {
		ll t = v * y[i] - u * x[i];
		if(t > 0) l = 1;
		if(t < 0) r = 1;
	}

	if(l && r) {
		ld t = 0;
		for(int i = 0; i < n; i ++)
			t = max(t, (x[i] - ld(y[i]) / u * v) / v);
		cout << t + ld(w) / u << '\n';
	} else
		cout << ld(w) / u << '\n';

	return 0;
}