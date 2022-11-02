#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll Mod = (ll)1e9 + 7;

ll qpow(ll a, ll b) {
	ll tmp = a, ret = 1;
	for(; b > 0; b >>= 1) {
		if(b & 1)
			ret = ret * tmp % Mod;
		tmp = tmp * tmp % Mod;
	}
	return ret;
}

int cnt[128];

int main() {
	ios :: sync_with_stdio(false);
	int n; cin >> n;
	string s; cin >> s;
	for(char c : s)
		cnt[c] ++;
	int m = *max_element(cnt, cnt + 128);
	int base = 0;
	for(int i = 0; i < 128; i ++)
		if(cnt[i] == m) base ++;
	cout << qpow(base, n) << '\n';
	return 0;
}