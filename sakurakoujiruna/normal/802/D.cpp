#include <bits/stdc++.h>
using namespace std;

using db = double;
const int N = 250;
db a[N];

int main() {
	ios :: sync_with_stdio(0);
	int t; cin >> t;
	while(t --) {
		db p = 0, s = 0;
		for(int i = 0; i < N; i ++) {
			cin >> a[i];
			p += a[i];
		}
		p /= N;
		for(int i = 0; i < N; i ++)
			s += (a[i] - p) * (a[i] - p);
		s /= N;
		if(s > 2 * p)
			cout << "uniform\n";
		else
			cout << "poisson\n";
	}
}