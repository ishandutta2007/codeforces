#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;

#define all(a) (a).begin(), (a).end()

template<typename T1, typename T2>
inline void chkmin(T1& x, const T2& y) {
	if (y < x) {
		x = y;
	}
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
	if (x < y) {
		x = y;
	}
}

vector<int> getLower(const vector<int>& a) {
	vector<int> ans(a.size(), -1);
	vector<int> st;
	for (int i = 0; i < (int)a.size(); ++i) {
		while (!st.empty() && a[st.back()] > a[i]) st.pop_back();
		if (!st.empty()) {
			ans[i] = st.back();
		}
		st.push_back(i);
	}
	return ans;
}

vector<int> getUpper(const vector<int>& a) {
	vector<int> ans(a.size(), -1);
	vector<int> st;
	for (int i = 0; i < (int)a.size(); ++i) {
		while (!st.empty() && a[st.back()] < a[i]) st.pop_back();
		if (!st.empty()) {
			ans[i] = st.back();
		}
		st.push_back(i);
	}
	return ans;	
}

void vout(vector<int> a) {
	for (auto i : a) cerr << i << " ";
	cerr << endl;
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto& i : a) {
		cin >> i;
	}
	ll ans = 0;
	auto lowerL = getLower(a);
	auto upperL = getUpper(a);
	reverse(all(a));
	auto lowerR = getLower(a);
	reverse(all(lowerR));
	for (auto& i : lowerR) i = n - 1 - i;
	auto upperR = getUpper(a);
	reverse(all(upperR));
	for (auto& i : upperR) i = n - 1 - i;


	vector<int> minR(n, n - 1);
	for (int i = 0; i < n; ++i) {
		if (lowerL[i] != -1 && upperR[i] != n) {
			chkmin(minR[lowerL[i]], upperR[i] - 1);
		}
		if (upperL[i] != -1 && lowerR[i] != n) {
			chkmin(minR[upperL[i]], lowerR[i] - 1);
		}
	}
	for (int i = n - 2; i >= 0; --i) {
		chkmin(minR[i], minR[i + 1]);
	}

	for (int i = 0; i < n; ++i) {
		ans += minR[i] - i + 1;
	}

	cout << ans << '\n';
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.precision(20), cout.setf(ios::fixed);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}