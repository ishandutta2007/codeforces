#include <bits/stdc++.h>
using namespace std;

int main() {
	int d; scanf("%d", &d);
	vector<int> itemIDs;
	vector<tuple<int, int, int>> qs;
	for (int i = 0; i < d; ++i) {
		int qt; scanf("%d", &qt);
		if (qt == 1) {
			int f; scanf("%d", &f);
			qs.emplace_back(1, f, -1);
			itemIDs.emplace_back(f);
		} else {
			int s, d; scanf("%d %d", &s, &d);
			qs.emplace_back(2, s, d);
			itemIDs.emplace_back(s);
			itemIDs.emplace_back(d);
		}
	}
	reverse(begin(qs), end(qs));
	map<int, int> endValue;
	auto getEndValue = [&] (int i) {
		return (endValue.find(i) == endValue.end() ? i : endValue[i]);
	};
	vector<int> ans;
	for (auto [qtype, f1, f2] : qs) {
		if (qtype == 1) ans.push_back(getEndValue(f1));
		else endValue[f1] = getEndValue(f2);
	}
	reverse(begin(ans), end(ans));
	for (int v : ans) printf("%d\n", v);
}