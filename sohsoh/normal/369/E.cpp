// Sohsoh84 :)))
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

int n, fen[MAXN], ans[MAXN], q, D[MAXN];
vector<int> Q[MAXN], seg[MAXN], V[MAXN];

inline void Add(int ind, int val) {
	for (++ind; ind < MAXN; ind += ind & (-ind))
		fen[ind] += val;
}

inline void Add(int L, int R, int val) {
	Add(L, val);
	Add(R + 1, -val);
}

inline int Query(int ind) {
	int ans = 0;
	for (++ind; ind > 0; ind -= ind & -ind)
		ans += fen[ind];
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		int l, r;
		cin >> l >> r;
		seg[l].push_back(r);
	}

	for (int i = 1; i <= q; i++) {
		int cnt;
		cin >> cnt;
		while (cnt--) {
			int x;
			cin >> x;
			Q[x].push_back(i);
			V[i].push_back(x);
		}

		sort(all(V[i]), greater<int>());
	}

	for (int l = 1; l < MAXN; l++) {
		for (int r : seg[l])
			Add(l, r, 1);
		for (int q : Q[l]) {
			ans[q] += Query(V[q].back()) - D[q];
			V[q].pop_back();
			if (!V[q].empty()) D[q] = Query(V[q].back());
		}
	}

	for (int i = 1; i <= q; i++) cout << ans[i] << endl;
	return 0;
}