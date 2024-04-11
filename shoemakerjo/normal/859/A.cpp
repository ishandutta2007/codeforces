#include <bits/stdc++.h>

using namespace std;

int main() {
	int cmax = 0;
	int K;
	cin >> K;
	int cur;
	for (int i = 0; i < K; i++) {
		cin >> cur;
		cmax = max(cmax, cur);
	}
	int ans = max(0, cmax - 25);
	cout << ans << endl;
	cin >> ans;
}