#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e5 + 10;
const ll SQ = 2000;
const ll SQI = MAXN / SQ + 5;

int pt[MAXN], qpt[MAXN], L[MAXN], n, m, q, ans[MAXN];
vector<int> R[MAXN];
vector<pll> Q[MAXN];

inline int boom(int ql, int ans, int l, int r) {
	for (int i = l; i <= r; i++)
		if (L[i] >= ql && L[i] <= ans)
			ans = i;

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		L[i] = i;
		R[i].push_back(i);
		R[i].push_back(n);
		Q[i].push_back({MAXN * SQ, MAXN - 1});
	}

	for (int i = 0; i < m; i++) {
		int l, r;
		cin >> l >> r;
		l--, r--;

		L[r] = l;
		R[l].push_back(r);
	}

	cin >> q;
	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		l--, r--;

		if (r - l + 1 <= SQ) ans[i] = boom(l, l, l, r);	
		else Q[l].push_back({r, i});
	}

	for (int i = 0; i < n; i++) {
		sort(all(R[i]));
		sort(all(Q[i]));
	}

	for (int r = 0; r < n; r += SQ) {
		stack<pll> st;
		for (int l = r - 1; l >= 0; l--) {
			while (R[l][pt[l] + 1] < r) pt[l]++;
			int tr = R[l][pt[l]], f = tr;

			while (!st.empty() && st.top().X <= tr) {
				f = max(f, st.top().Y);
				st.pop();
			}

			st.push({l, f});
		
			while (Q[l][qpt[l]].X < r + SQ) {
				ans[Q[l][qpt[l]].Y] = boom(l, f, r, Q[l][qpt[l]].X);
				qpt[l]++;
			}
		}
	}

	for (int i = 0; i < q; i++)
		cout << ans[i] + 1 << endl;
	return 0;
}