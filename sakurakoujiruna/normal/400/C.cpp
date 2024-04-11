#include <bits/stdc++.h>
using namespace std;

int main() {
	ios :: sync_with_stdio(false);
	int n, m, a, b, c, p;
	cin >> n >> m >> a >> b >> c >> p;
	a %= 4; b %= 2; c %= 4;
	while(p --) {
		int x, y; cin >> x >> y;
		for(int i = 0; i < a; i ++) {
			int nx = y, ny = n - x + 1;
			x = nx; y = ny;
			swap(n, m);
		}
		for(int i = 0; i < b; i ++)
			y = m - y + 1;
		for(int i = 0; i < c; i ++) {
			int nx = m - y + 1, ny = x;
			x = nx; y = ny;
			swap(n, m);
		}
		cout << x << ' ' << y << '\n';
		if((a + c) & 1)
			swap(n, m);
	}
	return 0;
}