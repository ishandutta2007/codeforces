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

const int maxN = 110;
const int inf = 1000000000;

int gcd(int a, int b) {
	if (a == 0 || b == 0) {
		return a + b;
	}
	if (a > b) {
		return gcd(a % b, b);
	}
	return gcd(b % a, a);
}

int g[maxN][maxN];
int n, a[maxN], b[maxN], best;
int c[maxN];
int order[maxN];

vector < int > candidates;

bool comp(int x, int y) {
	return a[x] > a[y];
}

int res = 0;

vector < int > numbers;

void solve() {
	if (numbers.size() > n) {
		return;
	}

	vector < int > b = numbers;
	reverse(b.begin(), b.end());
	while (b.size() < n) {
		b.push_back(1);
	}

	int current = 0;
	for (int i = 0; i < n; ++i) {
		current += abs(b[i] - a[order[i]]);
	}
	if (current < best) {
		best = current;
		for (int i = 0; i < n; ++i) {
			c[order[i]] = b[i];
		}
	}
}

long long gg[maxN];

void rec(int lv, long long mask) {
	++res;
	solve();
	if (mask == 0) {
		return;
	}

	for (long long i = lv + 1; i < 60; ++i) {
		if (mask & (1LL << i)) {
			numbers.push_back(i);
			rec(i, mask & gg[i]);
			numbers.pop_back();
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	for (int i = 1; i < maxN; ++i) {
		for (int j = 1; j < maxN; ++j) {
			g[i][j] = gcd(i, j);
			if (g[i][j] == 1 && j > i) {
				gg[i] |= (1LL << (long long)(j));
			}
		}
	}

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		order[i] = i;
	}
	sort(order, order + n, comp);
	best = 0;
	for (int i = 0; i < n; ++i) {
		best += abs(a[i] - 1);
		c[i] = 1;
	}

	rec(0, (1LL << 58LL) - 4LL);
	cerr << "Ways: " << res << endl;

	/*rec(0, 0);*/

	//cerr << best << endl;
	for (int i = 0; i < n; ++i) {
		printf("%d ", c[i]);
	}
	cout << endl;

	cerr << clock() << endl;


	return 0;
}