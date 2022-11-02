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

string prep(const string &s) {
	string t;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '-') {
			continue;
		}
		t += s[i];
	}
	return t;
}

bool isTaxi(const string &s) {
	string t = prep(s);
	for (int i = 0; i < t.size(); ++i) {
		if (t[i] != t[0]) {
			return false;
		}
	}
	return true;
}

bool isPizza(const string &s) {
	string t = prep(s);
	for (int i = 1; i < t.size(); ++i) {
		if (t[i] >= t[i - 1]) {
			return false;
		}
	}
	return true;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector < string > a, b, c;
	int na = 0, nb = 0, nc = 0;
	for (int i = 0; i < n; ++i) {
		int m;
		cin >> m;
		string name;
		cin >> name;
		int x = 0, y = 0, z = 0;
		for (int j = 0; j < m; ++j) {
			string s;
			cin >> s;
			if (isTaxi(s)) {
				++x;
			} else if (isPizza(s)) {
				++y;
			} else {
				++z;
			}
		}
		if (x > na) {
			a.clear();
			na = x;
			a.push_back(name);
		} else if (x == na) {
			a.push_back(name);
		}

		if (y > nb) {
			b.clear();
			nb = y;
			b.push_back(name);
		} else if (y == nb) {
			b.push_back(name);
		}

		if (z > nc) {
			c.clear();
			nc = z;
			c.push_back(name);
		} else if (z == nc) {
			c.push_back(name);
		}
	}

	printf("If you want to call a taxi, you should call:");
	for (int i = 0; i < a.size(); ++i) {
		printf(" %s", a[i].c_str());
		if (i + 1 == a.size()) {
			printf(".\n");
		} else {
			printf(",");
		}
	}

	printf("If you want to order a pizza, you should call:");
	for (int i = 0; i < b.size(); ++i) {
		printf(" %s", b[i].c_str());
		if (i + 1 == b.size()) {
			printf(".\n");
		} else {
			printf(",");
		}
	}

	printf("If you want to go to a cafe with a wonderful girl, you should call:");
	for (int i = 0; i < c.size(); ++i) {
		printf(" %s", c[i].c_str());
		if (i + 1 == c.size()) {
			printf(".\n");
		} else {
			printf(",");
		}
	}

	return 0;
}