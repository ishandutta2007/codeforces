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
vector < int > d[maxN];
int n, a[maxN];
int l[maxN];
long long s[maxN];

void update(int k, int delta) {
	for (int i = k; i < maxN; i |= (i + 1)) {
		s[i] += delta;
	}
}

long long get(int k) {
	long long res = 0;
	for (int i = k; i >= 0; i = (i & (i + 1)) - 1) {
		res += s[i];
	}
	return res;
}

long long get(int l, int r) {
	if (l > r) {
		return 0;
	}
	return get(r) - get(l - 1);
}

vector < int > p[maxN];

void updateValues(int pos, int g) {
	for (int i = pos; i <= n; ++i) {
		if (l[i] >= g) {
			break;
		}
		update(i, g - l[i]);
		l[i] = g;
	}
}

void gen() {
	int n = 200000;
	printf("%d\n", n);
	vector < int > a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = i + 1;
	}
	random_shuffle(a.begin(), a.end());
	for (int i = 0; i < n; ++i) {
		printf("%d\n", a[i]);
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	//gen();

	//return 0;

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}

	for (int i = 1; i < maxN; ++i) {
		for (int j = i; j < maxN; j += i) {
			d[j].push_back(i);
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < d[a[i]].size(); ++j) {
			p[d[a[i]][j]].push_back(i);
		}
	}

	for (int i = 1; i <= n; ++i) {
		int current = l[i - 1];
		for (int j = 0; j < d[a[i]].size(); ++j) {
			int g = d[a[i]][j];
			if (g <= current) {
				continue;
			}
			int pos = lower_bound(p[g].begin(), p[g].end(), i) - p[g].begin();
			if (pos > 0) {
				current = g;
			}
		}
		l[i] = current;
		update(i, current);
	}

	int current = 0;
	long long res = 0;
	for (int i = n + 1; i >= 2; --i) {
		if (i <= n) {
			for (int j = d[a[i]].size() - 1; j >= 0; --j) {
				int g = d[a[i]][j];
				if (g <= current) {
					break;
				}
				int pos = lower_bound(p[g].begin(), p[g].end(), i) - p[g].begin();
				if (pos + 1 < p[g].size()) {
					current = g;
				}

				if (pos != 0) {
					updateValues(p[g][0], g);
				}
			}
		}

		int index = upper_bound(l, l + i - 1, current) - l;
		--index;

		res += (long long)(index + 1) * (long long)(current);
		res += get(index + 1, i - 2);
	}

	cout << res << endl;

	//cerr << clock() << endl;


	return 0;
}