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

const int maxN = 110000;
const int maxD = 110;
int n;
int a[maxN];
int l[maxN], r[maxN], m;
int t[60][maxN];
int rm[60][maxN];
int id[maxN];
bool dv[60][7];

char s[3];

void calcSeg(int index) {
	int L = l[index];
	int R = r[index];
	for (int i = 0; i < 60; ++i) {
		int value = 0, rem = i;
		int pos = L;
		while (pos != R) {
			if (dv[rem][a[pos]]) {
				++value;
				++rem;
				if (rem == 60) { rem = 0; }
			} else {
				++value;
				++rem;
				if (rem == 60) { rem = 0; }
				++pos;
			}
		}
		t[i][index] = value;
		rm[i][index] = rem;
	}
}

void precalc() {
	for (int i = 0; i < 60; ++i) {
		for (int j = 1; j <= 6; ++j) {
			dv[i][j] = (i % j == 0);
		}
	}
	int start = 1;
	while (start < n + 1) {
		l[m] = start;
		r[m] = start + maxD;
		if (r[m] >= n + 1) {
			r[m] = n + 1;
		}
		for (int i = l[m]; i < r[m]; ++i) {
			id[i] = m;
		}
		calcSeg(m);
		start = r[m];
		++m;
	}
	id[n + 1] = m;
}

int getValue(int x, int y) {
	int p = id[x];
	int q = id[y];

	int value = 0;
	int rem = 0;
	int pos = x;
	while (pos != y && id[pos] == p) {
		if (dv[rem][a[pos]]) {
			++value;
			++rem;
			if (rem == 60) { rem = 0; }
		} else {
			++value;
			++rem;
			if (rem == 60) { rem = 0; }
			++pos;
		}
	}

	if (pos == y) {
		return value;
	}

	while (id[pos] != q) {
		value += t[rem][id[pos]];
		rem = rm[rem][id[pos]];
		pos = r[id[pos]];
	}

	while (pos != y) {
		if (dv[rem][a[pos]]) {
			++value;
			++rem;
			if (rem == 60) { rem = 0; }
		} else {
			++value;
			++rem;
			if (rem == 60) { rem = 0; }
			++pos;
		}
	}
	return value;
}

void gen() {
	int n = 100000;
	printf("%d\n", n);
	for (int i = 0; i < n; ++i) {
		printf("%d ", (rand() % 5) + 2);
	}
	printf("\n");
	int q = 100000;
	printf("%d\n", q);
	for (int i = 0; i < q; ++i) {
		if (rand() % 10 == 0) {
			int x = 1;
			int y = n + 1;
			printf("A %d %d\n", x, y);
		} else {
			int x = (rand() * rand() + rand()) % n + 1;
			x = ((x % n) + n) % n;
			int y = (rand() % 5) + 2;
			printf("C %d %d\n", x, y);
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	//gen();

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}

	precalc();

	int q;
	scanf("%d", &q);
	for (int i = 1; i <= q; ++i) {
		scanf("%s", &s);
		if (s[0] == 'A') {
			int x, y;
			scanf("%d%d", &x, &y);
			printf("%d\n", getValue(x, y));
		} else {
			int x, y;
			scanf("%d%d", &x, &y);
			if (y != a[x]) {
				a[x] = y;
				calcSeg(id[x]);
			}
		}
	}

	//cerr << clock() << endl;

	
	return 0;
}