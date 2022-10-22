#include<bits/stdc++.h>
using std::cin;
using std::cout;
int t, n;
char s[1000];
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> t;
	for(int i = 0;i < t;++i) {
		cin >> n;
		cin >> s;
		int ans = 0;
		for(int j = 0;j < n;++j) {
			if(s[j] > '0')
			ans += s[j] - '0' + 1;
		}
		ans -= s[n - 1] != '0';
		cout << ans << '\n';
	}
}