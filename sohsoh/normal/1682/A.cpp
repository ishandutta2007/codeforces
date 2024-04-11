#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;

		int ans = 0, p1 = n / 2 - 1, p2 = n / 2;	
		char c = s[p2];
		if (n & 1) {
			ans++;
			p2++;
		}

		while (p1 >= 0 && p2 < n && s[p1] == c && s[p2] == c) ans += 2, p1--, p2++;
		cout << ans << endl;
	}
	return 0;
}