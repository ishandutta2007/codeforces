#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

inline void solve() {
	string s;
	cin >> s;
	ll ans = 0, lst = 0, cnt = 0, lst_g = 0, n = s.size(), p_ans = 0;

	for (int i = 0; i < n; i++) {
		if (s[i] == '?') {
			ans += i - lst_g + 1;
			cnt++;
			continue;
		}

		if ((s[i] != s[lst]) ^ ((i - lst) & 1)) {
			if (s[i - 1] == '?') lst_g = i - cnt;
			else lst_g = i;
		}

		ans += i - lst_g + 1;
		lst = i;
		cnt = 0;

	}

	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}