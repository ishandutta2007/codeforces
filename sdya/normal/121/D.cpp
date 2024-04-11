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

const long long inf = 2000000000000000000LL;

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

struct Long {
	long long a, b;
	Long(long long n) : a(0), b(n) {}
	Long() : a(0), b(0) {}

	bool operator < (const Long &other) const {
		return make_pair(a, b) < make_pair(other.a, other.b);
	}

	void add(const Long &other) {
		a += other.a;
		b += other.b;
		if (b >= inf) {
			b -= inf;
			++a;
		}
	}

	void sub(const Long &other) {
		a -= other.a;
		b -= other.b;
		if (b < 0) {
			b += inf;
			--a;
		}
	}
};

Long mul(const Long &A, long long k) {
	if (k == 0) {
		return Long();
	}
	if (k == 1) {
		return A;
	}
	if (A.b < (4LL * inf) / k) {
		Long B = A;
		B.a *= k;
		B.b *= k;
		if (B.b >= inf) {
			B.a += B.b / inf;
			B.b %= inf;
		}
		return B;
	}

	Long B = mul(A, k / 2);
	B.add(B);

	if (k % 2 == 1) {
		B.add(A);
	}
	return B;
}

const int maxN = 110000;
long long n, k, m;
long long l[maxN], r[maxN];
Long sl[maxN], sr[maxN];

bool check(int cnt) {
	if (cnt == 0) {
		return true;
	}
	int indexR = 0;
	int indexL = 0;
	for (int i = 0; i + cnt <= a.size(); ++i) {
		if (a[i + cnt - 1] - a[i] + 1 > m) {
			continue;
		}
		Long L = a[i];
		Long R = a[i + cnt - 1];

		Long sum;
		while (indexR < n && r[indexR] <= a[i + cnt - 1]) {
			++indexR;
		}
		sum = mul(R, indexR);
		if (indexR > 0) {
			sum.sub(sr[indexR - 1]);
		}
		if (Long(k) < sum) {
			continue;
		}
		while (indexL < n && l[indexL] < a[i]) {
			++indexL;
		}
		if (indexL < n) {
			sum.add(sl[n - 1]);
			if (indexL != 0) {
				sum.sub(sl[indexL - 1]);
			}
			sum.sub(mul(L, n - indexL));
		}
		if (sum < Long(k + 1)) {
			return true;
		}
	}
	return false;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	gen(0);
	sort(a.begin(), a.end());

	cin >> n >> k;
	m = inf;
	for (int i = 0; i < n; ++i) {
		cin >> l[i] >> r[i];
		m = min(m, r[i] - l[i] + 1LL);
	}
	sort(l, l + n);
	sort(r, r + n);

	for (int i = 0; i < n; ++i) {
		sl[i] = l[i];
		if (i > 0) {
			sl[i].add(sl[i - 1]);
		}

		sr[i] = r[i];
		if (i > 0) {
			sr[i].add(sr[i - 1]);
		}
	}

	int left_bound = 0, right_bound = a.size();
	while (right_bound - left_bound > 1) {
		int middle = (left_bound + right_bound) / 2;
		if (check(middle)) {
			left_bound = middle;
		} else {
			right_bound = middle;
		}
	}

	if (check(right_bound)) {
		cout << right_bound << endl;
	} else {
		cout << left_bound << endl;
	}

	return 0;
}