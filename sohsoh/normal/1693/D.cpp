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

namespace fenwick {
	int fen[MAXN];
	
	inline void reset() {
		fill(fen, fen + MAXN, MAXN);
	}

	inline void update(int ind, int val) {
		ind = MAXN - 5 - ind;
		for (++ind; ind < MAXN; ind += ind & -ind)
			fen[ind] = min(fen[ind], val);
	}

	inline int query(int ind) {
		ind = MAXN - 5 - ind;
		int ans = MAXN;

		for (++ind; ind > 0; ind -= ind & -ind)
			ans = min(ans, fen[ind]);
		return ans;
	}
}

int n, A[MAXN], R[MAXN], ans[MAXN], L[MAXN]; 
vector<pll> T[MAXN], Q[MAXN];

// f -> max(min(inv[i -> n]))

inline void wtf() {	
	for (int i = n; i > 0; i--) {
		for (R[i] = i + 1; A[R[i]] > A[i] && R[i] <= n; R[i] = R[R[i]]);
		Q[R[i] + 1].push_back({i, A[i]});
	}

	for (int i = 1; i <= n; i++) {
		for (L[i] = i - 1; A[L[i]] < A[i] && L[i] > 0; L[i] = L[L[i]]);
		T[L[i]].push_back({A[i], i});
	}

	fenwick::reset();
	for (int i = n; i > 0; i--) {
		for (pll e : T[i])
			fenwick::update(e.X, e.Y);
		for (pll e : Q[i])
			ans[e.X] = min(ans[e.X], fenwick::query(e.Y) - 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		ans[i] = n;
	}

	wtf();

	fenwick::reset();
	for (int i = 0; i < MAXN; i++) {
		Q[i].clear();
		T[i].clear();
		L[i] = R[i] = 0;
	}

	for (int i = 1; i <= n; i++)
		A[i] = n - A[i] + 1;
	wtf();

	ll fans = 0;
	for (int i = n; i > 0; i--) {	
		if (i < n) 
			ans[i] = min(ans[i], ans[i + 1]);
		fans += ans[i] - i + 1;
	}

	cout << fans << endl;
	return 0;
}