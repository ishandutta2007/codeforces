#include <bits/stdc++.h>

using namespace std;
#define int long long
map <int, int> a, b;
const int MAXN = 510;
int arr1[MAXN][MAXN], arr2[MAXN][MAXN];
int n, m;
void read() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr1[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr2[i][j];
		}
	}
}

void no() {
	cout << "NO" << endl;
	exit(0);
}

void run() {
	for (int i = 0; i < n; i++) {
		int x = i, y = 0;
		map <int, int> a, b;
		while (x >= 0 && y < m) {
			a[arr1[x][y]]++;
			b[arr2[x][y]]++;
			x--;
			y++;
		}
		for (auto i : a) {
			if (b[i.first] != i.second)
				no();
		}
		for (auto i : b) {
			if (a[i.first] != i.second)
				no();
		}
	}

	for (int i = 0; i < m; i++) {
		int x = n - 1, y = i;
		map <int, int> a, b;
		while (x >= 0 && y < m) {
			a[arr1[x][y]]++;
			b[arr2[x][y]]++;
			x--;
			y++;
		}
		for (auto i : a) {
			if (b[i.first] != i.second)
				no();
		}
		for (auto i : b) {
			if (a[i.first] != i.second)
				no();
		}
	}
}

void write() {
	cout << "YES" << endl;
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