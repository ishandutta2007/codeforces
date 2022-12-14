
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>

using namespace std;

#define mp make_pair
#define x first
#define y second
#define pb push_back
#define ALL(x) (x).begin(), (x).end()

typedef long long LL;

const int N = (int) 1e3 + 3, mod = (int) 0;
int res[N], b[N], qt[N], ql[N], qr[N];
int main() {
	int n, m;
	cin >> n >> m;
	for (int j = 0; j < m; ++j) {
		cin >> qt[j] >> ql[j] >> qr[j];
		--ql[j];
		if (qt[j] == 1) for (int i = ql[j]; i < qr[j] - 1; ++i)
			b[i] = 1;
	}
	for (int j = 0; j < m; ++j) {
		int flag = 0;
		if (qt[j] == 0) {
			for (int i = ql[j]; i < qr[j] - 1; ++i)
				if (b[i] == 0)
					flag = 1;
			if (!flag) {
				cout << "NO\n";
				return 0;
			}
		}
	}
	cout << "YES\n";
	int cur = n + 1;
	for (int j = 0; j < n; ++j) {
		res[j] = cur;
		cur -= b[j] ^ 1;
	}
	for (int j = 0; j < n; ++j)
		cout << res[j] << ' ';
}