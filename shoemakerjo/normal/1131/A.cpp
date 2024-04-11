#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int w1, h1, w2, h2;
	cin >> w1 >> h1 >> w2 >> h2;

	int ans = 0;
	ans += h1 + h2 + h1 + h2;
	ans += w1 + w2;
	ans += 4;
	ans += w1-w2;

	cout << ans << endl;
}