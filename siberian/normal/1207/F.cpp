#include <bits/stdc++.h>

using namespace std;
//#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

const int MAXSQ = sqrt(5e5 + 10);
const int MAXN = 5e5 + 10;
int fans[MAXSQ][MAXSQ];
int a[MAXN];
int sq;


void add(int x, int y) {
	a[x] += y;
	for (int i = 1; i < sq; i++)
		fans[i][x % i] += y;
}

int get_ans(int x, int y) {
	if (x < sq)
		return fans[x][y];
	int ans = 0;
	for (int i = y; i < MAXN; i += x)
		ans += a[i];
	return ans;
}

void solve() {
	int n;
	cin >> n;
	sq = 288;
	chkmax(sq, 1);
	for (int test = 0; test < n; test++) {
		int t, x, y;
		cin >> t >> x >> y;
		if (t == 1)
			add(x, y);
		else
			cout << get_ans(x, y) << "\n";
	}
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}