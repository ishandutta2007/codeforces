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
		s = "." + s + ".";
		bool flag = false;
		for (int i = 1; i < int(s.size()) - 1; i++)
			if (s[i] != s[i - 1] && s[i] != s[i + 1])
				flag = true;

		cout << (flag ? "NO" : "YES") << endl;
	}
	return 0;
}