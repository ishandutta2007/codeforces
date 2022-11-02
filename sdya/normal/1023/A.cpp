#define _CRT_SECURE_NO_WARNINGS
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
#include <list>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 210000;
int n, m;
string s, t;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n >> m;
	cin >> s >> t;

	int index = -1;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '*') {
			index = i;
		}
	}

	if (index == -1) {
		if (s == t) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
		return 0;
	}

	if (m < n - 1) {
		cout << "NO" << endl;
		return 0;
	}

	string t1 = t.substr(0, index);
	string s1 = s.substr(0, index);

	string s2 = s.substr(index + 1);
	string t2 = t.substr(m - s2.size());

	if (t1 == s1 && t2 == s2) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}


	return 0;
}