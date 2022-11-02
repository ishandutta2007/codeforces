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

/*int d[2][70][70][70];

int calc(int move, int odd, int even, int rem) {
	if (d[move][odd][even][rem] != -1) {
		return d[move][odd][even][rem];
	}
	if (odd + even == rem) {
		return d[move][odd][even][rem] = (odd % 2 == 1 ? 1 : 2);
	}

	if (odd > 0 && calc(1 - move, odd - 1, even, rem) == 1 + move) {
		return d[move][odd][even][rem] = 1 + move;
	}
	if (even > 0 && calc(1 - move, odd, even - 1, rem) == 1 + move) {
		return d[move][odd][even][rem] = 1 + move;
	}
	return d[move][odd][even][rem] = 1 + (1 - move);
}*/

int trivial(int move, int odd, int even, int rem) {
	if (odd + even == rem) {
		return odd % 2 == 1 ? 1 : 2;
	}
	if (odd == 0) {
		return trivial(1 - move, odd, even - 1, rem);
	}
	if (even == 0) {
		return trivial(1 - move, odd - 1, even, rem);
	}
	int moves = (odd + even - rem);
	if (move == 0) {
		if (moves == 1) {
			return 1;
		}
		return trivial(1 - move, odd, even - 1, rem);
	} else {
		if (moves == 1) {
			return 2;
		}
		return trivial(1 - move, odd - 1, even, rem);
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	/*memset(d, -1, sizeof(d));
	for (int k = 1; k <= 50; ++k) {
		for (int odd = 0; odd <= 50; ++odd) {
			for (int even = 0; even <= 50; ++even) {
				if (odd + even >= k) {
					if (calc(0, odd, even, k) != trivial(0, odd, even, k)) {
						printf("%d %d %d: %d, %d\n", k, odd, even, calc(0, odd, even, k), trivial(0, odd, even, k));
					}
				}
			}
		}
	}*/

	int n, k;
	scanf("%d%d", &n, &k);
	int odd = 0, even = 0;
	for (int i = 1; i <= n; ++i) {
		int v;
		scanf("%d", &v);
		if (v % 2 == 0) {
			++even;
		} else {
			++odd;
		}
	}

	int res = trivial(0, odd, even, k);
	if (res == 1) {
		cout << "Stannis" << endl;
	} else {
		cout << "Daenerys" << endl;
	}


	return 0;
}