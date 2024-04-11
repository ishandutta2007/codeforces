//#define _GLIBCXX_DEBUG
#include <iostream>
#include <iomanip>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include <deque>
#include <string>
#include <cmath>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <fstream>
//#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#pragma GCC optimize("O3")

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define print(a) for (auto& i : a) cout << i << " ";
#define input(a) for (auto& i : a) cin >> i;
#define mp make_pair
#define lb lower_bound
#define ub upper_bound

//#define int long long
//#define DEBUG

using namespace std;

vector<vector<int>> p;

int get(int i, int j, int i1, int j1) {
	return p[i1][j1] - p[i - 1][j1] - p[i1][j - 1] + p[i - 1][j - 1];
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<string> a(n + 1);
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			a[i] = '0' + a[i];
		}
		p.assign(n + 1, vector<int>(m + 1, 0));
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				p[i][j] = p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1] + (a[i][j] == '1');
			}
		}
		int ans = 16;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				for (int x = i - 4; x >= 1; x--) {
					for (int y = j - 3; y >= 1; y--) {
						if (
							get(x + 1, y + 1, i - 1, j - 1) +
							(i - x - 1 - get(x + 1, j, i - 1, j)) +
							(j - y - 1 - get(i, y + 1, i, j - 1)) +
							(j - y - 1 - get(x, y + 1, x, j - 1))
							>= ans)
							break;
						ans = min(ans,
							get(x + 1, y + 1, i - 1, j - 1) +
							(i - x - 1 - get(x + 1, j, i - 1, j)) +
							(i - x - 1 - get(x + 1, y, i - 1, y)) +
							(j - y - 1 - get(i, y + 1, i, j - 1)) +
							(j - y - 1 - get(x, y + 1, x, j - 1))
						);
					}
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}