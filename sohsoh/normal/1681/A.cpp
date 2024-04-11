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
		int n, m;
		vector<int> vec[2];
		cin >> n;
		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			vec[0].push_back(x);
		}

		cin >> m;
		for (int i = 1; i <= m; i++) {
			int x;
			cin >> x;
			vec[1].push_back(x);
		}

		int m0 = *max_element(all(vec[0])), m1 = *max_element(all(vec[1]));
		if (m0 < m1) cout << "Bob" << endl << "Bob" << endl;
		else if (m0 > m1) cout << "Alice" << endl << "Alice" << endl;
		else cout << "Alice" << endl << "Bob" << endl;
	}
	return 0;
}