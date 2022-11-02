#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cstring>
#include <string>
#include <queue>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 5;

int a[maxN][maxN];
int n;
pair < int, int > order[] = {
	make_pair(0, 0),
	make_pair(0, 1),
	make_pair(0, 2),
	make_pair(0, 3),
	make_pair(1, 0),
	make_pair(2, 0),
	make_pair(3, 0),
	make_pair(2, 1),
	make_pair(1, 2),
	make_pair(1, 1),
	make_pair(3, 1),
	make_pair(1, 3),
	make_pair(2, 2),
	make_pair(3, 2),
	make_pair(3, 3),
	make_pair(2, 3)
};

void rec(int have) {
	if (have == n * n) return ;
}

int b[maxN * maxN];

void solve_trivial() {
	sort(b, b + (n * n));
	do {
		for (int i = 0; i < n * n; ++i)
			a[i / n][i % n] = b[i];
		set < int > S;
		for (int i = 0; i < n; ++i) {
			int sum = 0;
			for (int j = 0; j < n; ++j)
				sum += a[i][j];
			S.insert(sum);
			sum = 0;
			for (int j = 0; j < n; ++j)
				sum += a[j][i];
			S.insert(sum);
		}
		int s1 = 0, s2 = 0;
		for (int i = 0; i < n; ++i)
			s1 += a[i][i], s2 += a[i][n - 1 - i];
		S.insert(s1);
		S.insert(s2);
		if (S.size() == 1) {
			printf("%d\n", * S.begin());
			for (int i = 0; i < n; ++i, printf("\n"))
				for (int j = 0; j < n; ++j)
					printf("%d ", a[i][j]);
			return ;
		}
	} while (next_permutation(b, b + n * n));
}

void solve_clever() {
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n * n; ++i)
		scanf("%d", &b[i]);

	if (n <= 3) {
		solve_trivial();
	} else {
		solve_clever();
	}

	return 0;
}