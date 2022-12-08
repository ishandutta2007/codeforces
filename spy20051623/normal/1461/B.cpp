#include <bits/stdc++.h>
using namespace std;
int mp[505][505];
int d[505][2005];
int n, m;

int lowbit(int x) {
	return x & (-x);
}

void update(int x, int y, int k) {
	for (int i = y; i <= m; i += lowbit(i))
		d[x][i] += k;
}

int sum(int x, int y) {
	int res = 0;
	for (int i = y; i > 0; i -= lowbit(i))
		res += d[x][i];
	return res;
}

int main() {
//	freopen("in.txt", "r", stdin);
	long long t, i, j, k, cnt, res;
	char ch;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		memset(d, 0, sizeof(d));
		for (i = 1; i <= n; ++i) {
			getchar();
			for (j = 1; j <= m; ++j) {
				ch = getchar();
				if (ch == '*')
					update(i, j, 1);
			}
		}
		res = 0;
		for (i = 1; i <= n; ++i) {
			for (j = 1; j <= m; ++j) {
				cnt = 0;
				while (cnt <= n) {
					if (sum(i + cnt, j + cnt) - sum(i + cnt, j - cnt - 1) != cnt * 2 + 1)
						break;
					else
						++cnt;
				}
				res += cnt;
			}
		}
		cout << res << endl;
	}
	return 0;
}