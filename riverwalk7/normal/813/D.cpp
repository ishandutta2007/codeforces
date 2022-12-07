#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <map>

using namespace std;

const int MAXN = 5010;
int n, m = 0, a[MAXN], b[MAXN], c[MAXN] = {0}, d[MAXN] = {0}, ans = 0;
int f[MAXN][MAXN] = {0}, mx1[MAXN][MAXN] = {0}, mx2[MAXN][7] = {0};
map <int, int> key;

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (key.find(a[i]) == key.end())
			key[a[i]] = ++m;
		b[i] = key[a[i]];
		if (key.find(a[i]-1) != key.end())
			c[i] = key[a[i]-1];
		if (key.find(a[i]+1) != key.end())
			d[i] = key[a[i]+1];
	}
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j < i; ++j) {
			f[i][j] = 1 + max(max(mx1[j][c[i]], mx1[j][d[i]]), max(f[j][0], mx2[j][a[i]%7]));
			ans = max(ans, f[i][j]);
			mx1[j][b[i]] = max(mx1[j][b[i]], f[i][j]);
			if (j) {
				mx1[i][b[j]] = max(mx1[i][b[j]], f[i][j]);
				mx2[i][a[j]%7] = max(mx2[i][a[j]%7], f[i][j]);
			}
			mx2[j][a[i]%7] = max(mx2[j][a[i]%7], f[i][j]);
		}
	cout << ans << endl;
	return 0;
}