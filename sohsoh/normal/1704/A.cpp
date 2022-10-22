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
		int cnt[2] = {0, 0}, n, m;
		cin >> n >> m;
		string a, b;

		cin >> a >> b;
		reverse(all(a));
		reverse(all(b));

		while (a.size() > b.size()) {
			cnt[a.back() - '0']++;
			a.pop_back();
		}

		if (a == b) cout << "YES" << endl;
		else {
			a.pop_back();
			char c = b.back();
			b.pop_back();
			if (cnt[c - '0'] && a == b) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
	return 0;
}