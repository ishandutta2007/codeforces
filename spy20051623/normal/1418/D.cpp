#include <bits/stdc++.h>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, q;
	cin >> n >> q;
	set<int> a;
	multiset<int, greater<int>> s;
	for (int i = 0; i < n; ++i) {
		int p;
		cin >> p;
		a.insert(p);
		auto it = a.find(p);
		if (it != a.begin()) {
			auto it1 = it;
			--it1;
			s.insert(p - *it1);
		}
		if (it != --a.end()) {
			auto it1 = it;
			++it1;
			s.insert(*it1 - p);
		}
		if (it != a.begin() && it != --a.end()) {
			auto it1 = it, it2 = it;
			--it1, ++it2;
			s.erase(s.find(*it2 - *it1));
		}
	}
	cout << *--a.end() - *a.begin() - *s.begin() << '\n';
	while (q--) {
		int k, p;
		cin >> k >> p;
		if (k) {
			a.insert(p);
			auto it = a.find(p);
			if (it != a.begin()) {
				auto it1 = it;
				--it1;
				s.insert(p - *it1);
			}
			if (it != --a.end()) {
				auto it1 = it;
				++it1;
				s.insert(*it1 - p);
			}
			if (it != a.begin() && it != --a.end()) {
				auto it1 = it, it2 = it;
				--it1, ++it2;
				s.erase(s.find(*it2 - *it1));
			}
		} else {
			auto it = a.find(p);
			if (it != a.begin() && it != --a.end()) {
				auto it1 = it, it2 = it;
				--it1, ++it2;
				s.insert(*it2 - *it1);
			}
			if (it != a.begin()) {
				auto it1 = it;
				--it1;
				s.erase(s.find(p - *it1));
			}
			if (it != --a.end()) {
				auto it1 = it;
				++it1;
				s.erase(s.find(*it1 - p));
			}
			a.erase(p);
		}
		cout << (s.empty() ? 0 : *--a.end() - *a.begin() - *s.begin()) << '\n';
	}
	return 0;
}