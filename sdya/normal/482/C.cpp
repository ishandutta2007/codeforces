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

const int maxN = 60;
const int maxL = 25;
char s[maxN][maxL];
vector < pair < int, double > > d[1 << 20];
//unordered_map < int, double > d[1 << 20];
//double d[1 << 20][50];
int n, m;


long long g[maxL][256];
vector < int > letters[maxL];

char b[1 << 20];
char fb[1 << 20];

const int B = (1 << 20) - 1;

double getValue(int mask, int v) {
	for (int i = 0; i < d[mask].size(); ++i) {
		if (d[mask][i].first == v) {
			return d[mask][i].second;
		}
	}
	return -1.0;
}

double setValue(int mask, int v, double value) {
	d[mask].push_back(make_pair(v, value));
	return value;
}

inline char __builtin_popcountll(long long x) {
	char res = 0;
	while (x) {
		res += b[x & B];
		x >>= 20LL;
	}
	return res;
}

inline char __builtin_ctzll(long long x) {
	char cnt = 0;
	while (x) {
		if (x & B) {
			return cnt + fb[x & B];
		}
		x >>= 20LL;
		cnt += 20;
	}
	return 0;
}

int states = 0;
int misses = 0;

double dp[maxN][maxN];
int cm[maxN][maxN];

double calc(int mask, int w) {
	//if (d[mask].count(w)) {
	//if (d[mask][w] > -1.0) {
	double dd = getValue(mask, w);
	if (dd > -0.5) {
		return dd;
		//return d[mask][w];
	}
	++states;

	long long words = (1LL << (long long)(n)) - 1LL;
	if (mask != 0) {
		int nmask = mask;
		while (nmask != 0) {
			int i = fb[nmask];
			words &= g[i][s[w][i]];
			nmask ^= (1 << i);
		}
	}

	int cnt = 0;
	double res = 0.0;

	char y = __builtin_popcountll(words);
	if (y == 2) {
		int u = __builtin_ctzll(words);
		words ^= (1LL << u);
		int v = __builtin_ctzll(words);

		return dp[cm[u][v] - b[mask]][m - cm[u][v]];
	}

	int nmask = (1 << m) - 1 - mask;
	for (int i = 0; i < m; ++i) {
		if (mask & (1 << i)) {
			continue;
		}
		++cnt;
		int nmask = mask | (1 << i);
		for (int j = 0; j < letters[i].size(); ++j) {
			long long nwords = words & g[i][letters[i][j]];
			if (nwords > 0) {
				char x = __builtin_popcountll(nwords);
				if (x > 1) {
					res += calc(nmask, __builtin_ctzll(nwords)) * x;
				}
			} else {
				++misses;
			}
		}
	}
	res /= (double)(cnt);
	res /= (double)(y);
	//return d[mask][w] = res + 1.0;
	return setValue(mask, w, res + 1.0);
}

void gen() {
	int n = 50;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 20; ++j) {
			printf("%c", rand() % 2 + 'a');
		}
		printf("\n");
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	dp[0][0] = 0.0;
	for (int i = 0; i < maxN; ++i) {
		for (int j = 0; j < maxN; ++j) {
			if (i + j == 0) {
				continue;
			}

			double res = 0.0;
			for (int k = 0; k < i; ++k) {
				res += dp[i - 1][j]; 
			}
			res /= (double)(i + j);
			dp[i][j] = 1.0 + res;
		}
	}

	//gen();
	//return 0;

	for (int i = 0; i < (1 << 20); ++i) {
		b[i] = 0;
		for (int j = 0; j < 20; ++j) {
			if (i & (1 << j)) {
				++b[i];
			}
		}
		for (int j = 0; j < 20; ++j) {
			if (i & (1 << j)) {
				fb[i] = j;
				break;
			}
		}
	}
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", &s[i]);
	}
	if (n == 1) {
		printf("%.10lf\n", 0.0);
		return 0;
	}
	m = strlen(s[0]);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < m; ++k) {
				cm[i][j] += (int)(s[i][k] == s[j][k]);
			}
		}
	}

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			g[i][s[j][i]] |= (1LL << (long long)(j));
		}

		for (int j = 0; j < 256; ++j) {
			if (g[i][j] != 0) {
				letters[i].push_back(j);
			}
		}
	}

	//memset(d, -1, sizeof(d));
	printf("%.10lf\n", (double)calc(0, 0));

	cerr << "States: " << states << endl;
	cerr << "Misses: " << misses << endl;

	cerr << clock() << endl;

	return 0;
}