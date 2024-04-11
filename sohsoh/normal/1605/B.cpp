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
		string s;
		cin >> n >> s;
		if (is_sorted(all(s))) cout << 0 << endl;
		else {
			cout << 1 << endl;
			int cnt = count(all(s), '0');
			vector<int> ans;
			for (int i = 0; i < n; i++)
				if ((i < cnt) ^ (s[i] == '0'))
					ans.push_back(i);
			cout << ans.size() << sep;
			for (int e : ans) cout << e + 1 << sep;
			cout << endl;
		}
	}
	return 0;
}