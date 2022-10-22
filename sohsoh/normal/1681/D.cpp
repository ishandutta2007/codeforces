#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;

ll n, x;
set<ll> st;
queue<pll> q;

inline vector<int> vec(ll x) {
	vector<int> vec;
	while (x) {
		vec.push_back(x % 10);
		x /= 10;
	}
	
	return vec;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> x;

	q.push({x, 0});
	if (vec(x).size() == n) return cout << 0 << endl, 0;	

	while (!q.empty()) {
		pll e = q.front();
		ll x = e.X, d = e.Y;
		q.pop();

		vector<int> f = vec(x);
		for (int e : f) {
			ll tx = x * e;
			if (st.find(tx) != st.end()) continue;
			
			int l = vec(tx).size();
			if (l > int(n)) continue;
			if (l == int(n)) return cout << d + 1 << endl, 0;

			st.insert(tx);
			q.push({tx, d + 1});
		} 
	}

	cout << -1 << endl;
	return 0;
}