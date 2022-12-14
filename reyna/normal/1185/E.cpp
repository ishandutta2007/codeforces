
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>

using namespace std;

#define mp make_pair
#define x first
#define y second
#define pb push_back
#define ALL(x) (x).begin(), (x).end()

typedef long long LL;

const int N = (int) 2005, mod = (int) 0;
int xl[N], q[N], xr[N], yl[N], yr[N];
string s[N];
int main() {
	ios_base::sync_with_stdio(0);
	int tc;
	cin >> tc;
	while (tc--) {
		memset(xl, 63, sizeof xl);
		memset(yl, 63, sizeof yl);
		memset(xr, -63, sizeof xr);
		memset(yr, -63, sizeof yr);
		int n, m;
		cin >> n >> m;
		for (int j = 0; j < n; ++j) {
			cin >> s[j];
		}
		for (int x = 0; x < n; ++x) {
			for (int y = 0; y < m; ++y) {
				if (s[x][y] >= 'a' && s[x][y] <= 'z') {
					int c = s[x][y] - 'a';
					xl[c] = min(xl[c], x);
					xr[c] = max(xr[c], x);
					yl[c] = min(yl[c], y);
					yr[c] = max(yr[c], y);
				}	
			}
		}
		int flag = 1;
		for (int s = 0; flag && s < 26; ++s) {
			if (xr[s] >= 0) {
				int width = xr[s] - xl[s];
				int height = yr[s] - yl[s];
				if (width >= 1 && height >= 1) {
					flag = 0;
				}
			}
		}
		if (!flag) {
			cout << "NO\n";
			continue;
		}
		for (int s = 0; s < 26; ++s) if (xr[s] >= 0) {
			for (int x = xl[s]; x <= xr[s]; ++x)
				for (int y = yl[s]; y <= yr[s]; ++y) {
					if (::s[x][y] == '.') flag = 0;
					if (::s[x][y] - 'a' != s) {
						if (::s[x][y] - 'a' < s) flag = 0;
					}
				}
		}
		if (!flag) {
			cout << "NO\n";
			continue;
		}
		int cnt = 0;
		for (int j = 25; j >= 0; --j) {
			if (xr[j] >= 0) {
				cnt = j + 1;
				break;
			}
		}
		for (int j = 0; j < cnt; ++j)
			if (xr[j] < 0)
				xl[j] = xl[cnt - 1], yl[j] = yl[cnt - 1], xr[j] = xr[cnt - 1], yr[j] = yr[cnt - 1];
		cout << "YES\n";
		cout << cnt << '\n';
		for (int j = 0; j < cnt; ++j) {
			int id = j;
			cout << xl[j] + 1 << ' ' << yl[j] + 1 << ' ' << xr[j] + 1 << ' ' << yr[j] + 1 << '\n';
		}
		
	}
}