#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int h1, a1, c1;
	int h2, a2;
	int ans = 0;
	cin >> h1 >> a1 >> c1 >> h2 >> a2;
	vector<string> stuff;
	while (h2 > 0) {
		ans++;
		if (h2 <= a1) {
			h2 = 0;
			stuff.push_back("STRIKE");
		} 
		else if (h1 <= a2) {
			h1-=a2;
			h1 += c1;
			stuff.push_back("HEAL");
		}
		else {
			h1 -= a2;
			h2 -= a1;
			stuff.push_back("STRIKE");
		}
	}
	cout << ans << endl;
	for (int i = 0; i < ans; i++) {
		cout << stuff[i] << endl;
	}
	cin >> ans;
}