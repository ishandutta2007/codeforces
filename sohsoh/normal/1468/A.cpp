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

int n, fen[MAXN], f[MAXN], A[MAXN];
vector<int> Q[MAXN];

inline void update(int ind, int val) {
	for (++ind; ind < n + 5; ind += ind & -ind)
		fen[ind] = max(fen[ind], val);
}

inline int query(int ind) {
	int ans = 0;
	for (++ind; ind > 0; ind -= ind & -ind)
		ans = max(ans, fen[ind]);
	return ans;
}

inline void solve() {
	fill(fen, fen + n + 10, 0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> A[i];

	stack<int> st;
	for (int i = n; i > 0; i--) {
		while (!st.empty() && A[st.top()] < A[i]) st.pop();
		if (!st.empty()) Q[st.top()].push_back(i);
		st.push(i);
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		f[i] = max((i > 1 ? 2 : 1), query(A[i]) + 1);
		for (int j : Q[i])
			update(A[j], f[j] + 1);

		update(A[i], f[i]);
		ans = max(ans, f[i]);
		Q[i].clear();
	}

	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}