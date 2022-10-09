#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; ++i)
#define fs first
#define sc second

int d[80][1100100];
const int mod = 1000000007;

int main() {
	int n;
	char s[100];
	cin >> n >> s;
	forn (i, n + 1) {
		d[i][0] = 1;
	}
	forn (i, n) {
		forn (mask, 1 << 20) {
			int cur = 0;
			if (d[i][mask] == 0) {
				continue;
			}
			for (int j = i + 1; j <= n; ++j) {
				cur <<= 1;
				cur += s[j - 1] == '1';
				if (cur == 0) {
					continue;
				}
				if (cur > 20) {
					break;
				}
				d[j][mask | (1 << (cur - 1))] += d[i][mask];
				d[j][mask | (1 << (cur - 1))] %= mod;
			}
		}
	}
	int ans = 0;
	forn (i, n + 1) {
		int mask = 0;
		forn (j, 20) {
			mask += 1 << j;
			ans += d[i][mask];
			ans %= mod;
		}
	}
	cout << ans << endl;
	return 0;
}