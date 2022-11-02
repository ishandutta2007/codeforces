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

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	vector < int > a(3, 0);
	int n;
	cin >> n;
	a[n - 1] = 1;
	for (int i = 0; i < 3; ++i) {
		int u, v;
		cin >> u >> v;
		swap(a[u - 1], a[v - 1]);
	}

	for (int i = 0; i < 3; ++i) {
		if (a[i]) {
			cout << i + 1 << endl;
		}
	}


	return 0;
}