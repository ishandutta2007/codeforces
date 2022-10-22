//: // ////: ///  / : //// / :
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

const ll MAXN = 1e2 + 10;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		bitset<MAXN> a, b;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			char c;
			cin >> c;
			if (c == '1') a.set(i);
		}

		for (int i = 0; i < n; i++) {
			char c;
			cin >> c;
			if (c == '1') b.set(i);
		}

		if ((a & b).count()) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	return 0;
}