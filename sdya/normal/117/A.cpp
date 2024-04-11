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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

int n, m;

int getTime(int timestamp, int current, int dir, int finish) {
	if (dir == 1) {
		if (current <= finish) {
			return timestamp + finish - current;
		} else {
			timestamp += m - current;
			dir = -1;
			current = m;
			return getTime(timestamp, current, dir, finish);
		}
	} else {
		if (current >= finish) {
			return timestamp + current - finish;
		} else {
			timestamp += current - 1;
			dir = 1;
			current = 1;
			return getTime(timestamp, current, dir, finish);
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		int s, f, t;
		scanf("%d%d%d", &s, &f, &t);

		int rem = t % (2 * m - 2);
		int current = 0;
		if (rem <= m - 1) {
			current = rem + 1;
		} else {
			current = 2 * m - 1 - rem;
		}

		int Ts = (rem < m - 1 ? getTime(t, current, 1, s) : getTime(t, current, -1, s));

		rem = Ts % (2 * m - 2);
		int Tf = (rem < m - 1 ? getTime(Ts, s, 1, f) : getTime(Ts, s, -1, f));
		printf("%d\n", (s == f ? t : Tf));
	}

	return 0;
}