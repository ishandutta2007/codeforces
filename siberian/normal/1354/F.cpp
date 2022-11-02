#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

struct fa{
	int a, b, ind;
	fa() {}
};

int n, k;
const int MAXN = 76;
fa a[MAXN];
const int INF = 1e9;
int dp[MAXN][MAXN][2];
int par[MAXN][MAXN][2];

void relax(int pref, int cnt, int ind, int val, int fpar) {
	if (dp[pref][cnt][ind] >= val) return;
	dp[pref][cnt][ind] = val;
	par[pref][cnt][ind] = fpar;
}

void solve() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i].a >> a[i].b;
		a[i].ind = i + 1;
	}
	sort(a, a + n, [&] (fa i, fa j) {return i.b < j.b;});
	if (k == 1) {
		int pos = max_element(a, a + n, [&] (fa i, fa j) {return i.a < j.a;}) - a;
		cout << 1 << "\n" << a[pos].ind << "\n";
		return;
	}
	if (k == n) {
		cout << n << "\n";
		for (int i = 0; i < n; i++) {
			cout << a[i].ind << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < MAXN; i++) {
		for (int j = 0; j < MAXN; j++) {
			for (int k = 0; k < 2; k++) {
				dp[i][j][k] = -INF;
			}
		}
	}

	dp[0][0][0] = 0;
	for (int i = 0; i < n; i++) {
		for (int cnt = 0; cnt <= k - 1; cnt++) {
			for (int flag = 0; flag < 2; flag++) {
				if (dp[i][cnt][flag] == -INF) continue;
				if (cnt < k - 1) relax(i + 1, cnt + 1, flag, dp[i][cnt][flag] + a[i].a + a[i].b * cnt, 1);
				relax(i + 1, cnt, flag, dp[i][cnt][flag] + a[i].b * (k - 1), 2);
				if (!flag) {
					relax(i + 1, cnt, 1, dp[i][cnt][flag] + a[i].a + a[i].b * (k - 1), 3);
				}
			}
		}
	}

	int pos = 0, cnt = 0, flag = 0;
	for (int i = 0; i < MAXN; i++) {
		if (dp[i][k - 1][1] > dp[pos][cnt][flag]) {
			pos = i, cnt = k - 1, flag = 1;
		}
	}

	vector<pair<int, int>> ans;
	for (; pos >= 1; pos--) {
		ans.push_back({par[pos][cnt][flag], pos});
		int ncnt = cnt;
		if (par[pos][cnt][flag] == 1) ncnt--;
		int nflag = flag;
		if (par[pos][cnt][flag] == 3) nflag--;
		cnt = ncnt;
		flag = nflag;
	}
	sort(all(ans));

	vector<int> fout;
	for (auto i : ans) {
		fout.push_back(i.second);
		if (i.first == 2) {
			fout.push_back(-i.second);
		} 
	}
	cout << fout.size() << "\n";
	for (auto i : fout) {
		cout << a[abs(i) - 1].ind * i / abs(i) << " ";
	}
	cout << "\n";
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}