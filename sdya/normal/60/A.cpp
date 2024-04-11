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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, m;
	cin >> n >> m;
	int l = 1, r = n;
	for (int i = 0; i < m; ++i) {
		string s1, s2, s3, s4;
		int value;
		cin >> s1 >> s2 >> s3 >> s4 >> value;
		if (s3 == "left") {
			r = min(value - 1, r);
		} else {
			l = max(value + 1, l);
		}
	}
	
	if (l > r) {
		cout << -1 << endl;
	} else {
		cout << (r - l + 1) << endl;
	}

	return 0;
}