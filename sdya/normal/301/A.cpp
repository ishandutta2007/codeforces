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

	int n;
	cin >> n;
	vector < int > a(2 * n - 1), b, c;
	for (int i = 0; i < 2 * n - 1; ++i) {
		cin >> a[i];
		if (a[i] <= 0) {
			b.push_back(a[i]);
		} else {
			c.push_back(a[i]);
		}
	}

	if (n % 2 == 0) {
		sort(b.begin(), b.end());
		sort(c.begin(), c.end());

		if (b.size() % 2 == 0) {
			int res = 0;
			for (int i = 0; i < b.size(); ++i) {
				res -= b[i];
			}
			for (int i = 0; i < c.size(); ++i) {
				res += c[i];
			}
			cout << res << endl;
			return 0;
		}

		int current = 0;
		for (int i = 0; i + 1 < b.size(); ++i) {
			current -= b[i];
		}
		current += b.back();

		for (int i = 0; i < c.size(); ++i) {
			current += c[i];
		}

		int res = current;

		int sum = 0;
		for (int i = 0; i < b.size(); ++i) {
			sum -= b[i];
		}
		if (c.size() > 0) {
			sum -= c[0];
			for (int i = 1; i < c.size(); ++i) {
				sum += c[i];
			}
			res = max(res, sum);
		}

		cout << res << endl;

		return 0;
	}

	int res = 0;
	for (int i = 0; i < b.size(); ++i) {
		res -= b[i];
	}
	for (int i = 0; i < c.size(); ++i) {
		res += c[i];
	}
	cout << res << endl;

	return 0;
}