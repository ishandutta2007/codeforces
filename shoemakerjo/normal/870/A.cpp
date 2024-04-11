#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int flow = 11, slow = 11;
	int samelow = 11;
	int cur;
	set<int> first;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		first.insert(cur);
		flow = min(flow, cur);
	}
	for (int i = 0; i < m; i++) {
		cin >> cur;
		if (first.find(cur) != first.end()) {
			samelow = min(samelow, cur);
		}
		slow = min(slow, cur);
	}
	if (samelow != 11) {
		cout << samelow << endl;
	}
	else {
		cout << 10*(min(slow, flow)) + max(slow, flow) << endl;
	}
	// cin >> n;
}