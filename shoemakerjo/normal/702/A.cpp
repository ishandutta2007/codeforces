#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	int ans = 0;
	int prev = -1;
	int cs = 0;
	int cur;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		if (cur > prev) {
			cs++;
			ans = max(ans, cs);
		}
		else {
			cs = 1;
		}
		prev = cur;
	}
	cout << ans << endl;
	// cin >> n;
	
}