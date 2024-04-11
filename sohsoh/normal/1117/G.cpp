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

int n, q, L[MAXN], R[MAXN], A[MAXN], q_l[MAXN], q_r[MAXN];
vector<pll> LQ[MAXN], RQ[MAXN];
pll fen[MAXN];
ll ans[MAXN];
vector<int> T[MAXN];

pll operator+ (const pll& a, const pll& b) {
	return {a.X + b.X, a.Y + b.Y};
}

pll operator- (const pll& a, const pll& b) {
	return {a.X - b.X, a.Y - b.Y};
}

inline void update(int ind, pll val) {
	for (++ind; ind < MAXN; ind += ind & -ind)
		fen[ind] = fen[ind] + val;
}

inline pll query(int ind) {
	pll ans = {0, 0};
	for (++ind; ind > 0; ind -= ind & -ind)
		ans = ans + fen[ind];
	return ans;
}

inline pll query(int l, int r) {
	return query(r) - query(l - 1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> A[i];

	for (int i = 1; i <= n; i++)
		for (L[i] = i - 1; L[i] && A[L[i]] < A[i]; L[i] = L[L[i]]);
	for (int i = n; i > 0; i--)
		for (R[i] = i + 1; R[i] <= n && A[R[i]] < A[i]; R[i] = R[R[i]]);

	for (int i = 1; i <= q; i++) cin >> q_l[i];
	for (int i = 1; i <= q; i++) cin >> q_r[i];

	for (int i = 1; i <= q; i++) {
		int l = q_l[i], r = q_r[i];
		ans[i] -= r - l + 1;
		LQ[l].push_back({i, r});
		RQ[r].push_back({i, l});
	}

	for (int i = 1; i <= n; i++) {
		T[L[i]].push_back(i);
		update(i, {L[i], 0});
	}

	for (int l = 0; l <= n; l++) {
		for (pll q : LQ[l]) {
			int ind = q.X, r = q.Y;
			pll e = query(l, r);
			ans[ind] -= e.X + e.Y * (l - 1);
		}

		for (int ind : T[l])
			update(ind, {-L[ind], 1});
	}

	fill(fen, fen + MAXN, make_pair(0, 0));
	for (int i = 0; i < n + 2; i++) T[i].clear();

	for (int i = 1; i <= n; i++) {
		T[R[i]].push_back(i);
		update(i, {R[i], 0});
	}

	for (int r = n + 1; r > 0; r--) {			
		for (pll q : RQ[r]) {
			int ind = q.X, l = q.Y;
			pll e = query(l, r);
			ans[ind] += e.X + e.Y * (r + 1);
		}

		for (int ind : T[r])
			update(ind, {-R[ind], 1});
	}

	for (int i = 1; i <= q; i++)
		cout << ans[i] << sep;
	cout << endl;
	return 0;
}