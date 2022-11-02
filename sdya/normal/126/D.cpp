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
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110;
int n;
long long f[maxN], d[maxN], a[maxN], b[maxN];

long long solve(long long n) {
	for (int i = 86; i >= 1; i --)
		if (n >= f[i]) d[i] = 1, n -= f[i]; else d[i] = 0;

	a[0] = 1, b[0] = 0;
	int l = 0, len = 0;
	for (int i = 1; i <= 86; i ++) {
		len ++;
		if (d[i]) {
			a[i] = a[l] + b[l];
			b[i] = a[l] * (long long)((len - 1) / 2) + b[l] * (long long)(len / 2); 
			len = 0, l = i;
		}
	}
	return a[l] + b[l];
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	f[1] = 1, f[2] = 2;
	for (int i = 3; i <= 86; i ++)
		f[i] = f[i - 1] + f[i - 2];
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		long long x;
		cin >> x;
		cout << solve(x) << endl;
	}

	return 0;
}