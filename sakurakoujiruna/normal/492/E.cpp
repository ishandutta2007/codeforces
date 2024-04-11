#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e6 + 11;

int cnt[N];
int shift[N];

int main() {
	ios :: sync_with_stdio(false);
	int n, m, dx, dy;
	cin >> n >> m >> dx >> dy;

	int x = 0, y = 0;
	for(int i = 0; i < n; i ++) {
		shift[x] = y;
		x = (x + dx) % n;
		y = (y + dy) % n;
	}
	for(int i = 0; i < m; i ++) {
		int x, y;
		cin >> x >> y;
		cnt[(y - shift[x] + n) % n] ++;
	}
	cout << "0 " << max_element(cnt, cnt + n) - cnt << '\n';
	return 0;
}