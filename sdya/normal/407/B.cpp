#define _CRT_SECURE_NO_WARNINGS
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

const int maxN = 1100;
int n, p[maxN];
int s[maxN];

const long long P = 1000000007LL;
long long d[maxN][2];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> p[i];
	}

	d[1][1] = 0;
	d[1][0] = 1;
	for (int i = 2; i <= n; ++i) {
		d[i][1] = (d[i - 1][1] + d[i - 1][0] + 1) % P;
		d[i][0] = 1;
		int j = p[i];
		if (j < i) {
			d[i][0] = (d[i][0] + d[j][0]) % P;
			for (int k = j + 1; k < i; ++k) {
				d[i][0] = (d[i][0] + 1) % P;
				d[i][0] = (d[i][0] + d[k][0]) % P;
			}
			d[i][0] = (d[i][0] + 1) % P;
		}
	}
	cout << (d[n][1] + d[n][0] + 1) % P << endl;

	/*int res = 0;
	int v = 1;
	while (v != (n + 1)) {
		++s[v];
		if (s[v] % 2 == 1) {
			v = p[v];
		} else {
			v = v + 1;
		}
		++res;
	}

	cout << res << endl;*/


	return 0;
}