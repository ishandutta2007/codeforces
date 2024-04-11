#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const int MAXN = 1e5 + 5;
ll fib[MAXN];
const ll MOD = 1e9 + 7;
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
 
	fib[0] = fib[1] = 1;
	for(int i = 2; i < MAXN; i++)
		fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
	string s;
	cin >> s;
	s += '*';
	int cnt = 1;
	ll ans = 1;
	for(int i = 1; i < s.size(); i++) {
		if(s[i - 1] == 'm' || s[i - 1] == 'w')
			ans = 0;
		if(s[i] == s[i - 1])
			cnt++;
		else {
			if(s[i - 1] == 'n' || s[i - 1] == 'u')
				ans = (ans * cnt[fib]) % MOD;
			cnt = 1;
		}
	}
	cout << ans << '\n';
}