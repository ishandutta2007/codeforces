#include <bits/stdc++.h>
using namespace std;

#define pb push_back
using vi = vector <int>;

vi solve(int n) {
	vi r;
	if(n == 1) r = {1};
	else if(n & 1) {
		vi v = solve(n / 2);
		int sum = 0;
		for(int x : v) sum += x * x;
		for(int _ : {0, 1})
			for(int i = 0; i < n / 2; i ++)
				r.pb(v[i] * 2);
		r.pb(llround(sqrt((long double)sum)));
	} else {
		vi v = solve(n / 2);
		for(int i = 0; i < n / 2; i ++)
			r.pb(v[i] * 3);
		for(int i = 0; i < n / 2; i ++)
			r.pb(v[i] * 4);
	}
	return r;
}

int main() {
	ios :: sync_with_stdio(0);
	int n, m; cin >> n >> m;
	vi u = solve(n), v = solve(m);
	for(int i = 0; i < n; i ++) {
		for(int j = 0; j < m; j ++)
			cout << u[i] * v[j] << ' ';
		cout << '\n';
	}
}