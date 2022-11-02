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

	string a, b;
	cin >> a >> b;
	int x = 0, y = 0;
	for (int i = 0; i < a.size(); ++i) {
		if (a[i] != b[i]) {
			if (a[i] == '4') {
				++x;
			} else {
				++y;
			}
		}
	}
	cout << max(x, y) << endl;

	return 0;
}