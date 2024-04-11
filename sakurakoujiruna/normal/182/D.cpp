#include <bits/stdc++.h>
using namespace std;

const int N = 100011;
int p[N];
int solve(string s) {
	int n = s.size();
	s = '\0' + s;
	int t = -1; p[0] = -1;
	for(int i = 1; i <= n; i ++) {
		while(t >= 0 && s[i] != s[t + 1]) t = p[t];
		p[i] = ++ t;
	}
	return (n % (n - p[n]) ? n : n - p[n]);
}

int main() {
	ios :: sync_with_stdio(false);
	string s, t; cin >> s >> t;
	int a = solve(s), b = solve(t);
	int n = s.size(), m = t.size();
	if(s.substr(0, a) != t.substr(0, b))
		cout << "0\n";
	else {
		int ans = 0;
		for(int i = a; i <= n; i += a)
			if(n % i == 0 && m % i == 0)
				ans ++;
		cout << ans << '\n';
	}
	return 0;
}