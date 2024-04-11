#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s; cin >> s;
	int n = s.size();
	vector<int> preds(n, -1);
	queue<int> zeroLast;
	queue<int> oneLast;
	bool earlyTerminate = false;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '0') {
			// are there any ones to pair to?
			if (!oneLast.empty()) {
				int toPair = oneLast.front(); oneLast.pop();
				preds[i] = toPair;
			}
			zeroLast.push(i);
		} else {
			if (!zeroLast.empty()) {
				int toPair = zeroLast.front(); zeroLast.pop();
				preds[i] = toPair;
				oneLast.push(i);
			} else {
				earlyTerminate = true;
				break;
			}
		}
	}
	if (earlyTerminate || !oneLast.empty()) {
		cout << -1 << endl;
		return 0;
	}
	cout << zeroLast.size() << endl;
	vector<bool> visited(n, false);
	for (int toCheck = n - 1; toCheck >= 0; --toCheck) {
		if (!visited[toCheck]) {
			vector<int> comp;
			for (int toVisit = toCheck; toVisit != -1; toVisit = preds[toVisit]) {
				if (toVisit != -1) {
					comp.push_back(toVisit);
					visited[toVisit] = true;
				}
			}
			reverse(comp.begin(), comp.end());
			cout << comp.size();
			for (int i : comp) {
				cout << " " << i + 1;
			}
			cout << endl;
		}
	}
	return 0;
}