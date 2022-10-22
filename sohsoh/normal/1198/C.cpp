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

int n, mm;
set<int> st;
vector<int> m;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);	
	int t;
	cin >> t;

	while (t--) {
		st.clear();
		m.clear();

		cin >> n >> mm;
		for (int i = 1; i <= 3 * n; i++)
			st.insert(i);

		for (int i = 1; i <= mm; i++) {
			int u, v;
			cin >> u >> v;

			if (st.find(u) != st.end() && st.find(v) != st.end()) {
				m.push_back(i);
				st.erase(u);
				st.erase(v);
			}
		}

		if (m.size() >= n) {
			cout << "Matching" << endl;
			for (int i = 0; i < n; i++)
				cout << m[i] << ' ';
			cout << endl;
		} else {
			cout << "IndSet" << endl;
			while (st.size() > n) st.erase(st.begin());
			for (int e : st) cout << e << ' ';
			cout << endl;
		}
	}
	return 0;
}