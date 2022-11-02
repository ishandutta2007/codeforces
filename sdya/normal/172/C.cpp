#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <set>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110000;
int n, m;
int t[maxN], x[maxN];
int res[maxN];

set < pair < int, int > > S;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%d%d", &t[i], &x[i]);

	int current = 1, current_time = 0;
	while (current <= n) {
		while (S.size() < m && current <= n) {
			S.insert(make_pair(x[current], current));
			current_time = max(current_time, t[current]);
			++current;
		}

		int old_point = 0;
		while (!S.empty()) {
			int x = S.begin()->first;
			current_time += x - old_point;
			int k = 0;
			while (!S.empty()) {
				if (S.begin()->first == x) {
					res[S.begin()->second] = current_time;
					++k;
					S.erase(S.begin());
				} else {
					break;
				}
			}
			current_time += 1 + k / 2;
			old_point = x;
		}
		current_time += old_point;
	}

	for (int i = 1; i <= n; ++i)
		printf("%d ", res[i]);
	printf("\n");

	return 0;
}