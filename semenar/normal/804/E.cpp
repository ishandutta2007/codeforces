#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <iomanip>
#include <cmath>
#include <ctime>

#pragma comment(linker, "/STACK:134217728")

using namespace std;

#define INF 1e9
#define PI 3.1415927
#define P 1000000007

long long gcd(long long m, long long n) {
	return ((n == 0) ? m : gcd(n, m%n));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;

	cin >> n;

	if ((n * (n - 1) / 2) % 2 != 0) {
		cout << "NO";
	}
	else {
		cout << "YES" << endl;

		vector<vector<bool>> used(n, vector<bool>(n));
		vector<int> perm(n);
		for (int i = 0; i < n; i++) perm[i] = i;
		for (int i = 0; i < n - 2; i++) {
			int perm_pos = 0;
			for (int j = 0; j < n; j++) if (perm[j] == i) perm_pos = j;

			if (used[i][perm_pos] == false && perm_pos != i) {
				used[i][perm_pos] = true;
				for (int j = i + 1; j < n; j++) {
					if (used[i][j] == false) {
						swap(perm[i], perm[j]);
						cout << i + 1 << " " << j + 1 << endl;
					}
				}
				swap(perm[i], perm[perm_pos]);
				cout << i + 1 << " " << perm_pos + 1 << endl;
				continue;
			}

			if (perm_pos == i) {
				for (int j = n - 1; j > i + 1; j--) {
					if (used[i][j] == false) {
						swap(perm[i], perm[j]);
						cout << i + 1 << " " << j + 1 << endl;
					}
				}
				used[i + 1][n-1] = true;
				swap(perm[i+1], perm[n-1]);
				cout << i + 2 << " " << n << endl;
				swap(perm[i], perm[i + 1]);
				cout << i + 1 << " " << i + 2 << endl;
				continue;
			}

			if (used[i][perm_pos] == true) {
				used[i + 1][n - 1] = true;
				swap(perm[i + 1], perm[n - 1]);
				cout << i + 2 << " " << n << endl;
				for (int j = n - 1; j > i; j--) {
					if (used[i][j] == false) {
						swap(perm[i], perm[j]);
						cout << i + 1 << " " << j + 1 << endl;
					}
				}
				continue;
			}
		}
		if (n > 1 && used[n - 2][n - 1] == false) {
			swap(perm[n - 2], perm[n - 1]);
			cout << n - 1 << " " << n << endl;
		}
	}

	return 0;
}