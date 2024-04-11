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

	long long a, b, mod;
	cin >> a >> b >> mod;
	if (b >= mod - 1) {
		cout << 2 << endl;
		return 0;
	}

	for (long long i = 0; i < mod && i <= a; ++i) {
		long long r = (i * 1000000000LL) % mod;
		if (r > 0 && r + b < mod) {
			printf("1 %09d\n", (int)(i));
			return 0;
		}
	}

	cout << 2 << endl;

	return 0;
}