#include <cassert>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <bitset>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <stack>
#include <cmath>
#include <ctime>
#include <unordered_set>
#include <unordered_map>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

void solve() {
	string s;
	cin >> s;

	s = s.substr(4);

	int n = s.size();
	vector < long long > p(12);
	p[0] = 1;
	for (int i = 1; i < 12; ++i) {
		p[i] = p[i - 1] * 10LL;
	}

	long long t = 1988;
	for (int i = n - 1; i >= 0; --i) {
		long long value = 0;
		for (int j = i; j < n; ++j) {
			value = value * 10 + (s[j] - '0');
		}

		for (long long x = 0; ; ++x) {
			if (x * p[n - i] + value > t) {
				t = x * p[n - i] + value;
				break;
			}
		}
	}
	printf("%I64d\n", t);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		solve();
	}

	return 0;
}