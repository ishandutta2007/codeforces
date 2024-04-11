#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int cur;
	vector<int> g; //grade increase
	int numneed = (9*n + 1)/2;
	for (int i = 0; i  < n; i++) {
		cin >> cur;
		numneed -= cur;
		g.push_back(5-cur);
	}
	sort(g.begin(), g.end());
	reverse(g.begin(), g.end());
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (numneed > 0) {
			numneed -= g[i];
			ans++;
		}
	}
	cout << ans << endl;
	cin >> n;

}