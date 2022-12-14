
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
int f[N];
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
int query(int l, int r) {
	return query(r - 1) - query(l - 1);
}
int gcd(int x, int y) {
	if (min(x, y) == 0) return max(x, y);
	return gcd(y, x % y);
}
pair<int, int> mline(int x, int y) {
	int g = gcd(abs(x), abs(y));
	x /= g;
	y /= g;
	return mp(x, y);
}
map<pair<int, int>, int> last;
int ql[N], qr[N], px[N], py[N], res[N];
vector<pair<int, int>> lines[N];
vector<int> queries[N];
int main() {
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int j = 0; j < n; ++j) {
		int k;
		cin >> k;
		for (int i = 0; i < k; ++i) {
			cin >> px[i] >> py[i];
		}
		for (int i = 0; i < k; ++i) {
			int nx = (i + 1) % k;
			lines[j].pb(mline(px[nx] - px[i], py[nx] - py[i]));
		}
	}
	int q;
	cin >> q;
	for (int j = 0; j < q; ++j) {
		cin >> ql[j] >> qr[j];
		--ql[j];
		queries[qr[j]].pb(j);
	}
	for (int r = 1; r <= n; ++r) {
		for (auto x : lines[r - 1]) {
			if (last.find(x) != last.end()) {
				update(last[x], -1);
			}
			last[x] = r - 1;
			update(r - 1, +1);
		}
		for (int j : queries[r]) {
			int l = ql[j];
			res[j] = query(l, r);
		}
	}
	for (int j = 0; j < q; ++j)
		cout << res[j] << '\n';
}