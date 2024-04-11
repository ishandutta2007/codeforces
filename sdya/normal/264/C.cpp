#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <bitset>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const long long inf = 1000000000000000000LL;
const int maxN = 110000;
int n, q;
int v[maxN], c[maxN];
long long d[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &v[i]);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &c[i]);
	}

	for (int step = 0; step < q; ++step) {
		int a, b;
		scanf("%d%d", &a, &b);
		for (int i = 1; i <= n; ++i) {
			d[i] = -inf;
		}

		long long mx1 = 0, mx2 = 0;
		long long res = 0;

		for (int i = 0; i < n; ++i) {
			long long best = d[c[i]] + (long long)(v[i]) * (long long)(a);
			if (d[c[i]] != mx1) {
				best = max(best, mx1 + (long long)(v[i]) * (long long)(b));
			} else {
				best = max(best, mx2 + (long long)(v[i]) * (long long)(b));
			}

			res = max(res, best);
			if (best > d[c[i]]) {
				if (d[c[i]] == mx1) {
					mx1 = best;
				} else if (d[c[i]] == mx2) {
					mx2 = best;
					if (mx1 < mx2) {
						swap(mx1, mx2);
					}
				} else {
					long long mx3 = best;
					if (mx1 < mx2) {
						swap(mx1, mx2);
					}
					if (mx1 < mx3) {
						swap(mx1, mx3);
					}
					if (mx2 < mx3) {
						swap(mx2, mx3);
					}
				}
				d[c[i]] = best;	
			}
		}

		cout << res << endl;
	}

	return 0;
}