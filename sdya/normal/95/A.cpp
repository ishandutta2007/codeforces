#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <bitset>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110;
string s[maxN], t, a;
int n;

bool isEqual(char s, char t) {
	if (s >= 'A' && s <= 'Z') {
		s = s - 'A' + 'a';
	}
	if (t >= 'A' && t <= 'Z') {
		t = t - 'A' + 'a';
	}
	return s == t;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	cin >> t;
	cin >> a;

	vector < bool > filled(t.size(), false);
	for (int i = 0; i < t.size(); ++i) {
		for (int j = 0; j < n; ++j) {
			bool isOk = true;
			if (i + s[j].size() - 1 >= t.size()) {
				continue;
			}
			for (int k = i; k < i + s[j].size(); ++k) {
				if (!isEqual(t[k], s[j][k - i])) {
					isOk = false;
					break;
				}
			}
			if (isOk) {
				for (int k = i; k < i + s[j].size(); ++k) {
					filled[k] = true;
				}
			}
		}
	}

	char another = 'a';
	if (another == a[0]) {
		another = 'b';
	}
	for (int i = 0; i < t.size(); ++i) {
		if (filled[i]) {
			if (isEqual(t[i], a[0])) {
				if (t[i] >= 'A' && t[i] <= 'Z') {
					t[i] = another - 'a' + 'A';
				} else {
					t[i] = another;
				}
			} else {
				if (t[i] >= 'A' && t[i] <= 'Z') {
					t[i] = a[0] - 'a' + 'A';
				} else {
					t[i] = a[0];
				}
			}
		}
	}

	cout << t << endl;
	
	return 0;
}