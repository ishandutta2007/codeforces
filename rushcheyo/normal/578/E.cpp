#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	string s;
	cin >> s;
	int n = (int)s.size();
	vector<vector<int>> LL, LR, RL, RR;
	for (int i = 0; i < n; ++i)
		if (s[i] == 'L') {
			if (!LR.empty()) LL.push_back({}), swap(LL.back(), LR.back()), LL.back().push_back(i), LR.pop_back();
			else if (!RR.empty()) RL.push_back({}), swap(RL.back(), RR.back()), RL.back().push_back(i), RR.pop_back();
			else LL.push_back({i});
		} else {
			if (!RL.empty()) RR.push_back({}), swap(RR.back(), RL.back()), RR.back().push_back(i), RL.pop_back();
			else if (!LL.empty()) LR.push_back({}), swap(LR.back(), LL.back()), LR.back().push_back(i), LL.pop_back();
			else RR.push_back({i});
		}
	cout << LL.size() + LR.size() + RL.size() + RR.size() - 1 << endl;
	vector<int> big_LR, big_RL, big_LL, big_RR, ans;
	if (LL.size() >= RR.size()) {
		vector<int> v;
		for (int i = 0; i < (int)LL.size(); ++i) {
			for (int x : LL[i]) v.push_back(x);
			if (i < (int)RR.size())
				for (int x : RR[i]) v.push_back(x);
		}
		if (LL.size() == RR.size() + 1) big_LL = v;
		else LR.push_back(v);
	} else {
		vector<int> v;
		for (int i = 0; i < (int)RR.size(); ++i) {
			for (int x : RR[i]) v.push_back(x);
			if (i < (int)LL.size())
				for (int x : LL[i]) v.push_back(x);
		}
		big_RR = v;
	}
	for (const auto &v : LR)
		for (int x : v) big_LR.push_back(x);
	for (const auto &v : RL)
		for (int x : v) big_RL.push_back(x);
	if (!big_LR.empty() && !big_RL.empty()) {
		if (big_RL.back() > big_LR.back()) {
			big_LR.push_back(big_RL.back());
			big_RL.pop_back();
			for (int x : big_RL) big_LR.push_back(x);
			big_RL.clear();
		} else {
			big_RL.push_back(big_LR.back());
			big_LR.pop_back();
			for (int x : big_LR) big_RL.push_back(x);
			big_LR.clear();
		}
	}
	if (!big_LR.empty()) {
		for (int x : big_LL) big_LR.push_back(x);
		ans = big_RR;
		for (int x : big_LR) ans.push_back(x);
	} else {
		for (int x : big_RR) big_RL.push_back(x);
		ans = big_LL;
		for (int x : big_RL) ans.push_back(x);
	}
	for (int x : ans) cout << x + 1 << ' ';
	cout << endl;
}