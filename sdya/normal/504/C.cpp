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

const int maxN = 210000;
int n, a[maxN], cnt[maxN], cnt2[maxN];

void trivial() {
	int res = 0;
	for (int l = 0; l < n; ++l) {
		for (int r = l; r < n; ++r) {
			vector < int > b(n);
			for (int i = 0; i < n; ++i) {
				b[i] = a[i];
			}
			sort(b.begin() + l, b.begin() + r + 1);
			bool isgood = false;
			do {
				bool nice = true;
				for (int i = 0, j = n - 1; i < n; ++i, --j) {
					if (b[i] != b[j]) {
						nice = false;
						break;
					}
				}
				if (nice) {
					isgood = true;
					break;
				}
			} while (next_permutation(b.begin() + l, b.begin() + r + 1));
			if (isgood) {
				++res;
			}
		}
	}
	cout << res << endl;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		++cnt[a[i]];
	}

	int odd = 0, value = -1;
	for (int i = 0; i < maxN; ++i) {
		if (cnt[i] % 2 == 1) {
			++odd;
			value = i;
		}
	}

	if (odd > 1) {
		printf("0\n");
		return 0;
	}

	//trivial();

	int mx = 0;
	for (int i = 0, j = n - 1; i < n; ++i, --j) {
		if (a[i] == a[j]) {
			++mx;
		} else {
			break;
		}
	}

	int center = 0;
	if (n % 2 == 0) {
		for (int i = n / 2 - 1, j = n / 2; i >= 0; --i, ++j) {
			if (a[i] == a[j]) {
				++center;
			} else {
				break;
			}
		}
	} else {
		for (int i = n / 2 - 1, j = n / 2 + 1; i >= 0; --i, ++j) {
			if (a[i] == a[j]) {
				++center;
			} else {
				break;
			}
		}
	}

	long long res = 0;

	bool goodhalves = true;
	if (n % 2 == 0) {
		vector < int > u, v;
		for (int i = 0; i < n; ++i) {
			if (i < n / 2) {
				u.push_back(a[i]);
			} else {
				v.push_back(a[i]);
			}
		}
		sort(u.begin(), u.end());
		sort(v.begin(), v.end());
		goodhalves = (u == v);
	} else {
		vector < int > u, v;
		for (int i = 0; i < n; ++i) {
			if (i <= n / 2) {
				u.push_back(a[i]);
			}
			if (i >= n / 2) {
				v.push_back(a[i]);
			}
		}
		sort(u.begin(), u.end());
		sort(v.begin(), v.end());
		goodhalves = (u == v);
	}

	int gbound = n;
	for (int i = n - 1; i >= n / 2; --i) {
		++cnt2[a[i]];
		if (cnt[a[i]] % 2 == 0) {
			if (cnt2[a[i]] * 2 <= cnt[a[i]]) {
				gbound = i;
				continue;
			}
			break;
		} else {
			if (i > n / 2) {
				if (cnt2[a[i]] * 2 <= cnt[a[i]]) {
					gbound = i;
					continue;
				}
				break;
			} else {
				if (cnt2[a[i]] * 2 <= cnt[a[i]] + 1) {
					gbound = i;
					continue;
				}
				break;
			}
		}
	}
	--gbound;


	int gbound2 = -1;
	for (int i = 0; i < maxN; ++i) {
		cnt2[i] = 0;
	}
	for (int i = 0; i < (n + 1) / 2; ++i) {
		++cnt2[a[i]];
		if (cnt[a[i]] % 2 == 0) {
			if (cnt2[a[i]] * 2 <= cnt[a[i]]) {
				gbound2 = i;
				continue;
			}
			break;
		} else {
			if (i < n / 2) {
				if (cnt2[a[i]] * 2 <= cnt[a[i]]) {
					gbound2 = i;
					continue;
				}
				break;
			} else {
				if (cnt2[a[i]] * 2 <= cnt[a[i]] + 1) {
					gbound2 = i;
					continue;
				}
				break;
			}
		}
	}
	++gbound2;
	if (n % 2 == 0) {
		for (int l = 0; l < n / 2; ++l) {
			if (l > gbound2) {
				break;
			}
			if (l <= mx) {
				res += n - max(gbound, n / 2);
			} else {
				int u = max(max(gbound, n / 2), n - mx - 1);
				res += n - u;
			}
		}

		for (int steps = 0; steps < 2; ++steps) {
			if (!goodhalves) {
				continue;
			}
			for (int r = 0; r < n / 2; ++r) {
				if (n / 2 - r - 1 > center) {
					continue;
				}

				int bound = min(mx, r);
				res += bound + 1;
			}

			for (int i = 0, j = n - 1; i <= j; ++i, --j) {
				swap(a[i], a[j]);
			}
		}
	} else {
		for (int l = 0; l <= n / 2; ++l) {
			if (l > gbound2) {
				break;
			}
			if (l <= mx) {
				res += n - max(gbound, n / 2);
			} else {
				int u = max(max(gbound, n / 2), n - mx - 1);
				res += n - u;
			}
		}

		for (int steps = 0; steps < 2; ++steps) {
			if (!goodhalves) {
				continue;
			}
			for (int r = 0; r < n / 2; ++r) {
				if (n / 2 - r - 1 > center) {
					continue;
				}
				if (a[n / 2] != value) {
					continue;
				}

				int bound = min(mx, r);
				res += bound + 1;
			}

			for (int i = 0, j = n - 1; i <= j; ++i, --j) {
				swap(a[i], a[j]);
			}
		}
	}

	cout << res << endl;

	return 0;
}