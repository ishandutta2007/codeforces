#include <bits/stdc++.h>
using namespace std;

using db = double;
using ll = long long;
using vi = vector <int>;
#define op operator
#define pb push_back

const ll mod = 1e9L + 7;

int main() {
	cout << fixed << setprecision(9);
	ios :: sync_with_stdio(0);

	string s; cin >> s;
	ll ans = 0, tmp = 0;
	reverse(s.begin(), s.end());
	for(char c : s)
		if(c == 'b')
			tmp ++;
		else {
			ans += tmp;
			ans %= mod;
			tmp = (tmp + tmp) % mod;
		}
	cout << ans << '\n';

	return 0;
}