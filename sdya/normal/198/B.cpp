#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <cmath>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 210000;
int n, k;
int d[2][maxN];
char s[2][maxN];

bool valid(int x, int y) {
	if (y < 0) {
		return false;
	}
	if (y < n) {
		if (s[x][y] == 'X') {
			return false;
		}
		return true;
	} else {
		return true;
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d\n", &n, &k);
	gets(s[0]);
	gets(s[1]);
	queue < pair < int, int > > q;
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < maxN; ++j) {
			d[i][j] = -1;
		}
	}
	d[0][0] = 0;
	q.push(make_pair(0, 0));
	while (!q.empty()) {
		pair < int, int > p = q.front();
		q.pop();

		if (p.second >= n) {
			break;
		}

		if (d[p.first][p.second] >= p.second + 1) {
			continue;
		}

		int level = d[p.first][p.second];
		if (valid(p.first, p.second + 1) && level <= p.second + 1 && d[p.first][p.second + 1] == -1) {
			d[p.first][p.second + 1] = level + 1;
			q.push(make_pair(p.first, p.second + 1));
		}
		if (valid(p.first, p.second - 1) && level <= p.second - 1 && d[p.first][p.second - 1] == -1) {
			d[p.first][p.second - 1] = level + 1;
			q.push(make_pair(p.first, p.second - 1));
		}
		if (valid(1 - p.first, p.second + k) && level <= p.second + k && d[1 - p.first][p.second + k] == -1) {
			d[1 - p.first][p.second + k] = level + 1;
			q.push(make_pair(1 - p.first, p.second + k));
		}
	}

	for (int i = 0; i < 2; ++i) {
		for (int j = n; j < maxN; ++j) {
			if (d[i][j] != -1) {
				printf("YES\n");
				return 0;
			}
		}
	}

	printf("NO\n");
	
	return 0;
}