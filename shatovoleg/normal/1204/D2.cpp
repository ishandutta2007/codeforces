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
 
void run() {
	string s;
	cin >> s;
	int n = len(s);
	vector<int> dp(2, 0);
	vector<int> diff;
	for (auto &x : s) {
		++dp[x - '0'];
		cmax(dp[1], dp[0]);
		diff.pb(dp[1] - dp[0]);
	}
	for (int i = n - 2; i > -1; --i) {
		cmin(diff[i], diff[i + 1]);
	}
	int cur = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '1' && diff[i] - cur > 0) {
			s[i] = '0';
			++cur;
		}
	}
	cout << s << endl;
}