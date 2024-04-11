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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	long long res = 1000000000000000000LL;
	long long n;
	cin >> n;
	for (long long i = 1; i <= n; ++i) {
		long long j = (n + i - 1) / i;
		res = min(res, 2LL * (i + j));
	}
	cout << res << endl;

	return 0;
}