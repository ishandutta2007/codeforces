
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
int mark[N];
int main() {
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	if (n <= 3) {
		cout << 0 << endl;
		return 0;
	}
	int best = n, bestk = 2;
	for (int k = 2; k <= n; ++k) {
		int cur = 0, cnt = 0;
		while (cur + k < n) {
			++cnt;
			cur += k;
		}
		int op = cnt + k - 1;
		if (best >= op) {
			best = op;
			bestk = k;
		}
	}
	int k = bestk, s = 0;
	while (s < 5500) {
		int cnt = 0;
		for (int j = 0; j < n; ++j)	cnt += mark[j];
		vector<int> all;
		for (int j = 0; j < n; ++j)
			if (j % k != 0 && !mark[j] && all.size() < k) {
				all.push_back(j);
				mark[j] = 1;
			}
		if (all.size() != k) {
			cout << 0 << endl;
			return 0;
		}
		cout << all.size() << ' ';
		for (int x : all) {
			cout << x + 1 << ' ';
		}
		cout << endl;
		int x;
		cin >> x;
		--x;
		for (int j = x; j < x + k; ++j)
			mark[j % n] = 0;
		++s;
	}
	cout << 0 << endl;
	return 0;
}