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
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int y, k, n;
	cin >> y >> k >> n;
	vector < int > res;
	for (int i = k; i <= n; i += k) {
		if (i > y) {
			cout << i - y << " ";
			res.push_back(i);
		}
	}
	if (res.size() == 0) {
		cout << -1;
	}

	return 0;
}