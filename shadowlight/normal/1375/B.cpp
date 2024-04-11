#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int N = 307;
int a[N][N];
int need[N][N];

vector <int> dx = {0, -1, 0, 1};
vector <int> dy = {1, 0, -1, 0};

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int cnt = 0;
			for (int d = 0; d < 4; ++d) {
				int x = i + dx[d], y = j + dy[d];
				if (x >= 0 && x < n && y >= 0 && y < m) {
					++cnt;
				}
			}
			if (a[i][j] > cnt) {
				cout << "NO\n";
				return;
			}
			need[i][j] = cnt;
		}
	}
	cout << "YES\n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << need[i][j] << " ";
		}
		cout << "\n";
	}
}

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		solve();
	}

}