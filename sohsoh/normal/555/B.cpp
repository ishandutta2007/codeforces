#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define int			ll
#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;

int n, m, ans[MAXN];
pll P[MAXN];
vector<pair<pll, int>> B;
vector<pll> A;

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> P[i].X >> P[i].Y;
		if (i) B.push_back({{P[i].X - P[i - 1].Y, P[i].Y - P[i - 1].X}, i});
	}

	for (int i = 1; i <= m; i++) {
		int x;
		cin >> x;
		A.push_back({x, i});
	}

	sort(all(A));
	sort(all(B));

	int ptr = 0;
	set<pll> st;

	for (auto [x, ind] : A) {	
		while (ptr < int(B.size()) && B[ptr].X.X <= x) st.insert({B[ptr].X.Y, B[ptr].Y}), ptr++;
		
		if (!st.empty() && st.begin() -> X >= x) {
			ans[st.begin() -> Y] = ind;
			st.erase(st.begin());
		}
	}

	if (ptr < int(B.size()) || !st.empty()) return cout << "No" << endl, 0;
	cout << "Yes" << endl;
	for (int i = 1; i < n; i++)
		cout << ans[i] << sep;
	cout << endl;
	return 0;
}