#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, m;
	cin >> n >> m;
	vector < string > s(n);
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}

	int res = 0;
	for (int i = 0; i + 1 < n; ++i) {
		for (int j = 0; j + 1 < m; ++j) {
			set < char > S;
			S.insert(s[i][j]);
			S.insert(s[i][j + 1]);
			S.insert(s[i + 1][j]);
			S.insert(s[i + 1][j + 1]);
			if (S.count('f') && S.count('a') && S.count('c') && S.count('e')) {
				++res;
			}
		}
	}
	cout << res << endl;

	return 0;
}