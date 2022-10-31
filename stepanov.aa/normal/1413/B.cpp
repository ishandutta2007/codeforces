#include <vector>
#include <iostream>


using namespace std;





int main() {
	int q;
	cin >> q;
	for (int x = 0; x < q; ++x) {
		int n, m;
		cin >> n >> m;
		vector<int> pos(n * m + 1, -1);
		vector<vector<int>> a(n, vector<int>(m));
		vector<vector<int>> b(m, vector<int>(n));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> a[i][j];
			}
			pos[a[i][0]] = i;
		}
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> b[i][j];
			}
			if (pos[b[i][0]] != -1) {
				for (int i1 = 0; i1 < n; ++i1) {
					for (int j1 = 0; j1 < m; ++j1) {
						cout << a[pos[b[i][i1]]][j1] << " ";
					}
					cout << endl;
				}
			}
		}
	}
	return 0;
}

/*
1
4 3

4 5 3
1 7 11
10 8 9
6 2 12

7 2 5 8
1 6 4 10
11 12 3 9

*/