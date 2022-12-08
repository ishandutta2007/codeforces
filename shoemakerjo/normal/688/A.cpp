#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n, d;
	cin >> n >> d;
	string bad = "";
	for (int i = 0; i < n; i++) bad+='1';
	string cur;
	int ans = 0;
	int run = 0;
	for (int i = 0; i < d; i++) {
		cin >> cur;
		if (cur==bad) {
			run = 0;
		}
		else {
			run++;
			ans = max(ans, run);
		}
	}
	cout << ans << endl;
	// cin >> n;
}