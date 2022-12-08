#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b;
	cin >> a >> b;
	int ans = 1000000000;
	for (int i = 1; i <= 1000; i++) {
		int cur = 0;
		int val = abs(i-a);
		cur += (val*(val+1))/2;
		val = abs(i-b);
		cur += (val*(val+1))/2;
		ans = min(ans, cur);
	}
	cout << ans << endl;
	cin >> ans;

}