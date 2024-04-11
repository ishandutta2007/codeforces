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

const int maxN = 100;
long long d[maxN];

void solve(long long n, long long m, long long shift) {
	if (n == 0) {
		cout << endl;
		return;
	}
	if (n == 1) {
		cout << shift + 1 << endl;
		return ;
	}
	long long u = d[n - 1];
	if (u >= m) {
		cout << shift + 1 << " ";
		solve(n - 1, m, shift + 1);
		return;
	}

	cout << shift + 2 << " " << shift + 1 << " ";
	solve(n - 2, m - u, shift + 2);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	d[0] = 1;
	for (int i = 1; i < maxN; ++i) {
		d[i] = d[i - 1];
		if (i >= 2) {
			d[i] += d[i - 2];
		}
	}

	long long n, m;
	cin >> n >> m;
	solve(n, m, 0);

	return 0;
}