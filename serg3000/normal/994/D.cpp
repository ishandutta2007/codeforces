#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>>a(n, vector<int>(2));
	vector<vector<int>>b(m, vector<int>(2));
	for (int i = 0; i < n; i++) {
		cin >> a[i][0] >> a[i][1];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i][0] >> b[i][1];
	}
	int cnt = 0;
	int k = 0;
	for (int i = 0; i < n; i++) {
		int z = 0;
		int k2 = 0;
		for (int j = 0; j < m; j++) {
			if ((a[i][0] == b[j][0] && a[i][1] != b[j][1])){
				if (k2 != a[i][0] && k2 != 0) {
					z = 2;
				}
				if (k != a[i][0]) {
					cnt += 1;
				}
				k = a[i][0];
				k2 = a[i][0];
			}
			if ((a[i][0] == b[j][1] && a[i][1] != b[j][0])) {
				if (k2 != a[i][0] && k2 != 0) {
					z = 2;
				}
				if (k != a[i][0]) {
					cnt += 1;
				}
				k = a[i][0];
				k2 = a[i][0];
			}
			if ((a[i][1] == b[j][0] && a[i][0] != b[j][1])) {
				if (k2 != a[i][1] && k2 != 0) {
					z = 2;
				}
				if (k != a[i][1]) {
					cnt += 1;
				}
				k = a[i][1];
				k2 = a[i][1];
			}
			if ((a[i][1] == b[j][1] && a[i][0] != b[j][0])) {
				if (k2 != a[i][1] && k2 != 0) {
					z = 2;
				}
				if (k != a[i][1]) {
					cnt += 1;
				}
				k = a[i][1];
				k2 = a[i][1];
			}
		}
		if (z > 1) {
			cout << -1;  
			return 0;
		}
	}
	cnt = 0;
	k = 0;
	for (int j = 0; j < m; j++) {
		int z = 0;
		int k2 = 0;
		for (int i = 0; i < n; i++) {
			if ((a[i][0] == b[j][0] && a[i][1] != b[j][1])) {
				if (k2 != a[i][0] && k2 != 0) {
					z = 2;
				}
				if (k != a[i][0]) {
					cnt += 1;
				}
				k = a[i][0];
				k2 = a[i][0];
			}
			if ((a[i][0] == b[j][1] && a[i][1] != b[j][0])) {
				if (k2 != a[i][0] && k2 != 0) {
					z = 2;
				}
				if (k != a[i][0]) {
					cnt += 1;
				}
				k = a[i][0];
				k2 = a[i][0];
			}
			if ((a[i][1] == b[j][0] && a[i][0] != b[j][1])) {
				if (k2 != a[i][1] && k2 != 0) {
					z = 2;
				}
				if (k != a[i][1]) {
					cnt += 1;
				}
				k = a[i][1];
				k2 = a[i][1];
			}
			if ((a[i][1] == b[j][1] && a[i][0] != b[j][0])) {
				if (k2 != a[i][1] && k2 != 0) {
					z = 2;
				}
				if (k != a[i][1]) {
					cnt += 1;
				}
				k = a[i][1];
				k2 = a[i][1];
			}
		}
		if (z > 1) {
			cout << -1;
			return 0;
		}
	}
	if (cnt == 1 || cnt == 0) {
		cout << k;
	}
	else {
		cout << 0;
	}
	return 0;
}