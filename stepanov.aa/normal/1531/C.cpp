#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


using namespace std;





bool solve(int n, vector<vector<char>>& res) {
	if (n == 1) {
		res.resize(1, vector<char>(1));
		res[0][0] = 'o';
		return true;
	}
	if (n == 2) {
		return false;
	}
	for (int x = 1; ; ++x) {
		int k = x * x;
		if ((n - k) % 2 != 0) {
			k -= 1;
		}
		if (k > n) {
			break;
		}
		if (n == k) {
			res.assign(x, vector<char>(x, 'o'));
			if (k != x * x) {
				res[0][x - 1] = '.';
			}
			return true;
		}
		if(n - k <= x + x){
			int y = (n - k) / 2;
			if (k != x * x && y == x) {
				res.assign(x + 2, vector<char>(x + 2, 'o'));
				for (int i = 0; i < x + 2; ++i) {
					for (int j = 0; j < x + 2; ++j) {
						if ((i == 0 && j > 0) || (j == x + 1 && i < x + 1) || (i < 3 && j >= x - 1)) {
							res[i][j] = '.';
						}
					}
				}
				return true;
			}
			res.assign(x + 1, vector<char>(x + 1, 'o'));
			if (k != x * x) {
				res[1][x - 1] = '.';
			}
			for (int i = y; i <= x; ++i) {
				res[0][i] = '.';
				res[x - i][x] = '.';
			}
			return true;
		}
	}
	return false;
}


int32_t main() {
	int n;
	cin >> n;
	vector<vector<char>> res;
	if (solve(n, res)) {
		cout << res.size() << "\n";
		for (int i = 0; i < res.size(); ++i) {
			for (int j = 0; j < res[i].size(); ++j) {
				cout << res[i][j];
			}
			cout << "\n";
		}
	}
	else {
		cout << -1 << "\n";
	}
	return 0;
}