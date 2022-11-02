#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <set>
#include <map>
#include <queue>
#include <stack>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 2100000;
int a[maxN], b[maxN];
int n, m;
int p[maxN], q[maxN];
int d[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d", &n, &m);
	memset(p, -1, sizeof(p));
	memset(q, -1, sizeof(q));
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]), p[a[i]] = i;
	for (int i = n; i < n + n; ++i)
		a[i] = a[i - n];

	for (int i = 0; i < m; ++i)
		scanf("%d", &b[i]), q[b[i]] = i;

	int res = 0;
	int index = -1;
	for (int i = 0; i < n; ++i) {
		if (q[a[i]] == -1) continue;
		if (index < i) {
			index = i;
		}

		int shift = q[a[i]];
		int last_position = q[a[index]];
		last_position -= shift;
		if (last_position < 0) last_position += m;

		for (int i = index + 1; i < i + n; ++i) {
			int cur_position = q[a[i]];
			if (cur_position == -1) break;
			cur_position -= shift;
			if (cur_position < 0) cur_position += m;
			if (cur_position > last_position) {
				index = i;
				last_position = cur_position;
			} else {
				break;
			}
		}
		res = max(res, index - i + 1);
	}

	printf("%d\n", res);

	return 0;
}