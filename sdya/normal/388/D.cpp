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

const long long P = 1000000007LL;
const int maxN = 50;
long long d[maxN][maxN][2], c[maxN][maxN];
int digits[maxN], m;

void add(long long &d, long long value) {
	d += value;
	d %= P;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i = 0; i < maxN; ++i) {
		c[i][0] = 1;
		for (int j = 1; j <= i; ++j) {
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % P;
		}
	}
	int n;
	cin >> n;
	m = 0;
	while (n) {
		digits[m++] = n % 2;
		n /= 2;
	}
	reverse(digits, digits + m);
	d[0][0][1] = 1;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < maxN; ++j) {
			if (d[i][j][0] != 0) {
				add(d[i + 1][j][0], d[i][j][0] * (long long)(1 << (long long)(j)));
				add(d[i + 1][j + 1][0], d[i][j][0]);
			}
			if (d[i][j][1] != 0) {
				if (digits[i] == 0) {
					for (int a = 0; a <= j; a += 2) {
						add(d[i + 1][j][1], d[i][j][1] * c[j][a]);
					}
				} else {
					for (int a = 0; a <= j; ++a) {
						if (a % 2 == 0) {
							add(d[i + 1][j][0], d[i][j][1] * c[j][a]);
						} else {
							add(d[i + 1][j][1], d[i][j][1] * c[j][a]);
						}
					}
					add(d[i + 1][j + 1][1], d[i][j][1]);
				}
			}
		}
	}
	long long res = 0;
	for (int i = 0; i < maxN; ++i) {
		res += d[m][i][0] + d[m][i][1];
		res %= P;
	}
	cout << res << endl;

	return 0;
}