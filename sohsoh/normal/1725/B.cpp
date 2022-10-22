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

ll n, d;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> d;
	multiset<ll> st;

	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		st.insert(x);
	}

	int ans = 0;
	while (!st.empty() && ll(st.size()) * (*st.rbegin()) > d) {
		ans++;
		ll x = *st.rbegin();
		st.erase(st.find(x));

		ll t = x;
		while (t <= d) {
			t += x;
			st.erase(st.begin());
		}
	}

	cout << ans << endl;
	return 0;
}