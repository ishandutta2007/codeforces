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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

long long cnk(long long n, long long k) {
	long long res = 1;
	for (long long i = 1; i <= k; ++i) {
		res *= (n + 1 - i);
		res /= i;
	}
	return res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	long long a, b, c, l;
	cin >> a >> b >> c >> l;
	long long res = cnk(l + 3, 3);
	{
		for (long long da = 0; da <= l; ++da) {
			long long na = a + da;
			if (b + c > na) {
				continue;
			}
			long long rem = min(l - da, na - b - c);
			res -= cnk(rem + 2, 2);
		}
		for (long long db = 0; db <= l; ++db) {
			long long nb = b + db;
			if (a + c > nb) {
				continue;
			}
			long long rem = min(l - db, nb - a - c);
			res -= cnk(rem + 2, 2);
		}
		for (long long dc = 0; dc <= l; ++dc) {
			long long nc = c + dc;
			if (b + a > nc) {
				continue;
			}
			long long rem = min(l - dc, nc - b - a);
			res -= cnk(rem + 2, 2);
		}
	}
	cout << res << endl;

	return 0;
}