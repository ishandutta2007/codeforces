#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

pair<int, int> q(set<int> a) {
	cout << "? ";
	for (auto i : a)
		cout << i + 1 << " ";
	cout << endl;
	pair<int, int> ans;
	cin >> ans.second >> ans.first;
	return ans;
}

void out_ans(int x) {
	cout << "! " << x << endl;
	exit(0);
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin >> n >> k;
	set<int> have;
	for (int i = 0; i <= k; i++)
		have.insert(i);
	vector<pair<int, int>> ans;
	for (int i = 0; i <= k; i++) {
		have.erase(i);
		ans.push_back(q(have));
		have.insert(i);
	}
	sort(all(ans));
	for (int i = 1; i < ans.size(); i++)
		if (ans[i].first != ans[0].first)
			break;
		else
			k--;
	//ans.resize(unique(all(ans)) - ans.begin());
	out_ans(k);
	return 0;
}