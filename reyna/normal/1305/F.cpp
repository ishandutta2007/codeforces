
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
#define int long long
const int N = (int) 1e6 + 6, mod = (int) 0;
map<int, int> vis;
int seen[N], a[N], n;
int get_m(int p) {
	if (vis.find(p) != vis.end()) return vis[p];
	int res = 0;
	for (int j = 0; j < n; ++j) {
		if (a[j] - p < 0) {
			res += p - a[j] % p;
		} else 
			res += min(a[j] % p, (p - a[j]%p)%p);
	}
	return vis[p] = res;
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	srand(time(0));
	cin >> n;
	for (int j = 0; j < n; ++j) {
		a[j] = rand();
		cin >> a[j];
	}
	int res = n;
	int L = 50;
	for (int turn = 0; turn < L; ++turn) {
		int pos = rand() % n;
		if (seen[pos]++) continue;
		for (int j = max(1LL, a[pos] - 2); j < a[pos] + 3; ++j) {
			int cur = j;
			for (int i = 2; i * i <= cur; ++i) {
				if (cur % i == 0) res = min(res, get_m(i));
				while (cur % i == 0) cur /= i;
			}
			if (cur != 1) res = min(res, get_m(cur));
		}
	}
	cout << res << endl;
}