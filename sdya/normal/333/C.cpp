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
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int shift = 10500;
int k, m;
set < int > S;

vector < int > v[11000];
vector < int > invV[21000];
int a[4];

vector < int > gen(int l, int r) {
	int value = 0;
	for (int i = l; i <= r; ++i) {
		value = value * 10 + a[i];
	}
	if (l == r) {
		return vector < int > (1, a[l]);
	}

	vector < int > res;
	for (int i = l; i < r; ++i) {
		vector < int > a = gen(l, i);
		vector < int > b = gen(i + 1, r);
		vector < int > c;
		for (int j = 0; j < a.size(); ++j) {
			for (int k = 0; k < b.size(); ++k) {
				c.push_back(a[j] + b[k]);
				c.push_back(a[j] - b[k]);
				c.push_back(a[j] * b[k]);
			}
		}
		sort(c.begin(), c.end());
		c.resize(unique(c.begin(), c.end()) - c.begin());
		for (int j = 0; j < c.size(); ++j) {
			res.push_back(c[j]);
		}
	}
	res.push_back(value);
	sort(res.begin(), res.end());
	res.resize(unique(res.begin(), res.end()) - res.begin());
	return res;
}

void precalc() {
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			for (int k = 0; k < 10; ++k) {
				for (int l = 0; l < 10; ++l) {
					a[0] = i;
					a[1] = j;
					a[2] = k;
					a[3] = l;
					v[i * 1000 + j * 100 + k * 10 + l] = gen(0, 3);
				}
			}
		}
	}
	for (int i = 0; i < 10000; ++i) {
		for (int j = 0; j < v[i].size(); ++j) {
			if (v[i][j] + shift >= 0 && v[i][j] + shift < 21000) {
				invV[v[i][j] + shift].push_back(i);
			}
		}
	}

	for (int i = 0; i < 21000 && S.size() < m; ++i) {
		for (int j = 0; j < invV[i].size() && S.size() < m; ++j) {
			vector < int > needed;
			needed.push_back(k - (i - shift) + shift);
			needed.push_back((i - shift) - k + shift);
			if ((i - shift) != 0 && k % (i - shift) == 0) {
				needed.push_back(k / (i - shift) + shift);
			}
			sort(needed.begin(), needed.end());
			needed.resize(unique(needed.begin(), needed.end()) - needed.begin());
			for (int x = 0; x < needed.size(); ++x) {
				if (needed[x] >= 0 && needed[x] < 21000) {
					for (int a = 0; a < invV[needed[x]].size() && S.size() < m; ++a) {
						S.insert(invV[i][j] * 10000 + invV[needed[x]][a]);
					}
				}
			}
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &k, &m);
	precalc();
	if (k == 0) {
		for (int i = 0; i < m; ++i) {
			printf("%08d\n", i);
		}
		return 0;
	}

	while (!S.empty()) {
		printf("%08d\n", *S.begin());
		S.erase(S.begin());
	}

	return 0;
}