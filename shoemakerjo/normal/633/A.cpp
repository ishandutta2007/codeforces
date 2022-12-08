#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b, c;
	cin >> a >> b >> c;
	bool poss[c+1];
	fill (poss, poss+c+1, false);
	poss[0] = true;
	for (int i = 1; i <= c; i++) {
		if (i - a >= 0) poss[i] = poss[i] || poss[i-a];
		if (i - b >= 0) poss[i] = poss[i] || poss[i-b];
	}
	string ans = poss[c] ? "Yes" : "No";
	cout << ans << endl;
	cin >> a;
}