#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

int n, m;
const int MAXN = 51;
int a[MAXN][MAXN], b[MAXN][MAXN];

void read() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			b[i][j] = 0;
		}
	}
}

vector<pair <int, int>> ans;

void run() {
	for (int i = 0; i + 1 < n; i++) {
		for (int j = 0; j + 1 < m; j++) {
			int sum1 = a[i][j] + a[i + 1][j] + a[i][j + 1] + a[i + 1][j + 1];
			if (sum1 == 4) {
				b[i][j] = b[i + 1][j] = b[i][j + 1] = b[i + 1][j + 1] = 1;
				ans.push_back({i + 1, j + 1}); 
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] != b[i][j]) {
				cout << -1 << endl;
				exit(0);
			}
		}
	}
}

void write() {
	cout << ans.size() << endl;
	for (auto i : ans)
		cout << i.first << " " << i.second << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read();
	run();
	write();
	return 0;
}