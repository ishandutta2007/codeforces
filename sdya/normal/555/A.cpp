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
#include <complex>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, k;
	scanf("%d%d", &n, &k);
	long long res = (n - 1) + (n - 1 - (k - 1));
	for (int i = 0; i < k; ++i) {
		int m;
		scanf("%d", &m);
		vector < int > a(m);
		int len = 0;
		for (int j = 0; j < m; ++j) {
			scanf("%d", &a[j]);
		}
		for (int j = 0; j < m; ++j) {
			if (a[j] == j + 1) {
				++len;
			} else {
				break;
			}
		}
		if (len > 0) {
			res -= 2LL * (len - 1);
		}
	}
	cout << res << endl;


	return 0;
}