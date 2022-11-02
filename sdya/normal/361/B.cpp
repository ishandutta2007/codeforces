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
	int n, k;
	cin >> n >> k;
	if (k == n) {
		cout << -1 << endl;
		return 0;
	}
	for (int i = 1; i <= n; ++i) {
		int j = i;
		if (i <= n - k) {
			j = i + 1;
			if (j > n - k) {
				j = 1;
			}
		}
		cout << j << " ";
	}
	cout << endl;
	return 0;
}