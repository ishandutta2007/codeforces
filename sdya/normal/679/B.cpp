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

long long getRoot(long long n) {
	long long m = (long long)pow((double)(n), 1.0 / 3.0);
	long long res = 0;
	for (long long i = max(0LL, m - 2); i <= m + 2; ++i) {
		if (i * i * i <= n) {
			res = i;
		} else {
			break;
		}
	}
	return res;
}

int calculate(long long n, bool print = false) {
	int cnt = 0;
	while (n > 0) {
		long long m = getRoot(n);
		++cnt;
		n -= m * m * m;
		if (print) {
			cout << m << " ";
		}
	}
	if (print) {
		cout << endl;
	}
	return cnt;
}

map < long long, pair < long long, int > > M;

pair < long long, int > solve(long long m) {
	if (m <= 0) {
		return make_pair(0, 0);
	}
	if (M.count(m) != 0) {
		return M[m];
	}

	long long k = getRoot(m);
	pair < long long, int > res(0, -1);
	for (long long i = k; i >= 1 && i >= k - 1000; --i) {
		long long iii = i * i * i;
		long long bound = (i + 1) * (i + 1) * (i + 1) - iii;
		pair < long long, int > current = solve(min(m - iii, bound - 1));
		if (current.second + 1 > res.second) {
			res = make_pair(current.first + iii, current.second + 1);
		} else if (current.second + 1 == res.second) {
			res.first = max(res.first, current.first + iii);
		}
	}
	return M[m] = res;
}

pair < long long, int > trivial(long long m) {
	long long value = 0, best = -1;
	for (int i = 1; i <= m; ++i) {
		int cur = calculate(i);
		if (cur >= best) {
			best = cur;
			value = i;
		}
	}
	return make_pair(value, best);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	long long m;
	cin >> m;

	//int start = clock();
	pair < long long, int > res = solve(m);
	cout << res.second << " " << res.first << endl;

	//cerr << clock() - start << endl;

	//pair < long long, int > t = trivial(m);
	//cout << t.first << " " << t.second << endl;
	return 0;

	calculate(38589, true);
	return 0;
	int best = 0;
	for (long long i = 1; ; ++i) {
		int value = calculate(i);
		if (value >= best) {
			best = value;
			cout << i << ": " << value << ", ";
			calculate(i, true);
		}
	}

	return 0;
}