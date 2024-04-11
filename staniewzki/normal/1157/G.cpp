#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> a(n, vector<int>(m));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> a[i][j];

	// przypadek 1 : n = 1
	if(n == 1) {
		cout << "YES\n0\n";
		for(int j = 0; j < m; j++)
			cout << a[0][j];
		cout << "\n";
		return 0;
	}


	auto solve = [&](vector<int> c, bool flip) {
		if(flip) for(int &v : c) v ^= 1;
		vector<int> r(n);
		int used = 0;
		for(int i = 0; i < n; i++) {
			r[i] = a[i][0] ^ c[0];
			if(used == 1) r[i] ^= 1;
			for(int j = 0; j < m; j++) {
				int x = a[i][j] ^ c[j] ^ r[i];
				cerr << i << " " << j << " " << x << "\n";
				if(x == 1 && used == 0) used = 1;
				if(x == 0 && used != 0) used = -1;
			}

			if(used == -1) break;
		}

		if(used != -1) {
			cout << "YES\n";
			for(int i = 0; i < n; i++) cout << r[i];
			cout << "\n";
			for(int i = 0; i < m; i++) cout << c[i];
			cout << "\n";
			exit(0);
		}
	};

	// przypadek 2 : pierwszy wiersz to same 0
	solve(a[0], false);
	// przypadek 3 : ostatni wiersz to same 1
	solve(a[n - 1], true);

	cout << "NO\n";
}