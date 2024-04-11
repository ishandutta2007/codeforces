#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <bitset>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 8;
const int P = 1000000007LL;
int w[maxN];

int d[2][1 << maxN];

inline bool hasBit(int mask, int index) {
	return mask & (1 << index);
}

inline void add(int &x, int delta) {
	x += delta - P;
	x += (P & (x >> 31));
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	for (int i = 1; i <= 7; ++i) {
		cin >> w[i];
	}

	int last = 0;
	for (int i = 7; i >= 1; --i) {
		if (w[i]) {
			last = i;
			break;
		}
	}

	int u = 0, v = 1;
	d[u][1] = 1;
	for (int k = 1; k <= last; ++k) {
		memset(d[v], 0, sizeof(d[v]));
		for (int i = 0; i < (1 << k); ++i) {
			d[v][i + (1 << k)] = d[u][i];
		}
		swap(u, v);

		for (int i = 0; i < w[k]; ++i) {
			for (int j = 0; j < k; ++j, swap(u, v)) {
				memset(d[v], 0, sizeof(d[v]));
				for (int mask = 0; mask < (1 << (k + 1)); ++mask) {
					if (d[u][mask] == 0) {
						continue;
					}

					if (j == 0) {
						int nmask = mask;
						if (hasBit(nmask, k)) { nmask ^= (1 << k); }
						if (hasBit(nmask, 0)) { nmask ^= 1; }
						nmask <<= 1;

						bool filled = hasBit(mask, k);
						if (j != k - 1) {
							add(d[v][nmask], d[u][mask]);
							add(d[v][nmask + 2], d[u][mask]);
						}
						add(d[v][nmask + 1], d[u][mask]);
						if (!filled) {
							add(d[v][nmask + 3], d[u][mask]);
						}
					} else {
						int nmask = mask;
						if (hasBit(nmask, k)) { nmask ^= (1 << k); }
						if (hasBit(nmask, 0)) { nmask ^= 1; }
						nmask <<= 1;

						bool filled = hasBit(mask, k) && hasBit(mask, 0);
						if (j != k - 1) {
							add(d[v][nmask], d[u][mask]);
							add(d[v][nmask + 2], d[u][mask]);
						}
						add(d[v][nmask + 1], d[u][mask]);
						if (!filled) {
							add(d[v][nmask + 3], d[u][mask]);
						}
					}
				}
			}
		}
	}

	printf("%d\n", d[u][(1 << (last + 1)) - 1]);

	//cerr << clock() << endl;
	
	return 0;
}