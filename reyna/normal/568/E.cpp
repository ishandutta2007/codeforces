// In the name of God

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

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; ++i)

const int N = (int) 1e5 + 5, mod = 0;

int a[N], b[N], sz, lis[N], plvl[N], mark[N];
vector<int> level[N];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	rep(i, n)
		cin >> a[i];
	int m;
	cin >> m;
	rep(i, m)
		cin >> b[i];
	sort(b, b + m);
	rep(i, n) {
		if (a[i] > 0) {
			int pos = lower_bound(lis, lis + sz, a[i]) - lis;
			lis[pos] = a[i];
			level[pos].push_back(i);
			plvl[i] = pos;
			sz = max(sz, pos + 1);
		} else {
			int p = sz;
			for (int i = m - 1; i >= 0; --i) {
				int x = b[i];
				while (p > 0 && lis[p - 1] >= x)
					p--;
				lis[p] = x;
				sz = max(sz, p + 1);
			}
		}
	}
	int curl = sz - 1, last = (int) 2e9;
	for (int i = n - 1; i >= 0; --i) if (curl >= 0) {
		if (a[i] > 0) {
			if (plvl[i] == curl) {
				curl--;
				last = a[i];
			}
		} else {
			int pos = lower_bound(level[curl].begin(), level[curl].end(), i) - level[curl].begin() - 1;
			if (pos < 0 || a[level[curl][pos]] >= last) {
				int p = lower_bound(b, b + m, last) - b - 1;
				mark[p] = 1;
				a[i] = b[p];
				last = a[i];
				curl--;
			}
		}
	}
	int pt = 0;
	rep(i, n) {
		if (a[i] < 0) {
			while (mark[pt])
				pt++;
			a[i] = b[pt++];
		}
		cout << a[i] << ' ';
	}
}