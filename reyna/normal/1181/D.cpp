
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
int cnt[N], f[N], res[N];
pair<int, int> sr[N], s[N];

void update(int m, int x) { ++m;
	while (m < N) {
		f[m] += x;
		m += m & -m;
	}
}
int query(int m) { ++m;
	int res = 0;
	while (m > 0) {
		res += f[m];
		m -= m & -m;
	}
	return res;
}
int suf[N];
int32_t main() {
	ios_base::sync_with_stdio(0);
	int n, m, q;
	cin >> n >> m >> q;
	for (int j = 0; j < n; ++j) {
		int x;
		cin >> x;
		--x;
		cnt[x]++;
	}
	for (int j = 0; j < m; ++j) {
		s[j] = mp(cnt[j], j);	
	}
	sort(s, s + m);
	for (int j = 0; j < q; ++j) {
		int k;
		cin >> k;
		sr[j] = mp(k, j);
	}
	sort(sr, sr + q);
	for (int j = m - 1; j >= 0; --j) {
		suf[j] = suf[j + 1] + s[j].first;
	}
	int pt = 1;
	update(s[0].second, 1);
	for (int j = 0; j < q; ++j) {
		int k = sr[j].first, qid = sr[j].second;
		while (pt < m) {
			int help = suf[pt];
			int most = (k - help + pt - 1) / pt;
			if (most > s[pt].first) {
				update(s[pt].second, 1);
				++pt;	
			} else {
				break;
			}
		}
		int help = suf[pt];
		int ord = (k - help - 1) % pt;
		int bl = -1, br = m;
		while (bl < br - 1) {
			int bm = bl + br >> 1;	
			if (query(bm) >= ord + 1) {
				br = bm;	
			} else {
				bl = bm;
			}
		}
		res[qid] = br + 1;
	}
	for (int j = 0; j < q; ++j)
		cout << res[j] << '\n';
}