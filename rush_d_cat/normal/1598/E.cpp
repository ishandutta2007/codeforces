#include <bits/stdc++.h>
using namespace std;
const int N = 1002;
int d[N][N], r[N][N], a[N][N];
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	int n, m, q;
	cin >> n >> m >> q;
	for (int i = n; i >= 1; i --) {
		for (int j = m; j >= 1; j --) {
			d[i][j] = 1 + r[i+1][j];
			r[i][j] = 1 + d[i][j+1];
		}
	}
	int sum = 0;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
			sum += d[i][j] + r[i][j];

	auto add = [&](int x, int y, int sgn) {
		{
			int rr = x, cc = y;
			int flag = 0;
			while (rr >= 1 && cc >= 1 && a[rr][cc] == 0) {
				if (flag == 0) {
					rr --; 
					if (rr < 1 || a[rr][cc] == 1) break;
					d[rr][cc] += sgn*r[x][y]; sum += sgn*r[x][y];
				} else {
					cc --; 
					if (cc < 1 || a[rr][cc] == 1) break;
					r[rr][cc] += sgn*r[x][y]; sum += sgn*r[x][y];
				}
				flag ^= 1;
			}
		}
		{
			int rr = x, cc = y;
			int flag = 0;
			while (rr >= 1 && cc >= 1 && a[rr][cc] == 0) {
				if (flag == 1) {
					rr --; 
					if (rr < 1 || a[rr][cc] == 1) break;
					d[rr][cc] += sgn*d[x][y]; sum += sgn*d[x][y];
				} else {
					cc --; 
					if (cc < 1 || a[rr][cc] == 1) break;
					r[rr][cc] += sgn*d[x][y]; sum += sgn*d[x][y];
				}
				flag ^= 1;
			}
		}
	};
	int free = n * m;
	while (q --) {
		int x, y;
		cin >> x >> y;
		add(x, y, -1); 
		sum -= (d[x][y] + r[x][y]);
		if (a[x][y] == 0) {
			d[x][y] = r[x][y] = 0;	
			free --;
		} else {
			d[x][y] = 1 + r[x+1][y];
			r[x][y] = 1 + d[x][y+1];
			free ++;
		}
		a[x][y] ^= 1;
		add(x, y, +1); 
		sum += (d[x][y] + r[x][y]);
		cout << sum - free << "\n";
	}
}