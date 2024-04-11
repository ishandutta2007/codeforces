
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
map<pair<int, int>, int> milestone;
int cnt[N], cur_res;
int32_t main() {
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int j = 0; j < n; ++j) cin >> cnt[j], cur_res += cnt[j];
	int q;
	cin >> q;
	while (q--) {
		int s, t, u;
		cin >> s >> t >> u;
		--s, --u;
		if (u >= -1) {
			int &x = milestone[mp(s, t)];
			if (x > 0) {
				int y = x - 1;
				cur_res -= max(0LL, cnt[y]);
				cnt[y]++;
				cur_res += max(0LL, cnt[y]);
				x = 0;
			}
			if (x > 0) {
				x = 0;
			} else {
				x = u + 1;
			}
			if (x > 0) {
				int y = x - 1;
				cur_res -= max(0LL, cnt[y]);
				cnt[y]--;
				cur_res += max(0LL, cnt[y]);
			}
		}
		cout << max(1LL, cur_res) << '\n';
	}
}