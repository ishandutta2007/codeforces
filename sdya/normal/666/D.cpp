#define _CRT_SECURE_NO_WARNINGS
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
#include <stack>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
#include <list>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int inf = 1000000000;
int x[4], y[4];
int order[4];

int sx[4] = {0, 1, 1, 0};
int sy[4] = {0, 0, 1, 1};

int dx[4] = {-1, 0, 0, 1};
int dy[4] = { 0,-1, 1, 0};

int d[4];

bool setValue(int &v, int nv) {
	if (v == nv) {
		return true;
	}
	if (v == inf) {
		v = nv;
		return true;
	}
	return false;
}

int fx[4], fy[4];
int ansx[4], ansy[4];

int calc() {
	int cx = inf, cy = inf;
	int cxd = inf, cyd = inf;

	for (int i = 0; i < 4; ++i) {
		int j = order[i];

		if (dx[d[i]] == 0 && sx[j] == 0) {
			if (!setValue(cx, x[i])) {
				return inf;
			}
		}
		if (dx[d[i]] == 0 && sx[j] == 1) {
			if (!setValue(cxd, x[i])) {
				return inf;
			}
		}
		if (dy[d[i]] == 0 && sy[j] == 0) {
			if (!setValue(cy, y[i])) {
				return inf;
			}
		}
		if (dy[d[i]] == 0 && sy[j] == 1) {
			if (!setValue(cyd, y[i])) {
				return inf;
			}
		}
	}

	int d = inf;
	if (cx != inf && cxd != inf) {
		if (!setValue(d, cxd - cx)) {
			return inf;
		}
	}
	if (cy != inf && cyd != inf) {
		if (!setValue(d, cyd - cy)) {
			return inf;
		}
	}
	if (d < 1) {
		return inf;
	}

	if (d != inf) {
		if (cx != inf) {
			cxd = cx + d;
		}
		if (cxd != inf) {
			cx = cxd - d;
		}

		if (cy != inf) {
			cyd = cy + d;
		}
		if (cyd != inf) {
			cy = cyd - d;
		}
	}

	if (cx != inf && cy != inf && d != inf) {
		int res = 0;
		for (int i = 0; i < 4; ++i) {
			int j = order[i];
			int nx = cx + sx[j] * d;
			int ny = cy + sy[j] * d;

			fx[i] = nx;
			fy[i] = ny;

			res = max(res, abs(nx - x[i]) + abs(ny - y[i]));
		}
		return res;
	}

	if (d == inf) {
		return inf;
	}

	/*if (cy == inf) {
		int ry = -inf;
		int ly = inf;
		for (int i = 0; i < 4; ++i) {
			int j = order[i];

			if (dx[::d[i]] == 0) {
				if (dy[::d[i]] > 0) {
					ry = max(ry, y[i]);
				} else {
					ly = min(ly, y[i]);
				}
			}
		}
		if (ry - ly > d) {
			return inf;
		}

		int l = 1, r = inf;
		while (r - l > 1) {
			int middle = (l + r) / 2;

			int lbound = -inf, rbound = inf;
			for (int i = 0; i < 4; ++i) {
				int j = order[i];

				if (dx[::d[i]] == 0) {
					if (dy[::d[i]] > 0) {
						rbound = min(rbound, y[i] + middle);
					} else {
						lbound = max(lbound, y[i] - middle);
					}
				}
			}
			if (lbound <= ly && rbound >= ry && rbound - lbound >= d) {
				r = middle;
			} else {
				l = middle;
			}
		}

		for (int middle = l; middle <= r; ++middle) {
			int lbound = -inf, rbound = inf;
			for (int i = 0; i < 4; ++i) {
				int j = order[i];

				if (dx[::d[i]] == 0) {
					if (dy[::d[i]] > 0) {
						rbound = min(rbound, y[i] + middle);
					} else {
						lbound = max(lbound, y[i] - middle);
					}
				}
			}
			if (lbound <= ly && rbound >= ry && rbound - lbound >= d) {
				cy = lbound;
				cyd = cy + d;
				if (cyd < ry) {
					cy += ry - cyd;
					cyd = ry;
				}

				int res = 0;
				for (int i = 0; i < 4; ++i) {
					int j = order[i];
					int nx = cx + sx[j] * d;
					int ny = cy + sy[j] * d;

					fx[i] = nx;
					fy[i] = ny;

					res = max(res, abs(nx - x[i]) + abs(ny - y[i]));
				}
				return res;
			}
		}
	}*/

	if (cy == inf) {
		int l = 1, r = 1000000000;
		while (r - l > 1) {
			int middle = (l + r) / 2;

			int ly[4], ry[4];

			vector < int > lbound, rbound;
			for (int i = 0; i < 4; ++i) {
				int j = order[i];

				int rem = middle - abs(x[i] - cx - sx[j] * d);
				if (rem < 0) {
					ly[i] = 1;
					ry[i] = 0;
					continue;
				} 
				ly[i] = y[i] - rem;
				ry[i] = y[i] + rem;
				if (sy[j] == 0) {
					lbound.push_back(i);
				} else {
					rbound.push_back(i);
				}
			}

			bool good = true;
			for (int i = 0; i < 4; ++i) {
				if (ly[i] > ry[i]) {
					good = false;
				}
			}

			int l1 = -inf, r1 = inf;
			int l2 = -inf, r2 = inf;
			for (int i = 0; i < lbound.size(); ++i) {
				l1 = max(l1, ly[lbound[i]]);
				r1 = min(r1, ry[lbound[i]]);

				l2 = max(l2, ly[rbound[i]]);
				r2 = min(r2, ry[rbound[i]]);
			}

			if (l1 > r1 || l2 > r2) {
				good = false;
			}

			if (good && (r2 - l1 >= d && l2 - r1 <= d)) {
				r = middle;
			} else {
				l = middle;
			}
		}

		for (int middle = l; middle <= r; ++middle) {
			int ly[4], ry[4];

			vector < int > lbound, rbound;
			for (int i = 0; i < 4; ++i) {
				int j = order[i];

				int rem = middle - abs(x[i] - cx - sx[j] * d);
				if (rem < 0) {
					ly[i] = 1;
					ry[i] = 0;
					continue;
				} 
				ly[i] = y[i] - rem;
				ry[i] = y[i] + rem;
				if (sy[j] == 0) {
					lbound.push_back(i);
				} else {
					rbound.push_back(i);
				}
			}

			bool good = true;
			for (int i = 0; i < 4; ++i) {
				if (ly[i] > ry[i]) {
					good = false;
				}
			}

			int l1 = -inf, r1 = inf;
			int l2 = -inf, r2 = inf;
			for (int i = 0; i < lbound.size(); ++i) {
				l1 = max(l1, ly[lbound[i]]);
				r1 = min(r1, ry[lbound[i]]);

				l2 = max(l2, ly[rbound[i]]);
				r2 = min(r2, ry[rbound[i]]);
			}

			if (l1 > r1 || l2 > r2) {
				good = false;
			}

			if (good && (r2 - l1 >= d && l2 - r1 <= d)) {
								cy = l1;
				cyd = l1 + d;
				if (cyd < l2) {
					cy += l2 - cyd;
					cyd = l2;
				}

				int res = 0;
				for (int i = 0; i < 4; ++i) {
					int j = order[i];
					int nx = cx + sx[j] * d;
					int ny = cy + sy[j] * d;

					fx[i] = nx;
					fy[i] = ny;

					res = max(res, abs(nx - x[i]) + abs(ny - y[i]));
				}
				return res;
			}
		}
	}

	if (cx == inf) {
		int l = 1, r = 1000000000;
		while (r - l > 1) {
			int middle = (l + r) / 2;

			int lx[4], rx[4];

			vector < int > lbound, rbound;
			for (int i = 0; i < 4; ++i) {
				int j = order[i];

				int rem = middle - abs(y[i] - cy - sy[j] * d);
				if (rem < 0) {
					lx[i] = 1;
					rx[i] = 0;
					continue;
				} 
				lx[i] = x[i] - rem;
				rx[i] = x[i] + rem;
				if (sx[j] == 0) {
					lbound.push_back(i);
				} else {
					rbound.push_back(i);
				}
			}

			bool good = true;
			for (int i = 0; i < 4; ++i) {
				if (lx[i] > rx[i]) {
					good = false;
				}
			}

			int l1 = -inf, r1 = inf;
			int l2 = -inf, r2 = inf;
			for (int i = 0; i < lbound.size(); ++i) {
				l1 = max(l1, lx[lbound[i]]);
				r1 = min(r1, rx[lbound[i]]);

				l2 = max(l2, lx[rbound[i]]);
				r2 = min(r2, rx[rbound[i]]);
			}

			if (l1 > r1 || l2 > r2) {
				good = false;
			}

			if (good && (r2 - l1 >= d && l2 - r1 <= d)) {
				r = middle;
			} else {
				l = middle;
			}
		}
		
		for (int middle = l; middle <= r; ++middle) {
			int lx[4], rx[4];

			vector < int > lbound, rbound;
			for (int i = 0; i < 4; ++i) {
				int j = order[i];

				int rem = middle - abs(y[i] - cy - sy[j] * d);
				if (rem < 0) {
					lx[i] = 1;
					rx[i] = 0;
					continue;
				} 
				lx[i] = x[i] - rem;
				rx[i] = x[i] + rem;
				if (sx[j] == 0) {
					lbound.push_back(i);
				} else {
					rbound.push_back(i);
				}
			}

			bool good = true;
			for (int i = 0; i < 4; ++i) {
				if (lx[i] > rx[i]) {
					good = false;
				}
			}

			int l1 = -inf, r1 = inf;
			int l2 = -inf, r2 = inf;
			for (int i = 0; i < lbound.size(); ++i) {
				l1 = max(l1, lx[lbound[i]]);
				r1 = min(r1, rx[lbound[i]]);

				l2 = max(l2, lx[rbound[i]]);
				r2 = min(r2, rx[rbound[i]]);
			}

			if (l1 > r1 || l2 > r2) {
				good = false;
			}

			if (good && (r2 - l1 >= d && l2 - r1 <= d)) {
				cx = l1;
				cxd = l1 + d;
				if (cxd < l2) {
					cx += l2 - cxd;
					cxd = l2;
				}

				int res = 0;
				for (int i = 0; i < 4; ++i) {
					int j = order[i];
					int nx = cx + sx[j] * d;
					int ny = cy + sy[j] * d;

					fx[i] = nx;
					fy[i] = ny;

					res = max(res, abs(nx - x[i]) + abs(ny - y[i]));
				}
				return res;
			}
		}
	}

	/*if (cx == inf) {
		int rx = -inf;
		int lx = inf;
		for (int i = 0; i < 4; ++i) {
			int j = order[i];

			if (dy[::d[i]] == 0) {
				if (dx[::d[i]] > 0) {
					rx = max(rx, x[i]);
				} else {
					lx = min(lx, x[i]);
				}
			}
		}
		if (rx - lx > d) {
			return inf;
		}

		int l = 1, r = inf;
		while (r - l > 1) {
			int middle = (l + r) / 2;

			int lbound = -inf, rbound = inf;
			for (int i = 0; i < 4; ++i) {
				int j = order[i];

				if (dy[::d[i]] == 0) {
					if (dx[::d[i]] > 0) {
						rbound = min(rbound, x[i] + middle);
					} else {
						lbound = max(lbound, x[i] - middle);
					}
				}
			}
			if ((lbound <= lx && rbound >= rx && rbound - lbound >= d)
				|| (rx < lx && lx - rx >= d && lbound - rbound <= d))
			{
				r = middle;
			} else {
				l = middle;
			}
		}

		for (int middle = l; middle <= r; ++middle) {
			int lbound = -inf, rbound = inf;
			for (int i = 0; i < 4; ++i) {
				int j = order[i];

				if (dy[::d[i]] == 0) {
					if (dx[::d[i]] > 0) {
						rbound = min(rbound, x[i] + middle);
					} else {
						lbound = max(lbound, x[i] - middle);
					}
				}
			}
			if ((lbound <= lx && rbound >= rx && rbound - lbound >= d)
				|| (rx < lx && lx - rx >= d && lbound - rbound <= d))
			{
				cx = lbound;
				cxd = cx + d;
				if (cxd < rx) {
					cx += rx - cxd;
					cxd = rx;
				}

				if (rx < lx && lx - rx >= d && lbound - rbound <= d) {
					cx = rx;
					cxd = rx + d;
					if (cxd < lbound) {
						cx += lbound - cxd;
						cxd = lbound;
					}
				}

				int res = 0;
				for (int i = 0; i < 4; ++i) {
					int j = order[i];
					int nx = cx + sx[j] * d;
					int ny = cy + sy[j] * d;

					fx[i] = nx;
					fy[i] = ny;

					res = max(res, abs(nx - x[i]) + abs(ny - y[i]));
				}
				return res;
			}
		}
	}*/

	return inf;
}
 
void solve() {
	for (int i = 0; i < 4; ++i) {
		scanf("%d%d", &x[i], &y[i]);
		order[i] = i;
	}

	int res = inf;
	do {
		for (int mask = 0; mask < (1 << 8); ++mask) {
			d[0] = mask % 4;
			d[1] = (mask / 4) % 4;
			d[2] = (mask / 16) % 4;
			d[3] = (mask / 64);

			int value = calc();
			if (value < res) {
				res = value;
				for (int i = 0; i < 4; ++i) {
					ansx[i] = fx[i];
					ansy[i] = fy[i];
				}
			}
			res = min(res, calc());
		}
	} while (next_permutation(order, order + 4));

	if (res == inf) {
		printf("-1\n");
	} else {
		printf("%d\n", res);
		for (int i = 0; i < 4; ++i) {
			printf("%d %d\n", ansx[i], ansy[i]);
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		solve();
	}



	return 0;
}