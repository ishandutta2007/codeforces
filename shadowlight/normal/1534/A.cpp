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

void solve() {
	int n, m;
	cin >> n >> m;

	vector<string> was(n);
	for (int i = 0; i < n; ++i) {
		cin >> was[i];
	}

	vector<string> res = was;

	bool can = false;

	for (int it = 0; it < 2; ++it) {
		can = true;
		res = was;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if ((i + j) % 2 == it) {
					if (res[i][j] != '.' && res[i][j] != 'R') {
						//cout << i << " " << j << " "<< res[i][j] << endl;
						can = false;
					}  else {
						res[i][j] = 'R';
					}
				} else {
					if (res[i][j] != '.' && res[i][j] != 'W') {
						can = false;
					} else {
						res[i][j] = 'W';
					}
				}
			}
		}
		if (can) {
			cout << "YES\n";
			for (int i = 0; i < n; ++i) {
				cout << res[i] << "\n";
			}
			return;
		}
	}
	cout << "NO\n";
}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		solve();
	}

}