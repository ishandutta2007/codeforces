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

const int maxN = 2100;
const int maxM = 11000;
int a[maxN], n;
int p[maxM];
long long q[maxM];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a, a + n);

	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			++p[a[j] - a[i]];
		}
	}

	for (int i = 0; i <= 5000; ++i) {
		for (int j = 0; i + j <= 5000; ++j) {
			q[i + j] += (long long)(p[i]) * (long long)(p[j]);
		}
	}
	long long res = 0;
	for (int i = 0; i <= 5000; ++i) {
		for (int j = 0; j < i; ++j) {
			res += (long long)(p[i]) * q[j];
		}
	}
	double d = (n * (n - 1)) / 2;
	double ans = res;
	ans /= d;
	ans /= d;
	ans /= d;
	printf("%.10lf\n", ans);

	return 0;
}