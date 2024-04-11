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
	int res = 1000000;
	for (int a = 0; a <= n; ++a) {
		for (int b = 0; b <= n; ++b) {
			for (int c = 0; c <= n; ++c) {
				for (int d = 0; d <= n; ++d) {
					if (a + b + c + d == n && 2 * a + 3 * b + 4 * c + 5 * d == k) {
						res = min(res, a);
					}
				}
			}
		}
	}
	cout << res;

	return 0;
}