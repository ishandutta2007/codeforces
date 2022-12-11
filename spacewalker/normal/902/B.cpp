#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	vector<vector<int>> children(n, vector<int>());
	for (int i = 1; i < n; ++i) {
		int pi; cin >> pi; --pi;
		children[pi].push_back(i);
	}
	vector<int> colorToMatch(n, 0);
	for (int i = 0; i < n; ++i) {
		cin >> colorToMatch[i];
	}
	queue<pair<int, int>> q;
	q.emplace(0, 0); // first = i, second = c
	int recolors = 0;
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		int vcolor = colorToMatch[cur.first];
		if (cur.second != vcolor) {
			++recolors; 
		}
		for (int child : children[cur.first]) {
			q.emplace(child, vcolor);
		}
	}
	cout << recolors << endl;
	return 0;
}