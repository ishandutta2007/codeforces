#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int mod = 1000000007;

void add(int& a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  if (a < 0) a += mod;
}

int mult(int a, int b) {
  return a * (ll)b % mod;
}

int bp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mult(res, a);
    a = mult(a, a);
    b >>= 1;
  }
  return res;
}

const int INF = 1e9 + 7;

const int N = 507;
const int K = 11;
int res[N][N][K];

void upd(int &x, int y) {
	x = min(x, y);
}

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	if (k % 2) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cout << "-1 ";
			}
			cout << "\n";
		}
		return 0;
	}

	k /= 2;

	vector <vector<int>> lc(n, vector<int>(m));
	vector <vector<int>> dc(n, vector<int>(m));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m - 1; ++j) {
			cin >> lc[i][j];
		}
	}

	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> dc[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			res[i][j][0] = 0;
			for (int a = 1; a <= k; ++a) {
				res[i][j][a] = INF;
			}
		}
	}

	for (int a = 1; a <= k; ++a) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				for (int dx = -1; dx <= 1; ++dx) {
					for (int dy = -1; dy <= 1; ++dy) {
						if (abs(dx) + abs(dy) != 1) continue;
						int x = i + dx, y = j + dy;
						if (x < 0 || x >= n || y < 0 || y >= m) continue;

						int edge;
						if (x != i) {
							edge = dc[min(x, i)][y];
						} else {
							edge = lc[x][min(j, y)];
						}

						upd(res[i][j][a], res[x][y][a - 1] + edge);
					}
				}
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << 2 * res[i][j][k] << " ";
		}
		cout << "\n";
	}

}