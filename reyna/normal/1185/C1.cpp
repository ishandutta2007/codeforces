
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

const int N = (int) 1e6 + 6, mod = (int) 0;
int cnt[105];
int main() {
	ios_base::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	for (int j = 0; j < n; ++j) {
		int t;
		cin >> t;
		int t_have = m - t, fail = 0;
		for (int s = 1; s <= 100; ++s) {
			int use = min(t_have / s, cnt[s]);
			t_have -= use * s;
			fail += cnt[s] - use;
		}
		cout << fail << ' ';
		cnt[t]++;
	}
}