#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()
#define fadd fadd228
template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

#define int ll

int k;
vector<string> s;

bool check(int len) {
	int have = 1;
	int now = 0;
	//cout << len << endl;
	int cnt = 0;
	for (auto i : s) {
		cnt++;
		bool last = cnt == s.size(); 
		//cout << have << " " << now << " " << i << endl;
		if (now == 0) {
			if (i.size() + (!last) <= len) {
				now = i.size() + (!last);
			}
			else {
				return false;
			}
			continue;
		}
		if (now + i.size() + (!last) <= len) {
			now += + i.size() + (!last);
			continue;
		}

		if (i.size() + (!last) > len) return false;
		have++;
		now = i.size() + (!last);
	}
	//cout << have << endl;
	return have <= k;
}

void solve() {
	cin >> k;
	string x;
	while (cin >> x) {
		//s.push_back(x);
		string now = "";
		for (auto i : x) {
			if (i == '-') {
				s.push_back(now);
				now = "";
				continue;
			}
			now += i;
		}
		s.push_back(now);
	}
	//check(19);
	//return;
	int l = 0, r = 1e9;
	while (l < r - 1) {
		int mid = (l + r) / 2;
		if (check(mid)) {
			r = mid;
		}
		else {
			l = mid;
		}
	}
	cout << r << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}