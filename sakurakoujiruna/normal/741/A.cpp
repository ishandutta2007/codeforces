#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 101;

int p[N];
int in[N];

ll lcm(ll a, ll b) {
	return a / __gcd(a, b) * b;
}

int main() {
	ios :: sync_with_stdio(false);
	int n; cin >> n;
	for(int i = 1; i <= n; i ++) {
		cin >> p[i];
		in[p[i]] ++;
	}
	bool f = true;
	for(int i = 1; i <= n; i ++)
		f &= (in[i] == 1);
	if(!f)
		cout << -1 << '\n';
	else {
		ll ans = 1;
		for(int i = 1; i <= n; i ++) {
			int s = 1;
			for(int j = p[i]; j != i; j = p[j])
				s ++;
			if(s % 2 == 0) s /= 2;
			ans = lcm(ans, s);
		}
		cout << ans << '\n';
	}
	return 0;
}