
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

const int N = (int) 1005, mod = (int) 0;
int cnt[5], a[N];
string s[N];
int main() {
	int n, m;
	cin >> n >> m;
	for (int j = 0; j < n; ++j)
		cin >> s[j];
	for (int j = 0; j < m; ++j) cin >> a[j];
	int res = 0;
	for (int j = 0; j < m; ++j) {
		memset(cnt, 0, sizeof cnt);
		for (int i = 0; i < n; ++i)
			cnt[s[i][j] - 'A']++;
		int mx = 0;
		for (int i = 0; i < 5; ++i)
			mx = max(mx, cnt[i]);
		res += mx * a[j];
	}
	cout << res << endl;
}