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

int n, k;
vector<int> vec;

inline void solve() {
	vec.clear();
	k = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		vec.push_back(x);
	}

	n--;
	while (n--) {
		if (k) {
			k--;
			vec.push_back(0);
		}

		sort(all(vec));
		vector<int> vec2;
		for (int i = 1; i < int(vec.size()); i++) {
			int x = vec[i] - vec[i - 1];
			if (x == 0) k++;
			else vec2.push_back(x);
		}

		vec = vec2;
	}

	if (k) cout << 0 << endl;
	else cout << vec.front() << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}