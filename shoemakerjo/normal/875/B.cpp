#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	cout << 1;
	int cur;
	bool seen[n];
	for (int i = 0; i < n; i++) {
		seen[i] = false;
	}
	queue<int> q;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		seen[cur-1] = true;
		q.push(n-i-1);
		int ans = 0;
		while (!q.empty()) {
			int c = q.front();
			if (seen[c]) {
				q.pop();
				continue;
			}
			else {
				ans = (i+1)-(n-c-1);
				break;
			}
			
		}
		cout << " " << ans+1;
	}
	// cin >> n;
}