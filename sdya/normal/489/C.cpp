#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

int main() {
	int m, s;
	cin >> m >> s;
	if (s == 0) {
		if (m != 1) {
			printf("-1 -1\n");
			return 0;
		}
		printf("0 0\n");
		return 0;
	}
	string A;
	int sa = s;
	for (int i = 0; i < m; ++i) {
		for (int j = (i == 0 ? 1 : 0); j <= 9; ++j) {
			int maxsum = (m - i - 1) * 9;
			if (sa >= j && sa - j <= maxsum) {
				A += j + '0';
				sa -= j;
				break;
			}
		}
		if (A.size() != i + 1) {
			printf("-1 -1\n");
			return 0;
		}
	}
	string B;
	int sb = s;
	for (int i = 0; i < m; ++i) {
		for (int j = 9; j >= (i == 0 ? 1 : 0); --j) {
			int maxsum = (m - i - 1) * 9;
			if (sb >= j && sb - j <= maxsum) {
				B += j + '0';
				sb -= j;
				break;
			}
		}
		if (B.size() != i + 1) {
			printf("-1 -1\n");
			return 0;
		}
	}
	cout << A << " " << B << endl;
	return 0;
}