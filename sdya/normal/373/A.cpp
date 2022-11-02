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
#include <stack>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int k;
	cin >> k;
	string s[4];
	vector < int > cnt(10);
	for (int i = 0; i < 4; ++i) {
		cin >> s[i];
		for (int j = 0; j < 4; ++j) {
			if (s[i][j] != '.') {
				++cnt[s[i][j] - '0'];
			}
		}
	}

	for (int i = 0; i < 10; ++i) {
		if (cnt[i] > 2 * k) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";



	return 0;
}