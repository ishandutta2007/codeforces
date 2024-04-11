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
	vector < vector < int > > a(n, vector < int > (n));

	vector < int > res;
	for (int i = 0; i < n; ++i) {
		bool isgood = true;
		for (int j = 0; j < n; ++j) {
			cin >> a[i][j];
			if (a[i][j] == 1 || a[i][j] == 3) {
				isgood = false;
			}
		}
		if (isgood) {
			res.push_back(i);
		}
	}
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); ++i) {
		printf("%d ", res[i] + 1);
	}
	printf("\n");

	return 0;
}