#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	string s;
	cin >> s;
	int bal = 0, ans = 0, pv = -1;
	for(int i = 0; i < n; i++) {
		char c = s[i];
		if(c == ')') {
			bal--;
			if(bal < 0 && pv == -1)
				pv = i;
		}
		if(c == '(') {
			bal++;
			if(bal == 0 && pv != -1) {
				ans += i - pv + 1;
				pv = -1;
			}
		}
	}
	if(bal != 0)
		cout << "-1\n";
	else
		cout << ans << '\n';
}