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
		int d = 0;
		bool flag = (s.back() == 'B');

		for (char c : s) {
			d += (c == 'A' ? 1 : -1);
			flag &= (d >= 0);
		}

		cout << (flag ? "YES" : "NO") << endl;
	}
	return 0;
}