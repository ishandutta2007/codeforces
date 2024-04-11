#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <string>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	vector < int > a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	for (int i = 0; i < 3000; ++i) {
		for (int j = 0; j < n; ++j) {
			if (j % 2 == 0) {
				a[j] = (a[j] + 1) % n;
			} else {
				a[j] = (a[j] + n - 1) % n;
			}
		}

		bool isgood = true;
		for (int j = 0; j < n; ++j) {
			if (j != a[j]) {
				isgood = false;
			}
		}
		if (isgood) {
			printf("Yes\n");
			return 0;
		}
	}

	printf("No\n");

	return 0;
}