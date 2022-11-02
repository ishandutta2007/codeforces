#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

const int MAXN = 510;
int n;
int a[MAXN];

void read() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
}

int num[MAXN][MAXN];

int calc(int l, int r) {
	vector<int> st;
	for (int i = l; i <= r; i++) {
		st.push_back(a[i]);
		while (st.size() >= 2) {
			int x = st.back();
			st.pop_back();
			int y = st.back();
			st.pop_back();
			if (x != y){
				st.push_back(y);
				st.push_back(x);
				break;
			}
			st.push_back(x + 1);
		}
	}
	if (st.size() == 1) return st.back();
	return -1;
}

void precalc() {
	for (int l = 1; l <= n; l++) {
		for (int r = l; r <= n; r++) {
			num[l][r] = calc(l, r);
		}
	}
}

int dp[MAXN];

void calc_dp() {
	dp[0] = 0;
	for (int i = 1; i <= n; i++) dp[i] = n;

	for (int r = 1; r <= n; r++) {
		for (int l = 1; l <= r; l++) {
			if (num[l][r] != -1) {
				chkmin(dp[r], dp[l - 1] + 1);
			}
		}
	}
}

int ans;

void make_ans() {
	ans = dp[n];
}

void run() {
	precalc();
	calc_dp();
	make_ans();
}

void write() {
	cout << ans << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read();
	run();
	write();
	return 0;
}