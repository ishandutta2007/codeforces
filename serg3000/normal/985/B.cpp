#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>>a(n, vector<int>(m));
	vector<int>b(m);
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			a[i][j] = s[j] - '0';
			if (a[i][j] == 1) {
				b[j] += 1;
			}
		}
	}
	int z = 0;
	for (int i = 0; i < n; i++) {
		z = 0;
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 1) {
				if (b[j] == 1) {
					z = 1;
				}
			}
		}
		if (z == 0) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}