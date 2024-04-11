#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

int query1(int x, int y, int z) {
	cout << "1 " << x + 1 << " " << y + 1 << " " << z + 1 << endl;
	int ans;
	cin >> ans;
	return ans;
}

int query2(int x, int y, int z) {
	cout << "2 " << x + 1 << " " << y + 1 << " " << z + 1 << endl;
	int ans;
	cin >> ans;
	return ans;
}

void out_ans(vector<int> a) {
	cout << "0 ";
	for (auto i : a)
		cout << i + 1 << " ";
	cout << endl;
	exit(0);
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;

	vector<pair<int, int> > a, b;
	for (int i = 2; i < n; i++) {
		int s = query1(0, 1, i);
		int z = query2(0, 1, i);
		if (z < 0) {
			a.push_back({s, i});
		}
		else {
			b.push_back({s, i});
		}
	}
	sort(all(a));

	vector<int> fans;

	vector<int> now;
	for (auto i : a) {
		if (now.empty()) {
			now.push_back(i.second);
			continue;
		}
		int z = query2(0, now.back(), i.second);
		if (z < 0) {
			fans.push_back(now.back());
			now.pop_back();
		}	
		now.push_back(i.second);
	}

	reverse(all(fans));
	vector<int> ans;
	ans.push_back(0);
	for (auto i : now)
		ans.push_back(i);
	for (auto i : fans)
		ans.push_back(i);

	ans.push_back(1);

	sort(all(b));

	now.clear();
	fans.clear();

	for (auto i : b) {
		if (now.empty()) {
			now.push_back(i.second);
			continue;
		}
		int z = query2(1, now.back(), i.second);
		if (z < 0) {
			fans.push_back(now.back());
			now.pop_back();
		}
		now.push_back(i.second);
	}
	
	reverse(all(fans));
	for (auto i : now)
		ans.push_back(i);
	for (auto i : fans)
		ans.push_back(i);

	out_ans(ans);
	return 0;
}