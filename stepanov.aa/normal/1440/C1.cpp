#include <iostream>
#include <vector>


using namespace std;


int n, m;
vector<vector<bool>> a;
vector<vector<int>> op;

inline void make_op(int i1, int j1, int i2, int j2, int i3, int j3) {
	a[i1][j1] = !a[i1][j1];
	a[i2][j2] = !a[i2][j2];
	a[i3][j3] = !a[i3][j3];
	op.push_back({ i1 + 1, j1 + 1, i2 + 1, j2 + 1, i3 + 1, j3 + 1});
}


inline void left1(int i, int j) {
	make_op(i, j, i + 1, j, i + 1, j - 1);
	make_op(i, j - 1, i + 1, j, i + 1, j - 1);
}


inline void left2(int i, int j) {
	make_op(i, j, i, j - 1, i + 1, j - 1);
	make_op(i, j - 2, i, j - 1, i + 1, j - 1);
}


int main() {
	int t;
	cin >> t;
	while (t--) {
		op.clear();
		cin >> n >> m;
		a.resize(n);
		for (int i = 0; i < n; ++i) {
			a[i].resize(m);
			for (int j = 0; j < m; ++j) {
				char c;
				cin >> c;
				a[i][j] = (c == '1');
			}
		}
		for (int i = n - 1; i > 0; --i) {
			for (int j = m - 1; j > 0; --j) {
				if (a[i][j]) {
					if (a[i][j - 1]) {
						make_op(i, j, i, j - 1, i - 1, j - 1);
					}
					else {
						make_op(i, j, i - 1, j, i - 1, j - 1);
					}
				}
			}
			if (a[i][0]) {
				make_op(i, 0, i - 1, 0, i - 1, 1);
			}
		}
		for (int j = m - 1; j > 1; --j) {
			if (a[0][j]) {
				if (a[0][j - 1]) {
					left1(0, j);
				}
				else {
					left2(0, j);
				}
			}
		}
		if (a[0][0]) {
			if (a[0][1]) {
				left1(0, 1);
			}
			else {
				make_op(0, 1, 0, 0, 1, 0);
				make_op(0, 1, 0, 0, 1, 1);
				make_op(1, 1, 0, 0, 1, 0);
			}
		}
		else if (a[0][1]) {
			make_op(0, 0, 0, 1, 1, 1);
			make_op(0, 0, 0, 1, 1, 0);
			make_op(1, 0, 0, 1, 1, 1);
		}
		cout << op.size() << "\n";
		for (int i = 0; i < op.size(); ++i) {
			cout << op[i][0] << " " << op[i][1] << " " << op[i][2] << " " << op[i][3] << " " << op[i][4] << " " << op[i][5] << "\n";
		}
	}
	return 0;
}

/*
1
3 3
010
011
100

*/