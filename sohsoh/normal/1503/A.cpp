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

bool is_ok(string s) {
	int bal = 0;
	for (char c : s) {
		if (c == '(') bal++;
		else bal--;
		if (bal < 0) return false;
	}

	return bal == 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		string ans1, ans2, s;
		cin >> n >> s;
		int t = count(all(s), '1');
		t /= 2;
		bool b = false;

		for (char c : s) {
			if (c == '1') {
				if (t > 0) {
					t--;
					ans1.push_back('(');
					ans2.push_back('(');
				} else {
					ans1.push_back(')');
					ans2.push_back(')');
				}
			} else {
				b = !b;
				if (b) {
					ans1.push_back('(');
					ans2.push_back(')');
				} else {
					ans1.push_back(')');
					ans2.push_back('(');
				}
			}
		}

		if (is_ok(ans1) && is_ok(ans2)) {
			cout << "YES" << endl;
			cout << ans1 << endl << ans2 << endl;
		} else cout << "NO" << endl;
	}
	return 0;
}