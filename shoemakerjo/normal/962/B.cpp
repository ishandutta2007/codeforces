#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, a, b;
	cin >> n >> a >> b;
	string s;
	cin >> s;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '*') continue;
		if (i > 0 && s[i-1] == 'A')  {
			if (b > 0) {
				ans++;
				b--;
				s[i] = 'B';
			}
		}
		else if (i > 0 && s[i-1] == 'B') {
			if (a > 0) {
				ans++;
				a--;
				s[i] = 'A';
			}
		}
		else { //we get to pick
			if (a > b) {
				s[i] = 'A';
				a--;
				ans++;
			}
			else if (b > 0) {
				s[i] = 'B';
				b--;
				ans++;
			}
		}
	}
	cout << ans << endl;
	cin >> a;

}