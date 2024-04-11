#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

int main() {
	string s;
	cin >> s;
	int n = s.size();

	s += s;
	vector < int > d(2 * n);
	d[2 * n - 1] = 1;
	for (int i = 2 * n - 2; i >= 0; --i) {
		if (s[i + 1] != s[i]) {
			d[i] = 1 + d[i + 1];
		} else {
			d[i] = 1;
		}
	}

	int res = min(n, *max_element(d.begin(), d.end()));
	cout << res << endl;

	return 0;
}