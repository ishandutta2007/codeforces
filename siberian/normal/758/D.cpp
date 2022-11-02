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

int pow(int a, int n) {
	int ans = 1;
	for (int i = 0; i < n; i++)
		ans *= a;
	return ans;
}

int len(int x) {
	int ans = 0;
	while (x) {
		ans++;
		x /= 10;
	}
	return ans;
}

void solve() {
	vector<int> have;
	string s;
	int n;
	cin >> n >> s;
	//reverse(all(s));
	while (!s.empty()) {
		int now = 0;
		string del = "";
		int len = 0;
		while (!s.empty()) {
			if (pow(10, len) >= n) break;
			int nxt = pow(10, len) * (s.back() - '0');
			if (now + nxt >= n) break;
			now += nxt;
			len++;
			del += s.back();
			s.pop_back();
		} 
		while (del.size() > 1 && del.back() == '0') {
			s += del.back();
			del.pop_back();
		}
		//cout << s << " " << now << endl;
		have.push_back(now);
	}
	
	/*cout << "have = " << endl;
	for (auto i : have) {
		cout << i << " ";
	}
	cout << endl;*/
	int ans = 0;
	//reverse(all(have));
	int now = 1;
	for (auto i : have) {
		ans += i * now;
		now *= n;
	}
	cout << ans << endl;
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