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

long long n, m, x, y, a, b;
long long xs, ys, xf, yf;

void solve(long long &p, long long &q, long long n, long long x, long long u) {
	vector < long long > candidates;
	long long left_bound = max(0LL, x - u);
	long long right_bound = min(n - u, x);
	candidates.push_back(left_bound);
	candidates.push_back(right_bound);

	if (u <= 2LL * x) {
		long long t = (2LL * x - u) / 2LL;
		if (t >= left_bound && t <= right_bound) {
			candidates.push_back(t);
		}

		if (t + 1 >= left_bound && t + 1 <= right_bound) {
			candidates.push_back(t + 1);
		}
	}
	sort(candidates.begin(), candidates.end());

	int index = 0;
	long long best = 1000000000000000000LL;
	for (int i = 0; i < candidates.size(); ++i) {
		long long score = 2LL * x - (2LL * candidates[i] + u);
		if (score < 0) {
			score = -score;
		}
		if (score < best) {
			best = score;
			index = i;
		}
	}
	p = candidates[index];
	q = candidates[index] + u;
}

bool check(long long d) {
	long long u = a * d;
	long long v = b * d;

	if (u > n || v > m) {
		return false;
	}

	solve(xs, xf, n, x, u);
	solve(ys, yf, m, y, v);
	return true;
}

long long gcd(long long a, long long b) {
	if (a == 0 || b == 0) {
		return a + b;
	}
	if (a > b) {
		return gcd(a % b, b);
	} else {
		return gcd(b % a, a);
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n >> m >> x >> y >> a >> b;

	long long d = gcd(a, b);
	a /= d;
	b /= d;

	long long left_bound = 1, right_bound = 1000000000;
	while (right_bound - left_bound > 1) {
		long long m = (left_bound + right_bound) / 2;
		if (check(m)) {
			left_bound = m;
		} else {
			right_bound = m;
		}
	}

	if (check(right_bound)) {
		cout << xs << " " << ys << " " << xf << " " << yf << endl;
	} else {
		check(left_bound);
		cout << xs << " " << ys << " " << xf << " " << yf << endl;
	}

	return 0;
}