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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

int n;
string s;

string a[] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n;
	cin >> s;
	for (int i = 0; i < 8; ++i) {
		if (a[i].size() != s.size()) {
			continue;
		}
		bool good = true;
		for (int j = 0; j < s.size(); ++j) {
			if (s[j] != '.' && s[j] != a[i][j]) {
				good = false;
			}
		}

		if (good) {
			cout << a[i] << endl;
			return 0;
		}

	}

	return 0;
}