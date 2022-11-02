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

const int maxN = 8;
long long d[maxN][maxN];
long long x[maxN], y[maxN], z[maxN];
long long a[maxN][3];

int id[maxN];
bool used[maxN];

void rec(int have, long long coef) {
        if (coef == 0) return ;
	if (have == 8) {
		cout << "YES" << endl;
		for (int i = 0; i < 8; ++i) {
			cout << a[i][0] << " " << a[i][1] << " " << a[i][2] << endl;	
		}
		exit(0);
	}

	a[have][0] = x[have];
	a[have][1] = y[have];
	a[have][2] = z[have];

	sort(a[have], a[have] + 3);

	do {
		for (int i = 0; i < 8; ++i) {
			if (used[i]) {
				continue;
			}
			bool nice = true;
			if (coef != -1) {
				for (int j = 0; j < 8; ++j) {
					if (!used[j]) {
						continue;
					}

					int pos = id[j];
					long long cur = 0;
					for (int k = 0; k < 3; ++k) {
						cur += (a[pos][k] - a[have][k]) * (a[pos][k] - a[have][k]);
					}

					if (cur != coef * d[i][j]) {
						nice = false;
						break;
					}
				}

				if (nice) {
					used[i] = true;
					id[i] = have;
					rec(have + 1, coef);
					used[i] = false;
				}
			} else {
				if (have == 0) {
					used[i] = true;
					id[i] = have;
					rec(have + 1, -1);
					used[i] = false;
				} else {
					long long ncoef = -1;
					for (int j = 0; j < 8; ++j) {
						if (!used[j]) {
							continue;
						}

						int pos = id[j];
						long long cur = 0;
						for (int k = 0; k < 3; ++k) {
							cur += (a[pos][k] - a[have][k]) * (a[pos][k] - a[have][k]);
						}

						if (ncoef == -1) {
							if (cur % d[i][j] != 0) {
								nice = false;
								break;
							}
							ncoef = cur / d[i][j];
						} else {
							if (cur != ncoef * d[i][j]) {
								nice = false;
								break;
							}
						}
					}
					if (nice) {
						used[i] = true;
						id[i] = have;
						rec(have + 1, ncoef);
						used[i] = false;
					}
				}
			}
		}
	} while (next_permutation(a[have], a[have] + 3));
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			int res = 0;
			for (int k = 0; k < 3; ++k) {
				if ((i & (1 << k)) != (j & (1 << k))) {
					++res;
				}
			}
			d[i][j] = res;
		}
	}

	for (int i = 0; i < 8; ++i) {
		cin >> x[i] >> y[i] >> z[i];
	}

	rec(0, -1);

	cout << "NO" << endl;

	return 0;
}