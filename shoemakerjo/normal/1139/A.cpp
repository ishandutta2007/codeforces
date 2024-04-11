#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	

	ll res = 0LL;
	int n;
	cin >> n;
	int cur;
	string s;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		cur = s[i-1]-'0';
		if (cur %2 == 0) {
			res += i+0LL;
		}
	}
	cout << res << endl;
}