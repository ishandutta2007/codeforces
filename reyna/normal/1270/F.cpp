
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

const int N = (int) 2e5 + 5, sq = 430, mod = (int) 0;
int a[N], b[N], bg[N], ed[N];
int main() {
	memset(bg, -1, sizeof bg);
	memset(ed, -1, sizeof ed);
	string s;
	cin >> s;
	int n = (int) s.size();
	for (int j = 0; j < n; ++j)
		a[j + 1] = a[j] + (s[j] == '1');
	for (int j = 0; j <= n; ++j) ed[a[j]] = j;
	for (int j = n; j >= 0; --j) bg[a[j]] = j;
	long long res = 0;
	for (int sz = 1; sz <= sq; ++sz) {
		for (int j = 0; j < n; ++j) 
			b[j + 1] = b[j] + (a[j + 1] - a[j]) * sz - 1;
		sort(b, b + n + 1);
		int cnt = 0;
		for (int j = 0; j <= n; ++j) {
			if (j == 0 || b[j] != b[j - 1]) cnt = 0;
			res += cnt;
			++cnt;
		}
	}
	for (int sz = 1; sz <= n / sq + 3; ++sz) {
		for (int pos = 0; pos < n; ++pos) {
			int cur = a[pos];
			int want = cur + sz;
			if (bg[want] == -1) break;
			int l = max((bg[want] - pos + sz - 1) / sz * sz + pos, pos + sz * (sq + 1));
			int r = ed[want] + 1;
			if (r - l <= 0) continue;
			res += (r - l + sz - 1) / sz;
		}
	}
	cout << res << endl;
	
}