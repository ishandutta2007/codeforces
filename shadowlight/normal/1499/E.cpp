#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int MOD = 998244353;
const int N = 1007;

int ways[N][N][2][2];

void add(int &x, int y) {
	x += y;
	if (x >= MOD) {
		x -= MOD;
	}
}

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s, t;
	cin >> s >> t;

	int n = s.size(), m = t.size();
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			add(ways[i + 1][j][0][0], 1);
			add(ways[i][j + 1][1][0], 1);
			for (int was = 0; was < 2; ++was) {
				if (i) {
					if (s[i - 1] != s[i]) {
						add(ways[i + 1][j][0][was], ways[i][j][0][was]);
					}
					if (s[i - 1] != t[j]) {
						add(ways[i][j + 1][1][1], ways[i][j][0][was]);
					}
				}
				if (j) {
					if (t[j - 1] != s[i]) {
						add(ways[i + 1][j][0][1], ways[i][j][1][was]);
					}
					if (t[j - 1] != t[j]) {
						add(ways[i][j + 1][1][was], ways[i][j][1][was]);
					}
				}
			}
		}
	}
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) { 
			//cout << i << " " << j << " " << ways[i][j][0][1] << " " << ways[i][j][1][1] << "\n";
			add(res, ways[i][j][0][1]);
			add(res, ways[i][j][1][1]);
		}
	}
	cout << res << "\n";
}