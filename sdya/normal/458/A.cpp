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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110000;
const long long inf = 2000000000000000000LL;

long long a[maxN];
long long b[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	string s1, s2;
	cin >> s1;
	cin >> s2;
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());

	for (int i = 0; i < s1.size(); ++i) {
		a[i] = s1[i] - '0';
	}
	for (int i = 0; i < s2.size(); ++i) {
		b[i] = s2[i] - '0';
	}

	for (int i = maxN - 1; i >= 2; --i) {
		long long current = min(a[i], b[i]);
		a[i] -= current;
		b[i] -= current;

		a[i - 1] += a[i];
		a[i - 2] += a[i];
		a[i - 1] = min(a[i - 1], inf);
		a[i - 2] = min(a[i - 2], inf);

		b[i - 1] += b[i];
		b[i - 2] += b[i];
		b[i - 1] = min(b[i - 1], inf);
		b[i - 2] = min(b[i - 2], inf);
	}

	long long p1 = min(a[1], b[1]);
	a[1] -= p1;
	b[1] -= p1;

	long long p0 = min(a[0], b[0]);
	a[0] -= p0;
	b[0] -= p0;

	if (a[1] == b[1] && a[0] == b[0]) {
		cout << "=" << endl;
		return 0;
	}

	double r1 = (sqrt(5.0) + 1.0) / 2.0 * (double)(a[1]) + (double)(a[0]);
	double r2 = (sqrt(5.0) + 1.0) / 2.0 * (double)(b[1]) + (double)(b[0]);

	if (r1 < r2) {
		cout << "<" << endl;
	} else {
		cout << ">" << endl;
	}


	return 0;
}