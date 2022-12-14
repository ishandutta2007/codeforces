
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
int a[N], cnt[N];
int main() {
	ios_base::sync_with_stdio(0);
	int tc;
	cin >> tc;
	while (tc--) {
		memset(cnt, 0, sizeof cnt);
		int n;
		cin >> n;
		vector<int> res;
		for (int j = 0; j < n; ++j) cin >> a[j], cnt[a[j]]++;
		while (true) {
			int mex = 0;
			while (cnt[mex]) ++mex;
			if (mex == n) {
				int pos = -1;
				for (int i = 0; i < n; ++i) if (a[i] != i) {
					pos = i;
					break;
				}
				if (pos == -1) break;
				cnt[a[pos]]--;
				a[pos] = mex;
				cnt[a[pos]]++;
				res.pb(pos);
				continue;
			}
			cnt[a[mex]]--;
			a[mex] = mex;
			cnt[a[mex]]++;
			res.pb(mex);
		}
		cout << (int) res.size() << '\n';
		for (int x : res) cout << x+1 << ' ';
		cout << '\n';
		
	}
}