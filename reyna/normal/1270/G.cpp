
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
int a[N];
int ml, mr, sl[N], sr[N];
pair<int, int> pl[N], pr[N];
int cmp(int x, int y) { return a[x] < a[y]; }
int solve() {
		
		for (int j = 0; j < ml; ++j) sl[j + 1] = (sl[j] + pl[j].first);
		for (int j = 0; j < mr; ++j) sr[j + 1] = (sr[j] + pr[j].first);
		int pt = 0, flag = 0;
		for (int j = 1; j < mr + 1; ++j) {
			while (pt < ml + 1 && sl[pt] < sr[j]) ++pt;
			if (pt != ml + 1 && sl[pt] == sr[j]) {
				cout << j + pt << '\n';
				for (int i = 0; i < j; ++i) cout << pr[i].second + 1 << ' ';
				for (int i = 0; i < pt; ++i) cout << pl[i].second + 1 << ' ';
				cout << '\n';
				return 1;
			}
		}
		return 0;
}
int32_t main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		ml = mr = 0;
		int pos0 = -1;
		for (int j = 0; j < n; ++j) {
			cin >> a[j];
		}
		if (n <= 10) {
			for (int mask = 1; mask < 1 << n; ++mask) {
				int sum = 0;
				for (int j = 0; j < n; ++j)
					if (mask >> j & 1)
						sum += a[j];
				if (sum == 0) {
					cout << (__builtin_popcount(mask)) << '\n';
					for (int j = 0; j < n; ++j)
						if (mask >> j & 1)
							cout << j + 1 << ' ';
					cout << '\n';
					break;
				}
			}
			continue;
		}
		for (int j = 0; j < n; ++j) {
			if (a[j] == 0) {
				pos0 = j;
			} else if (a[j] < 0) {
				pl[ml++] = mp(-a[j], j);
				a[j] = -a[j];
			} else {
				pr[mr++] = mp(a[j], j);
			}
		}
		if (pos0 >= 0) {
			cout << 1 << '\n' << pos0 + 1 << '\n';
			continue;
		}
		if (!solve()) {
			if (!solve()) {
				reverse(pr, pr + mr);
				if (!solve()) {
					reverse(pl, pl + ml);
					if (!solve()) {
						reverse(pr, pr + mr);
						if (!solve()) {
							
			sort(pl, pl + ml);
			sort(pr, pr + mr);
			if (!solve()) {
				reverse(pr, pr + mr);
				if (!solve()) {
					reverse(pl, pl + ml);
					if (!solve()) {
						reverse(pr, pr + mr);
						while (!solve()) {
							random_shuffle(pl, pl + ml);
							random_shuffle(pr, pr + mr);
						}
					}
				}
			}
						}
					}
				}
			}
		}
	}
}