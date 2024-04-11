#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <bitset>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const long long inf = 1000000000000000000LL;
const int maxN = 310000;
int a[maxN], b[maxN];
int n, m;
int order[maxN];
int pA[maxN], posA[maxN];
int pB[maxN], posB[maxN];

bool cmp(int x, int y) {
	return a[x] - b[x] < a[y] - b[y];
}

bool cmpA(int x, int y) {
	return a[x] < a[y];
}

bool cmpB(int x, int y) {
	return b[x] < b[y];
}

long long fA[maxN], fB[maxN];
int cntA[maxN], cntB[maxN];

void updateF(long long f[], int k, long long delta) {
	for (int i = k; i < maxN; i |= (i + 1)) {
		f[i] += delta;
	}
}

long long getF(long long f[], int k) {
	long long res = 0;
	for (int i = k; i >= 0; i = (i & (i + 1)) - 1) {
		res += f[i];
	}
	return res;
}

void updateC(int f[], int k, int delta) {
	for (int i = k; i < maxN; i |= (i + 1)) {
		f[i] += delta;
	}
}

int getC(int f[], int k) {
	int res = 0;
	for (int i = k; i >= 0; i = (i & (i + 1)) - 1) {
		res += f[i];
	}
	return res;
}

int getPos(int cnt[], int k) {
	int left_bound = 0, right_bound = n - 1;
	while (right_bound - left_bound > 1) {
		int middle = (left_bound + right_bound) / 2;
		if (getC(cnt, middle) >= k) {
			right_bound = middle;
		} else {
			left_bound = middle;
		}
	}
	if (getC(cnt, left_bound) == k) {
		return left_bound;
	} else {
		return right_bound;
	}
}

long long calc(int ones, int twos) {
	return getF(fA, getPos(cntA, ones)) + getF(fB, getPos(cntB, twos));
}

int res[maxN];

bool check(int x, int y, int k) {
	int posR = getPos(cntA, x + 2 * k);
	int posL = getPos(cntA, x + 2 * k - 1);
	long long sumA = getF(fA, posR) - getF(fA, posL - 1);
	int posB = getPos(cntB, y + 1 - k);
	long long sumB = getF(fB, posB) - getF(fB, posB - 1);
	return sumA < sumB;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &a[i], &b[i]);
		pA[i] = i;
		pB[i] = i;
		order[i] = i;
	}

	sort(order, order + n, cmp);
	sort(pA, pA + n, cmpA);
	sort(pB, pB + n, cmpB);

	for (int i = 0; i < n; ++i) {
		posA[pA[i]] = i;
		posB[pB[i]] = i;
	}

	for (int i = 0; i < n; ++i) {
		updateC(cntB, posB[order[i]], +1);
		updateF(fB, posB[order[i]], b[order[i]]);
	}

	long long best = inf;
	int split = -1;
	int x = -1;
	int y = -1;

	for (int i = 0; i <= n; ++i) {
		int ones = i;
		int twos = n - i;

		int left_bound = 0, right_bound = min(ones, m);
		bool good = true;
		if (2 * twos < m) {
			left_bound = m - 2 * twos;
		}
		if (left_bound <= right_bound) {
			int u = left_bound;
			int v = (m + 1 - u) / 2;
			if (u + 2 * v > m) {
				++u;
				--v;
			}
			if (u <= right_bound) {
				long long score = calc(u, v);
				if (score < best) {
					best = score;
					split = i;
					x = u;
					y = v;
				}
				if (u + 2 <= right_bound) {
					int l = 1, r = (right_bound - u) / 2;
					r = min(r, v);

					while (r - l > 1) {
						int k = (l + r) / 2;
						if (check(u, v, k)) {
							l = k;
						} else {
							r = k;
						}
					}

					int bound = r;
					if (check(u, v, r)) {
						bound = r;
					} else {
						bound = l;
					}
					long long current = calc(u + 2 * bound, v - bound);
					if (current < best) {
						best = current;
						split = i;
						x = u + 2 * bound;
						y = v - bound;
					}
				}
			}
		}
		/*if (left_bound <= right_bound && getF(fA, getPos(cntA, left_bound)) >= best) {
			good = false;
		}
		if (left_bound <= right_bound && good) {
			while (right_bound - left_bound > 3) {
				int l = (left_bound * 2 + right_bound) / 3;
				int r = (left_bound + right_bound * 2) / 3;

				long long A = calc(l, (m - l + 1) / 2);
				long long B = calc(r, (m - r + 1) / 2);

				if (A < B) {
					right_bound = r;
				} else {
					left_bound = l;
				}
			}
			for (int j = left_bound; j <= right_bound; ++j) {
				long long cur = calc(j, (m - j + 1) / 2);
				if (cur < best) {
					best = cur;
					split = i;
					x = j;
					y = (m - j + 1) / 2;
				}
			}
		}*/
		if (i != n) {
			updateC(cntA, posA[order[i]], +1);
			updateF(fA, posA[order[i]], a[order[i]]);

			updateC(cntB, posB[order[i]], -1);
			updateF(fB, posB[order[i]], -b[order[i]]);
		}
	}

	cout << best << endl;
	vector < pair < int, int > > sA, sB;
	for (int i = 0; i < n; ++i) {
		if (i < split) {
			sA.push_back(make_pair(a[order[i]], order[i]));
		} else {
			sB.push_back(make_pair(b[order[i]], order[i]));
		}
	}

	sort(sA.begin(), sA.end());
	sort(sB.begin(), sB.end());
	for (int i = 0; i < x; ++i) {
		res[sA[i].second] = 1;
	}
	for (int i = 0; i < y; ++i) {
		res[sB[i].second] = 2;
	}

	for (int i = 0; i < n; ++i) {
		printf("%d", res[i]);
	}
	printf("\n");

	return 0;
}