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

bool isStrong(const string &s) {
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == ' ') {
			continue;
		}
		if (s[i] == '#') {
			return true;
		}
		return false;
	}
	return false;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	vector < string > s;
	string t;
	while (getline(cin, t)) {
		s.push_back(t);
	}

	for (int i = 0; i < s.size(); ++i) {
		if (isStrong(s[i])) {
			continue;
		}
		string t = "";
		for (int j = 0; j < s[i].size(); ++j) {
			if (s[i][j] == ' ') {
				continue;
			}
			t += s[i][j];
		}
		s[i] = t;
	}

	vector < string > res;
	for (int i = 0; i < s.size(); ++i) {
		if (isStrong(s[i])) {
			res.push_back(s[i]);
			continue;
		}
		if (res.empty()) {
			res.push_back(s[i]);
			continue;
		}
		if (isStrong(res.back())) {
			res.push_back(s[i]);
			continue;
		}
		res.back() += s[i];
	}
	for (int i = 0; i < res.size(); ++i) {
		cout << res[i] << endl;
	}


	return 0;
}