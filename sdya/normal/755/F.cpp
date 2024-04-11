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

const int maxN = 1100000;
int n, k;
int p[maxN], ip[maxN];

bool used[maxN];

pair < int, int > trivial(int n, int k) {
	int mn = n, mx = 0;
	for (int i = 0; i < (1 << n); ++i) {
		int cnt = 0;
		for (int j = 0; j < n; ++j) {
			if (i & (1 << j)) {
				++cnt;
			}
		}
		if (cnt != k) {
			continue;
		}

		int r = 0;
		for (int j = 0; j < n; ++j) {
			if ((i & (1 << j)) || (i & (1 << ip[j]))) {
				++r;
			}
		}
		mn = min(mn, r);
		mx = max(mx, r);
	}
	return make_pair(mn, mx);
}

int calcMax(vector < int > &cycles, int n, int k) {
	multiset < int > S;
	for (int i = 0; i < cycles.size(); ++i) {
		int m = cycles[i];
		for (int j = 0; j < m / 2; ++j) {
			S.insert(-2);
		}
		for (int j = 0; j < m / 2; ++j) {
			S.insert(0);
		}
		if (m % 2 == 1) {
			S.insert(-1);
		}
	}

	int a = 0;
	for (int i = 0; i < k; ++i) {
		int v = *S.begin();
		a -= v;
		S.erase(S.begin());
	}
	return a;
}

int cnt[maxN];
int id[maxN];

bool check(vector < pair < int, int > > &p, int s) {
	cnt[0] = 0;
	for (int i = 0; i < p.size(); ++i) {
		int m = p[i].first;
		int v = p[i].second;

		for (int j = 0; j + m <= s; ++j) {
			if (cnt[j] == -1 || cnt[j + m] != -1) {
				continue;
			}
			if (id[j] < i || cnt[j] + 1 <= v) {
				cnt[j + m] = (id[j] < i ? 1 : cnt[j] + 1);
				id[j + m] = i;
			}
		}
		if (cnt[s] != -1) {
			return true;
		}
	}
	return false;
}

int calcMin(vector < int > &cycles, int n, int k) {
	vector < pair < int, int > > p;
	int l = 0;
	for (int i = 1; i <= cycles.size(); ++i) {
		if (i == cycles.size() || cycles[i] > cycles[i - 1]) {
			p.push_back(make_pair(cycles[l], i - l));
			l = i;
		}
	}

	if (check(p, min(k, n - k))) {
		return k;
	}
	return k + 1;
}

pair < int, int > clever(int n, int k) {
	vector < int > cycles;
	for (int i = 0; i < n; ++i) {
		used[i] = false;
	}
	for (int i = 0; i <= n; ++i) {
		cnt[i] = -1;
		id[i] = -1;
	}
	for (int i = 0; i < n; ++i) {
		if (used[i]) {
			continue;
		}

		int v = i;
		int len = 0;
		while (!used[v]) {
			++len;
			used[v] = true;
			v = p[v];
		}
		cycles.push_back(len);
	}
	sort(cycles.begin(), cycles.end());

	int a = calcMax(cycles, n, k);
	int b = calcMin(cycles, n, k);
	return make_pair(b, a);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &p[i]);
		--p[i];
		ip[p[i]] = i;
	}

	pair < int, int > res = clever(n, k);
	printf("%d %d\n", res.first, res.second);

	return 0;

	for (int n = 1; n <= 10; ++n) {
		cerr << n << endl;
		for (int k = 0; k <= n; ++k) {
			vector < int > a(n);
			for (int i = 0; i < n; ++i) {
				a[i] = i;
			}

			do {
				bool bad = false;
				for (int i = 0; i < n; ++i) {
					p[i] = a[i];
					ip[p[i]] = i;
					if (a[i] == i) {
						bad = true;
					}
				}
				if (bad) {
					continue;
				}
				if (trivial(n, k) != clever(n, k)) {
					for (int j = 0; j < n; ++j) {
						printf("%d ", a[j] + 1);
					}
					printf("\n");
					printf("%d\n", k);
					printf("%d %d\n", trivial(n, k).first, trivial(n, k).second);
					printf("%d %d\n", clever(n, k).first, clever(n, k).second);
					return 0;
				}
			} while (next_permutation(a.begin(), a.end()));
		}
	}

	return 0;
}