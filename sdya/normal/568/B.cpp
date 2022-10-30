#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <string>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const long long P = 1000000007LL;
const int maxN = 4100;

long long d[maxN], r[maxN];
int c[maxN][maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	for (int i = 0; i < maxN; ++i) {
		c[i][0] = 1;
		for (int j = 1; j <= i; ++j) {
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]);
			if (c[i][j] >= P) {
				c[i][j] -= P;
			}
		}
	}

	d[0] = 1;
	r[0] = 1;
	for (int i = 1; i < maxN; ++i) {
		for (int j = 1; j <= i; ++j) {
			d[i] += (long long)(c[i - 1][j - 1]) * d[i - j];
			d[i] %= P;
		}
		for (int j = 1; j <= i; ++j) {
			r[i] += (long long)(c[i - 1][j - 1]) * r[i - j];
			r[i] %= P;
		}
		r[i] += r[i - 1];
		r[i] %= P;
	}

	int n;
	cin >> n;
	long long res = (r[n] - d[n]) % P;
	if (res < 0) {
		res += P;
	}
	cout << res << endl;

	return 0;
}