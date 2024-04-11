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

const long long inf = 10000000000LL;

vector < long long > a;

void gen(long long current) {
	if (current > inf) {
		return;
	}
	if (current > 0) {
		a.push_back(current);
	}
	gen(current * 10LL + 4LL);
	gen(current * 10LL + 7LL);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	gen(0);
	sort(a.begin(), a.end());

	long long l, r;
	cin >> l >> r;
	long long res = 0;
	for (int i = 0; i < a.size(); ++i) {
		if (a[i] < l) {
			continue;
		}
		long long bound = a[i];
		if (bound > r) {
			bound = r;
		}
		if (l <= bound) {
			res += (bound - l + 1) * a[i];
		}
		l = bound + 1;
	}
	cout << res << endl;

	return 0;
}