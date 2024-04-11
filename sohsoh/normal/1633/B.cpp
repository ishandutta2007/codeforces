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
		int c[2] = {count(all(s), '0'), count(all(s), '1')};
		if (c[0] != c[1]) cout << min(c[0], c[1]) << endl;
		else {
			int ans = 0;
			c[s.back() - '0']--;
			ans = max(ans, min(c[0], c[1]));	
			c[s.back() - '0']++;
			c[s.front() - '0']--;	
			ans = max(ans, min(c[0], c[1]));	
			cout << ans << endl;
		}
	}
	return 0;
}