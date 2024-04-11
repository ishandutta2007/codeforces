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

const long long P = 1000000007LL;
const int maxN = 2100;
int n, a[maxN];

long long c[maxN][maxN];
long long p[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		if (a[i] == i) {
			printf("0\n");
			return 0;
		}
	}
	p[0] = 1;
	p[1] = 0;
	for (int i = 2; i < maxN; ++i) {
		p[i] = (long long)(i - 1) * (p[i - 1] + p[i - 2]);
		p[i] %= P;
	}
	for (int i = 0; i < maxN; ++i) {
		c[i][0] = 1;
		for (int j = 1; j <= i; ++j) {
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % P;
		}
	}

	int x = 0, y = 0;
	for (int i = 1; i <= n; ++i) {
		bool isStart = true;
		for (int j = 1; j <= n; ++j) {
			if (a[j] == i) {
				isStart = false;
			}
		}
		if (!isStart) {
			continue;
		}
		int len = 0;
		int j = i;
		while (j != -1) {
			++len;
			j = a[j];
		}
		if (len == 1) {
			++y;
		} else {
			++x;
		}
	}

	long long res = 0;
	for (int i = 0; i <= x; ++i) {
		long long A = c[x][i];
		long long B = p[x + y - i];
		res = (res + A * B) % P;
	}
	cout << res << endl;


	return 0;
}