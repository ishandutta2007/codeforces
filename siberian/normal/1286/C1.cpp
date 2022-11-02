#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

multiset<string> query(int l, int r) {
	cout << "? " << l << " " << r << endl;
	int x = (r - l + 1);
	x = x * (x + 1) / 2;
	multiset<string> ans;
	for (int j = 0; j < x; j++) {
		string i;
		cin >> i;
		sort(all(i));
		ans.insert(i);
	}
	return ans;
}

char Get(string a, string b) {
	multiset<char> have;
	//cout << "puhhh" << endl;
	for (auto i : b)
		have.insert(i);
	//cout << "pu" << endl;
	for (auto i : a)
		have.erase(have.find(i));
	//cout << "puhh" << endl;
	assert(have.size() == 1);
	return *have.begin();
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	if (n == 1) {
		cout << "? 1 1" << endl;
		string ans;
		cin >> ans;
		cout << "! " << ans << endl;
		return 0;
	}
	auto All = query(1, n);
	auto out = query(2, n);
	for (auto i : out)
		All.erase(All.find(i));
	//cout << "puhh" << endl;
	vector<string> fans;
	for (auto i : All)
		fans.push_back(i);
	assert(fans.size() == n);
	sort(all(fans), [&] (string a, string b) {return a.size() < b.size();});
	string ans = "";
	ans += fans[0];
	//cout << "fans = " << endl;
	//for (auto i : fans)
	//	cout << i << endl;
	for (int i = 0; i + 1 < n; i++) {
	//	cout << "i = " << i << endl;
		ans += Get(fans[i], fans[i + 1]);
	}
	cout << "! " << ans << endl;
	return 0;
}