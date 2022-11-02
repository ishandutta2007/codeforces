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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 150;
int r[maxN][maxN];
map < pair < int, int >, int > M;

void calc(int x, int y) {
	if (r[x][y] < 4) {
		return ;
	}
	int add = r[x][y] / 4;
	r[x][y] %= 4;
	r[x + 1][y] += add; calc(x + 1, y);
	r[x - 1][y] += add; calc(x - 1, y);
	r[x][y + 1] += add; calc(x, y + 1);
	r[x][y - 1] += add; calc(x, y - 1);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, t;
	cin >> n >> t;
	r[maxN / 2][maxN / 2] = n;
	calc(maxN / 2, maxN / 2);

	for (int i = 0; i < maxN; ++i) {
		for (int j = 0; j < maxN; ++j) {
			M[make_pair(i - maxN / 2, j - maxN / 2)] = r[i][j];
		}
	}

	for (int i = 0; i < t; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%d\n", M[make_pair(x, y)]);
	}

	return 0;
}