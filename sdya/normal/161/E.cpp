#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <set>
#include <string>
#include <map>
#include <algorithm>
#include <bitset>
#include <queue>
#include <stack>
#include <ctime>

using namespace std;

bool is_prime(int n) {
	for (int i = 2; i * i <= n; ++i)
		if (n % i == 0) return false;
	return true;
}

const int maxP = 6;
const int maxN = 110000;

vector < int > primes;
vector < vector < int > > digits[maxP];
int values[maxP][maxN], lenv[maxP], pr[maxN];

inline pair < int, int > get(int start, int finish, int length) {
	int left_bound = lower_bound(values[length], values[length] + lenv[length], start) - values[length];
	int right_bound = upper_bound(values[length], values[length] + lenv[length], finish) - values[length];
	return make_pair(left_bound, right_bound - 1);
}

int a[maxP][maxP];

inline pair < int, int > get_correct(int level, int n) {
	int start = 0;
	for (int i = 0; i < level; ++i)
		start = start * 10 + a[level][i];
	int coef = 1;
	for (int i = level; i < n; ++i)	coef *= 10;
	return get(start * coef, start * coef + (coef - 1), n);
}

void precalc() {
	for (int i = 2; i <= 100000; ++i)
		if (is_prime(i)) {
			pr[i] = true;
			primes.push_back(i);
			vector < int > buf;
			int n = i;
			for (int j = 0; j < 5; ++j)
				buf.push_back(n % 10), n /= 10;
			int l = 5;
			for (int j = 4; j >= 0; --j)
				if (buf[j] != 0) {
					l = j + 1;
					break;
				}
			for (int j = l; j <= 5; ++j) {
				vector < int > a;
				for (int k = j - 1; k >= 0; --k)
					a.push_back(buf[k]);
				digits[j].push_back(a);
				values[j][lenv[j] ++] = i;
			}
		}
}

int rec(int level, int n) {
	pair < int, int > cur = get_correct(level, n);
	if (cur.first > cur.second) return 0;
	if (level == n - 1) return cur.second - cur.first + 1;
	int res = 0;
	for (int i = cur.first; i <= cur.second; ++i) {
		for (int j = level; j < n; ++j)
			a[j][level] = digits[n][i][j];
		if (level == n - 2) {
			int x = 0;
			for (int k = 0; k + 1 < n; ++k)
				x = x * 10 + a[level + 1][k];
			for (int k = 1; k <= 9; k += 2)
				if (pr[x * 10 + k]) ++res;
			if (pr[x * 10 + 2]) ++res;
		} else res += rec(level + 1, n);
	}
	return res;
}

int solve(int p) {
	int n = 0;
	int m = p;
	while (m) a[0][n ++] = m % 10, m /= 10;
	reverse(a[0], a[0] + n);
	for (int i = 0; i < n; ++i)
		a[i][0] = a[0][i];
	return rec(1, n);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);	

	precalc();
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int p;
		scanf("%d", &p);
		cout << solve(p) << endl;
	}
	cerr << clock() << endl;
	return 0;
}