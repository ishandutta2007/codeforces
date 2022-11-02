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
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	long long n;
	cin >> n;
	vector < long long > d;
	for (long long i = 1; i * i <= n; ++i) {
		if (n % i == 0) {
			d.push_back(i);
			d.push_back(n / i);
		}
	}

	long long x = 8000000000000000000LL, y = 0LL;
	for (int i = 0; i < d.size(); ++i) {
		for (int j = 0; j < d.size(); ++j) {
			if (n % (d[i] * d[j]) == 0) {
				long long a = d[i];
				long long b = d[j];
				long long c = n / (d[i] * d[j]);

				long long u = a * b * c;
				long long v = (a + 1) * (b + 2) * (c + 2);

				long long cnt = v - u;
				x = min(x, cnt);
				y = max(y, cnt);
			}
		}
	}

	cout << x << " " << y << endl;

	return 0;
}