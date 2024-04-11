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

int n;

vector < pair < pair < int, int >, int > > ops;

void rec(vector < int > a) {
	if (a.size() == 1) {
		if (a[0] == 24) {
			for (int i = 0; i < ops.size(); ++i) {
				int x = ops[i].first.first;
				int y = ops[i].first.second;
				int z = ops[i].second;
				if (x + y == z) {
					printf("%d + %d = %d\n", x, y, z);
				} else if (x - y == z) {
					printf("%d - %d = %d\n", x, y, z);
				} else {
					printf("%d * %d = %d\n", x, y, z);
				}
			}
			exit(0);
		}
		return ;
	}

	for (int i = 0; i < a.size(); ++i) {
		for (int j = i + 1; j < a.size(); ++j) {
			vector < int > b;
			for (int k = 0; k < a.size(); ++k) {
				if (k != i && k != j) {
					b.push_back(a[k]);
				}
			}
			b.push_back(a[i] + a[j]);
			ops.push_back(make_pair(make_pair(a[i], a[j]), a[i] + a[j]));
			rec(b);
			ops.pop_back();
			b.pop_back();

			b.push_back(a[i] - a[j]);
			ops.push_back(make_pair(make_pair(a[i], a[j]), a[i] - a[j]));
			rec(b);
			ops.pop_back();
			b.pop_back();

			b.push_back(a[i] * a[j]);
			ops.push_back(make_pair(make_pair(a[i], a[j]), a[i] * a[j]));
			rec(b);
			ops.pop_back();
			b.pop_back();

			b.push_back(a[j] - a[i]);
			ops.push_back(make_pair(make_pair(a[j], a[i]), a[j] - a[i]));
			rec(b);
			ops.pop_back();
			b.pop_back();
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	if (n < 4) {
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	while (n >= 8) {
		printf("%d + %d = %d\n", n - 3, n, 2 * n - 3);
		printf("%d + %d = %d\n", n - 2, n - 1, 2 * n - 3);
		printf("%d - %d = %d\n", 2 * n - 3, 2 * n - 3, 0);
		printf("1 + 0 = 1\n");
		n -= 4;
	}
	vector < int > res;
	for (int i = 1; i <= n; ++i) {
		res.push_back(i);
	}
	rec(res);

	return 0;
}