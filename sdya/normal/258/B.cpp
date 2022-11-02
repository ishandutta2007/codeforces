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

map < pair < long long, int >, vector < int > > M;
long long pw[10];

vector < int > add(vector < int > a, vector < int > b) {
	vector < int > c(a.size());
	for (int i = 0; i < a.size(); ++i) {
		c[i] = a[i] + b[i];
	}
	return c;
}

void addOne(vector < int > &a) {
	for (int i = a.size() - 1; i > 0; --i) {
		a[i] = a[i - 1];
	}
	a[0] = 0;
}

vector < int > get(long long n, int digit) {
	if (digit == -1) {
		vector < int > res(10);
		res[0] = 1;
		return res;
	}
	if (M.count(make_pair(n, digit))) {
		return M[make_pair(n, digit)];
	}

	vector < int > digits;
	{
		int m = n;
		for (int i = 0; i < 10; ++i) {
			digits.push_back(m % 10);
			m /= 10;
		}
		//reverse(digits.begin(), digits.end());
	}

	vector < int > res(10, 0);
	if (4 < digits[digit]) {
		vector < int > cur = get(pw[digit] - 1, digit - 1);
		addOne(cur);
		res = add(res, cur);
	} else if (4 == digits[digit]) {
		vector < int > cur = get(n - 4 * pw[digit], digit - 1);
		addOne(cur);
		res = add(res, cur);
	}
	if (7 < digits[digit]) {
		vector < int > cur = get(pw[digit] - 1, digit - 1);
		addOne(cur);
		res = add(res, cur);
	} else if (7 == digits[digit]) {
		vector < int > cur = get(n - 7 * pw[digit], digit - 1);
		addOne(cur);
		res = add(res, cur);
	}

	int A = 0;
	for (int i = 0; i < 10; ++i) {
		if (i != 4 && i != 7 && i < digits[digit]) {
			++A;
		}
	}
	{
		vector < int > cur = get(pw[digit] - 1, digit - 1);
		for (int i = 0; i < cur.size(); ++i) {
			cur[i] *= A;
		}
		res = add(res, cur);
	}
	{
		int x = digits[digit];
		if (x != 4 && x != 7) {
			vector < int > cur = get(n - x * pw[digit], digit - 1);
			res = add(res, cur);
		}
	}
	return M[make_pair(n, digit)] = res;
}

const long long P = 1000000007LL;

long long ank(long long n, long long k) {
	long long res = 1;
	for (int i = 1; i <= k; ++i) {
		res *= (n + 1 - i);
		res %= P;
	}
	return res;
}

long long dp[20][20][20];
long long c[20][20];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	for (int i = 0; i < 20; ++i) {
		c[i][0] = 1;
		for (int j = 1; j <= i; ++j) {
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
			c[i][j] %= P;
		}
	}

	pw[0] = 1;
	for (int i = 1; i < 10; ++i) {
		pw[i] = pw[i - 1] * 10;
	}
	int n;
	cin >> n;

	vector < int > res = get(n, 9);
	--res[0];

	int s = 0;
	for (int i = 0; i < res.size(); ++i) {
		s += res[i];
	}
	if (s != n) {
		cerr << "Bad" << endl;
	}

	long long ways = 0;
	for (int i = 0; i < 10; ++i) {
		vector < int > current = res;
		if (current[i] == 0) {
			continue;
		}
		long long coef = current[i];
		--current[i];

		memset(dp, 0, sizeof(dp));
		dp[0][0][0] = 1LL;
		for (int j = 0; j < 10; ++j) {
			for (int sum = 0; sum < i; ++sum) {
				for (int k = 0; k <= 6; ++k) {
					if (dp[j][sum][k] == 0) {
						continue;
					}
					for (int l = 0; k + l <= 6 && sum + l * j < i; ++l) {
						long long coef = dp[j][sum][k] * ank(current[j], l);
						coef %= P;
						coef *= c[6 - k][l];
						dp[j + 1][sum + l * j][k + l] += coef;
						dp[j + 1][sum + l * j][k + l] %= P;
					}
				}
			}
		}

		long long coef2 = 0;
		for (int j = 0; j < i; ++j) {
			coef2 += dp[10][j][6];
			coef2 %= P;
		}
		ways += coef * coef2;
		ways %= P;
	}

	cout << ways << endl;

	return 0;
}