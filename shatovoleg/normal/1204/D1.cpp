#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
#define int ll
#define pb push_back
#define kek pop_back
#define mp make_pair
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
#define len(v) ((int)(v).size())
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
const int INF = 1e18 + 666;
 
template<class t1, class t2>
bool cmin(t1 &a, const t2 &b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
 
template<class t1, class t2>
bool cmax(t1 &a, const t2 &b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
 
void run();
 
signed main() {
	iostream::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	run();
}

vector<int> calc_fixed_begin(const string &s, int b) {
	vector<int> ans;
	vector<int> dp(2, 0);
	for (int i = b; i < len(s); ++i) {
		++dp[s[i] - '0'];
		cmax(dp[1], dp[0]);
		ans.pb(dp[1]);
	}
	return ans;
}

vector<vector<int>> calc_lens(const string &s) {
	vector<vector<int>> ans;
	for (int i = 0; i < len(s); ++i) {
		ans.pb(calc_fixed_begin(s, i));
	}
	return ans;
}

string to_str(int a, int n) {
	string s;
	for (int i = 0; i < n; ++i) {
		s += '0' + (a & 1);
		a >>= 1;
	}
	return s;
}

int count_0(const string &s) {
	int cnt = 0;
	for (auto &x : s) {
		if (x == '0') {
			++cnt;
		}
	}
	return cnt;
}

void run() {
	string s;
	cin >> s;
	vector<int> l = calc_fixed_begin(s, 0);
	for (auto &x : s) {
		if (x == '1') {
			x = '0';
			if (calc_fixed_begin(s, 0) != l) {
				x = '1';
			}
		}
	}
	cout << s << endl;
	// int cnt = 0;
	// for (int i = 0; i < len(s); ++i) {
	// 	cnt += s[i] - '0';
	// }
	// int n = len(s);
	// int ans = 0;
	// vector<string> a;
	// auto l = calc_lens(s);
	// for (int i = 0; i < (1 << n); ++i) {
	// 	string t = to_str(i, n);
	// 	int c = count_0(t);
	// 	if (c > ans && calc_lens(t) == l) {
	// 		ans = c;
	// 		a.clear();
	// 	}
	// 	if (c == ans) {
	// 		a.pb(t);
	// 	}
	// }
	// for (auto &x : a) {
	// 	cout << x << endl;
	// }
}