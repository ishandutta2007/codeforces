
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
const int N = (int) 2e5 + 5, mod = (int) 0;
int a[N], t[N], o[N];
int cmp(int x, int y) { return a[x] < a[y]; }
int32_t main() {
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int j = 0; j < n; ++j) {
		cin >> a[j];
		o[j] = j;
	}
	for (int j = 0; j < n; ++j) cin >> t[j];
	sort(o, o + n, cmp);
	set<pair<int, int>, greater<pair<int, int>>> st;
	o[n] = n;
	int cnt = 0, cur_num = -1e9, res = 0, sum = 0;
	for (int _ = 0; _ < n + 1; ++_) {
		int cur = o[_];
		if (_ == n) a[cur] = 2e9;
		while ((int) st.size() && cur_num < a[cur]) {
			auto s = *(st.begin());
			res += sum - s.first;
			sum -= s.first;
			st.erase(s);
			--cnt;
			cur_num++;
		}
		if (_ == n) break;
		cur_num = a[cur];
		++cnt;
		st.insert(mp(t[cur], cur));
		sum += t[cur];
	}
	cout << res << '\n';
}