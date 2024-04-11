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
#include <complex>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 2100;
const long long P = 1000000007LL;
long long c[maxN][maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	for (int i = 0; i < maxN; ++i) {
		c[i][0] = 1;
		for (int j = 1; j <= i; ++j) {
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % P;
		}
	}

	long long res = 1;
	int n;
	scanf("%d", &n);

	long long total = 0;
	for (int i = 0; i < n; ++i) {
		int m;
		scanf("%d", &m);
		res = (res * c[total + m - 1][total]) % P;
		total += m;
	}

	cout << res << endl;

	return 0;
}