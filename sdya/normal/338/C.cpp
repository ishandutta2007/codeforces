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

const int maxN = 10;
const int inf = 1000000;
int n;
long long a[maxN];
map < long long, int > M[maxN];

bool available[1 << maxN];
int id[1 << maxN];

map < long long, int > subtract(map < long long, int > &A, map < long long, int > &B) {
	map < long long, int > res;
	for (map < long long, int > ::iterator it = A.begin(); it != A.end(); ++it) {
		if (B.find(it->first) != B.end()) {
			int value = it->second - B[it->first];
			if (value > 0) {
				res[it->first] = value;
			}
		} else {
			res[it->first] = it->second;
		}
	}
	return res;
}

long long value(map < long long, int > &A) {
	long long res = 1;
	for (map < long long, int > ::iterator it = A.begin(); it != A.end(); ++it) {
		for (int i = 0; i < it->second; ++i) {
			res *= it->first;
		}
	}
	return res;
}

int divisors(map < long long, int > &A) {
	int res = 0;
	for (map < long long, int > ::iterator it = A.begin(); it != A.end(); ++it) {
		res += it->second;
	}
	return res;
}

map < pair < long long, pair < int, int > >, int > R;

int calc(long long root, int assigned, int whole, map < long long, int > A) {
	pair < long long, pair < int, int > > current = make_pair(root, make_pair(assigned, whole));
	if (R.count(current)) {
		return R[current];
	}
	int res = divisors(A);
	if (whole && res == 1) {
		res = 0;
	}
	int submask = assigned;
	if (submask == 0) {
		return R[current] = res;
	}
	res = inf;
	int s = submask;
	while (s) {
		if (available[s] && (root % a[id[s]] == 0)) {
			map < long long, int > B;
			long long nRoot;
			if (root == 0) {
				B = A;
				nRoot = 0;
			} else {
				B = subtract(A, M[id[s]]);
				nRoot = root / a[id[s]];
			}
			int X = 0, Y = 0;
			X = calc(nRoot, (assigned ^ s), 0, B);
			Y = calc(a[id[s]], (s ^ (1 << id[s])), 1, M[id[s]]);
			res = min(res, 1 + X + Y);
		}
		s = ((s - 1) & submask);
	}
	return R[current] = res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < n; ++i) {
		long long m = a[i];
		for (long long j = 2; j * j <= a[i]; ++j) {
			int q = 0;
			while (m % j == 0) {
				++q;
				m /= j;
			}
			if (q > 0) {
				M[i][j] = q;
			}
		}
		if (m > 1) {
			M[i][m] = 1;
		}
	}

	for (int i = 1; i < (1 << n); ++i) {
		int j = n - 1;
		while ((i & (1 << j)) == 0) {
			--j;
		}
		id[i] = j;
		available[i] = true;
		for (int k = 0; k < j; ++k) {
			if ((i & (1 << k)) && (a[j] % a[k]) != 0) {
				available[i] = false;
			}
		}
	}

	int res = 1 + calc(0, (1 << n) - 1, 1, map < long long, int > ());
	if (available[(1 << n) - 1]) {
		res = min(res, 1 + calc(a[n - 1], (1 << (n - 1)) - 1, 1, M[n - 1]));
	}
	cout << res << endl;

	return 0;
}