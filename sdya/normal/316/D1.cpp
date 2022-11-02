#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <string>
#include <cstring>
#include <cmath>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const long long P = 1000000007LL;

struct State {
	vector < int > order;
	vector < int > attempts;

	State() {
	}

	State(vector < int > order, vector < int > attempts) : order(order), attempts(attempts) {
	}

	bool operator < (const State& other) const {
		return make_pair(order, attempts) < make_pair(other.order, other.attempts);
	}
};

set < State > states;
set < vector < int > > orders;

int a[11][11] = {
	{ 0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0},
	{ 1,  1,  0, 0, 0, 0, 0, 0, 0, 0, 0},
	{ 2,  2,  2, 0, 0, 0, 0, 0, 0, 0, 0},
	{ 4,  6,  6,  6, 0, 0, 0, 0, 0, 0, 0},
	{10, 16, 24, 24, 24, 0, 0, 0, 0, 0, 0},
	{26, 50, 80, 120, 120, 120, 0, 0, 0, 0, 0},
	{76, 156, 300, 480, 720, 720, 720, 0, 0, 0, 0},
	{232, 532, 1092, 2100, 3360, 5040, 5040, 5040, 0, 0, 0},
	{764, 1856, 4256, 8736, 16800, 26880, 40320, 40320, 40320, 0, 0},
	{2620, 6876, 16704, 38304, 78624, 151200, 241920, 362880, 362880, 362880, 0},
	{9496, 26200, 68760, 167040, 383040, 786240, 1512000, 2419200, 3628800, 3628800, 3628800}
};

long long powmod(long long a, long long n) {
	if (n == 0) {
		return 1LL;
	}

	long long b = powmod(a, n / 2LL);
	b = (b * b) % P;

	if (n % 2LL == 0LL) {
		return b;
	} else {
		return (a * b) % P;
	}
}

long long inverse(long long a) {
	return powmod(a, P - 2);
}

const int maxN = 1100000;
long long f[maxN];

long long c[1100][1100], fc[1100];

void precalc() {
	f[0] = 1;
	f[1] = 1;
	f[2] = 2;
	for (int i = 3; i < maxN; ++i) {
		f[i] = f[i - 1] + (long long)(i - 1) * f[i - 2];
		f[i] %= P;
	}

	for (int i = 0; i < 1100; ++i) {
		c[i][0] = 1;
		for (int j = 1; j <= i; ++j) {
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % P;
		}
	}

	fc[0] = 1;
	for (int i = 1; i < 1100; ++i) {
		fc[i] = (fc[i - 1] * i) % P;
	}
}

long long cnk(long long n, long long k) {
	if (n < k || k < 0) {
		return 0;
	}
	return c[n][k];
}

long long d[1100][1100];

long long calc(long long n, long long m) {
	long long res = 0;
	for (int x = 0; x + x <= n - m; ++x) {
		long long coef = 1;
		coef *= cnk(n - m, x + x);
		coef %= P;
		coef *= fc[x + x];
		coef %= P;
		coef *= inverse(powmod(2, x));
		coef %= P;
		coef *= inverse(fc[x]);
		coef %= P;

		//res += coef;
		//res %= P;

		for (int y = 0; y <= m && y <= n - m - 2 * x; ++y) {
			coef *= cnk(m, y);
			coef %= P;
			coef *= cnk(n - m - 2 * x, y);
			coef %= P;
			coef *= fc[y];
			coef %= P;

			for (int z = 0; z <= m - y && z + z <= n - m - 2 * x - y; ++z) {
				coef *= cnk(m - y, z);
				coef %= P;
				coef *= cnk(n - m - 2 * x - y, 2 * z);
				coef %= P;
				coef *= fc[2 * z];
				coef %= P;
				coef *= inverse(powmod(2, z));
				coef %= P;

				coef *= f[m - y - z];
				coef %= P;

				res += coef;
				res %= P;
			}
		}
	}
	return res;
}

long long calculate(long long n, long long m) {
	if (m == 0) {
		return f[n];
	}

	long long res = 0;
	long long cnk = 1LL;
	for (int k = 0; k <= m && k <= n - m; ++k) {
		long long coefficient = f[n - k] * f[m - k] - f[m - k];
		coefficient %= P;
		if (coefficient < 0) {
			coefficient += P;
		}
		res += cnk * coefficient;
		res %= P;
		cnk *= (n - m - k);
		cnk %= P;
		cnk *= inverse(k + 1);
		cnk %= P;
	}
	return res;
}

void rec(State& S) {
	if (states.count(S)) {
		return ;
	}
	states.insert(S);
	orders.insert(S.order);
	int n = S.attempts.size();
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (S.attempts[i] > 0 && S.attempts[j] > 0) {
				--S.attempts[i];
				--S.attempts[j];
				swap(S.order[i], S.order[j]);
				rec(S);
				++S.attempts[i];
				++S.attempts[j];
				swap(S.order[i], S.order[j]);
			}
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	memset(d, -1, sizeof(d));
	precalc();
	int n;
	scanf("%d", &n);
	int m = 0;
	for (int i = 0; i < n; ++i) {
		int value;
		scanf("%d", &value);
		if (value == 2) {
			++m;
		}
	}

	cout << a[n][m] << endl;
	/*vector < int > order(n), attempts(n);
	for (int i = 0; i < n; ++i) {
		order[i] = i + 1;
		scanf("%d", &attempts[i]);
	}

	State current(order, attempts);
	rec(current);

	cout << orders.size() << endl;*/

	return 0;
}