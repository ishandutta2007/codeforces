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

bool check(string s) {
	for (int i = 1; i < s.size(); ++i) {
		if (s[i - 1] == s[i]) {
			return false;
		}
	}
	for (int i = 2; i < s.size(); ++i) {
		if (s[i - 2] == s[i]) {
			return false;
		}
	}
	return true;
}

bool add(string &s, int p) {
	vector < int > a(s.size());
	for (int i = 0; i < s.size(); ++i) {
		a[i] = s[i] - 'a';
	}
	++a.back();
	for (int i = (int)(a.size()) - 1; i >= 1; --i) {
		if (a[i] >= p) {
			a[i] = 0;
			++a[i - 1];
		}
	}
	if (a[0] >= p) {
		return false;
	}
	for (int i = 0; i < s.size(); ++i) {
		s[i] = a[i] + 'a';
	}
	return true;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, p;
	cin >> n >> p;
	string s;
	cin >> s;

	for (int i = s.size() - 1; i >= 0; --i) {
		string cur = "";
		for (int j = 0; j < i; ++j) {
			cur += s[j];
		}

		for (int j = s[i] + 1; j < 'a' + p; ++j) {
			bool nice = true;
			if (i > 0 && j == s[i - 1]) {
				nice = false;
			}
			if (i > 1 && j == s[i - 2]) {
				nice = false;
			}
			if (!nice) {
				continue;
			}

			cur += j;
			break;
		}

		if (cur.size() == i) {
			continue;
		}

		for (int j = i + 1; j < s.size(); ++j) {
			for (int k = 'a'; k < 'a' + p; ++k) {
				bool nice = true;
				if (j > 0 && k == cur[j - 1]) {
					nice = false;
				}
				if (j > 1 && k == cur[j - 2]) {
					nice = false;
				}
				if (nice) {
					cur += k;
					break;
				}
			}
		}
		cout << cur << endl;
		return 0;
	}

	cout << "NO" << endl;

	return 0;
}