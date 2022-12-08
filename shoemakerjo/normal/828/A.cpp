#include <iostream>

using namespace std;

int main() {
	int n, a, b;
	cin >> n >> a >> b;
	int  c = 0;
	int ans = 0;
	int cur;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		if (cur == 1) {
			if (a > 0) a--;
			else if (b > 0) {
				b--;
				c++;
			}
			else if (c > 0) c--;
			else {
				ans++;
			}
		}
		else {
			if (b > 0) {
				b--;
			}
			else ans+=2;
		}
	}
	cout << ans << endl;
	cin >> n;
}