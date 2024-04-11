#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <set>
#include <queue>
#include <deque>
#include <unordered_set>
#include <map>
#include<unordered_map>
#include <bitset>
#include <random>
#include <ctime>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>>a(n, vector<int>(m));
	vector<vector<int>>b(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char tmp;
			cin >> tmp;
			if (tmp == '#') {
				a[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 2; j++) {
			if (a[i][j] == 1 && a[i + 1][j] == 1&& a[i + 2][j] == 1 && a[i][j + 1] == 1 && a[i][j + 2] == 1 && a[i + 1][j + 2] == 1 && a[i + 2][j + 1] == 1&& a[i + 2][j + 2] == 1) {
				b[i][j] = 1, b[i + 1][j] = 1, b[i + 2][j] = 1, b[i][j + 1] = 1, b[i][j + 2] = 1, b[i + 1][j + 2] = 1, b[i + 2][j + 1] = 1, b[i + 2][j + 2] = 1;
			}
		}
	}
	int ch = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 1 && b[i][j] != 1) {
				ch = 1;
			}
		}
	}
	if (ch == 0) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	return 0;
}