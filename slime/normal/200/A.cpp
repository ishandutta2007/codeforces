#include <bits/stdc++.h>
#define ll long long
#define maxn 2005 /*rem*/
#define mod 1000000007 
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
int d[maxn][maxn];
int f[maxn][maxn]; 
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		int mn = 2 * maxn, pl = 0;
		for (int j = 1; j <= n; j++) {
			int c = abs(x - j) + d[j][y];
			if (c < mn) mn = c, pl = j;
		}
		int s = 0;
		for (int q = 0; q <= m; q++) {
			if (y - q >= 1 && !f[pl][y - q]) {
				f[pl][y - q] = 1;
				s = y - q;
				break;
			}
			if (y + q <= m && !f[pl][y + q]) {
				f[pl][y + q] = 1;
				s = y + q;
				break;
			}
		}
		printf("%d %d\n", pl, s);
		int g = s, h = s;
		while (g >= 1 && f[pl][g] == 1) g--;
		while (h <= m && f[pl][h] == 1) h++;
		int l = g, r = h;
		if (g == 0) g = - 3 * maxn;
		if (h > m) h = 10 * maxn;
		for (int j = l; j <= r; j++)
			d[pl][j] = min(j - g, h - j);
	}
	return 0;
}