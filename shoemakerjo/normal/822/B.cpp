#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	int n, m;
	string s, t;
	cin >> n >> m >> s >> t;
	vector<int> sol;
	int ans = 10000;
	for (int i = 0; i <= m-n; i++) {
		int diff = 0;
		vector<int> cur;
		for (int j = 0; j < n; j++) {
			if (s[j]!=t[i+j]) {
				diff++;
				cur.push_back(j+1);
			}
		}
		if (diff < ans) {
			ans = diff;
			sol = cur;
		}
	}
	cout << ans << endl;
	for (int i = 0; i < ans; i++) {
		if (i > 0) cout << " ";
		cout << sol[i];
	}
	cout << endl;
	// cin >> n;
}