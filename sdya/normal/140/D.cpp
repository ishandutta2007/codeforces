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

using namespace std;

const int maxN = 110;
const int maxT = 1000;
const int T = 360;
int n, a[maxN];

pair < int, int > d[maxN][maxT];

pair < int, int > operator + (pair < int, int > A, pair < int, int > B) {
	return make_pair(A.first + B.first, A.second + B.second);
}

int dist(int A, int B) {
	if (A <= B) return 0;
	return A - B;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= 720; ++j)
			d[i][j] = make_pair(-1000000, 1000000);

	for (int j = 10; j <= 720; ++j)
		d[0][j] = make_pair(0, 0);
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= 720; ++j) {
			d[i][j] = d[i - 1][j];
			if (j > 0) {
				d[i][j] = max(d[i][j], d[i][j - 1]);
			}

			if (j >= a[i]) {
				d[i][j] = max(d[i][j], d[i - 1][j - a[i]] + make_pair(1, - dist(j, T)));
			}
		}
	}
	printf("%d %d\n", d[n][720].first, - d[n][720].second);
	return 0;
}