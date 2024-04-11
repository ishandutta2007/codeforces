#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		vector<int> v;
		int s = 0, n, x;
		cin >> n >> x;
		for (int i = 1; i <= n; i++) {
			int t;
			cin >> t;
			s += t;
			v.push_back(t);
		}

		if (s == x) cout << "NO" << endl;
		else {
			s = 0;
			sort(all(v));
			for (int i = 0; i < v.size(); i++) {
				s += v[i];
				if (s == x) swap(v[i], v[i + 1]);
			}

			cout << "YES" << endl;
			for (int e : v) cout << e << sep;
			cout << endl;
		}
	}
	return 0;
}