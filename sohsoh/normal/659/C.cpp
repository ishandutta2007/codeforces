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

set<int> st;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		st.insert(x);
	}

	vector<int> ans;
	for (int j = 1; j <= m; j++) {
		if (st.find(j) != st.end()) continue;
		m -= j;
		ans.push_back(j);
	}

	cout << ans.size() << endl;
	for (int e : ans) cout << e << sep;
	cout << endl;
	return 0;
}