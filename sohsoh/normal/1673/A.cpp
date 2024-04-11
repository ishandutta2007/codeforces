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
		string s;
		cin >> s;
		int ans = 0;
		for (char c : s)
			ans += int(c - 'a' + 1);
	
		if (int(s.size()) & 1) {
			if (s.size() == 1) cout << "Bob " << ans << endl;
			else cout << "Alice " << ans - 2 * int(min(s.front(), s.back()) - 'a' + 1) << endl; 
		} else cout << "Alice " << ans << endl;
	}
	return 0;
}