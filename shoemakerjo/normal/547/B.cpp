#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int nums[n];
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	int anses[n+1];
	for (int i = 1; i <= n; i++) {
		anses[i] = 0;
	}
	stack<pii> cur;
	int previous[n+1];
	cur.push(pii(-1,-1));
	for (int i = 0; i < n; i++) {
		int temp = nums[i];
		while (cur.size() > 0 && cur.top().first >= temp) {
			cur.pop();
		}
		previous[i] = cur.top().second+1;
		cur.push(pii(temp, i));
	}
	while (cur.size() > 0) cur.pop();
	cur.push(pii(-1, n));
	int after[n+1];
	for (int i = n-1; i >= 0; i--) {
		int temp = nums[i];
		while (cur.top().first >= temp) {
			cur.pop();
		}
		after[i] = cur.top().second-1;
		cur.push(pii(temp, i));
	}
	for (int i = 0; i < n; i++) {
		int clen = after[i]-previous[i]+1;
		anses[clen] = max(anses[clen], nums[i]);
		// cout << i << " " << clen << endl;
	}
	for (int i = n-1; i >= 1; i--) {
		anses[i] = max(anses[i], anses[i+1]);
	}
	for (int i = 1; i <= n; i++) {
		if (i > 1) cout << " ";
		cout << anses[i];
	}
	cout << endl;
	// cin >> n;
}