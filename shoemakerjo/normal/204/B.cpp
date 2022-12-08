#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> colors;
	int n;
	cin >> n;
	int needed = (n+1)/2;
	map<int, int> front;
	map<int, int> back;
	int f, b;
	for (int i = 0; i < n; i++) {
		cin >> f >> b;
		if (front.find(f) == front.end()) {
			front[f] = 1;
			back[f] = 0;
			colors.push_back(f);
		}
		else front[f]++;
		if (b == f) continue;
		if (back.find(b) == back.end()) {
			front[b] = 0;
			back[b] = 1;
			colors.push_back(b);
		}
		else back[b]++;
	}
	int ans = n+1;
	for (int i = 0; i < colors.size(); i++) {
		int cur = colors[i];
		int left = needed-front[cur];
		if (back[cur] >= left) {
			left = max(left, 0);
			ans = min(ans, left);
		}
	}
	if (ans == n+1) cout << -1 << endl;
	else cout << ans << endl;
	// cin >> n;
}