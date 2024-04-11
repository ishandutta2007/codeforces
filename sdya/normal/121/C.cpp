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

vector < long long > genPerm(vector < long long > values, long long k) {
	vector < long long > f(values.size() + 1, 1LL);
	for (int i = 1; i < f.size(); ++i) {
		f[i] = f[i - 1] * (long long)(i);
		if (f[i] > inf) {
			f[i] = inf;
		}
	}

	if (values.size() == 1) {
		if (k == 1) {
			return values;
		} else {
			cout << -1 << endl;
			exit(0);
		}
	}

	vector < long long > res;
	for (int i = 0; i < values.size(); ++i) {
		if (f[values.size() - 1] >= k) {
			res.push_back(values[i]);
			vector < long long > current;
			for (int j = 0; j < values.size(); ++j) {
				if (i != j) {
					current.push_back(values[j]);
				}
			}
			current = genPerm(current, k);
			for (int j = 0; j < current.size(); ++j) {
				res.push_back(current[j]);
			}
			k = 0;
			break;
		} else {
			k -= f[values.size() - 1];
		}
	}
	if (k != 0) {
		cout << -1 << endl;
		exit(0);
	}
	return res;
}

bool isLucky(long long n) {
	while (n) {
		if (n % 10LL != 4LL && n % 10LL != 7LL) {
			return false;
		}
		n /= 10LL;
	}
	return true;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	gen(0);
	sort(a.begin(), a.end());

	long long n, k;
	cin >> n >> k;
	if (n < 20) {
		vector < long long > current;
		for (int i = 1; i <= n; ++i) {
			current.push_back(i);
		}
		current = genPerm(current, k);

		long long res = 0;
		for (int i = 0; i < current.size(); ++i) {
			if (isLucky(i + 1) && isLucky(current[i])) {
				++res;
			}
		}
		cout << res << endl;
		return 0;
	}

	vector < long long > ending;
	for (int i = n - 15; i <= n; ++i) {
		ending.push_back(i);
	}
	ending = genPerm(ending, k);

	long long res = 0;
	for (int i = 0; i < a.size(); ++i) {
		if (a[i] < n - 15) {
			++res;
		}
	}

	for (int i = n - 15; i <= n; ++i) {
		if (isLucky(i) && isLucky(ending[i - n + 15])) {
			++res;
		}
	}
	cout << res << endl;

	return 0;
}