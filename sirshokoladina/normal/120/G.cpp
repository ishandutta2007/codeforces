#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <map>
#include <set>
#include <deque>
#include <queue>

using namespace std;

#define forn(i,n) for (int i = 0; i < (int)(n); i++)
#define ford(i,n) for (int i = (int)(n) - 1; i >= 0; i--)

int a[200][2], b[200][2], c[200], d[200][200];
int nx[200], u[200], ans[200];
string w[200];
int v[200][200];

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	forn (i, 200) {
		forn (j, 200) {
			d[i][j] = 0;
		}
		u[i] = ans[i] = 0;
	}
	int n, t, m;
	cin >> n >> t;
	forn (i, n) {
		cin >> a[i][0] >> b[i][0] >> a[i][1] >> b[i][1];
	}
	cin >> m;
	forn (i, m) {
		cin >> w[i] >> c[i];
		nx[i] = (i + 1) % m;
	}
	int i = 0, j = 0, k = 0;
	while (m) {
		int s = t;
		while (s) {
			int q = max(1, c[k] - (a[i][j] + b[i][1 - j]) - d[i][k]);
			if (q <= s) {
				s -= q;
				u[k] = 1;
				m--;
				v[i][ans[i]] = k;
				ans[i]++;
				if (!m) {
					break;
				}
			} else {
				d[i][k] += s;
				s = 0;
			}
			while (u[nx[k]]) {
				nx[k] = nx[nx[k]];
			}
			k = nx[k];
		}
		i++;
		if (i == n) {
			i = 0;
			j = 1 - j;
		}
	}
	forn (i, n) {
		cout << ans[i];
		forn (j, ans[i]) {
			cout << ' ' << w[v[i][j]];
		}
		cout << endl;
	}
}