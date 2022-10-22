// orz ?
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
const ll MAXT = 80;
const ll INF = 1e9;

int A[MAXN], n, q;
vector<int> F[MAXN];

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

inline bool cnt(int l, int r, int k, int c) {
	int ind = lower_bound(all(F[k]), l) - F[k].begin();
	if (ind + c >= F[k].size() || F[k][ind + c] > r) return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		F[A[i]].push_back(i);
	}

	while (q--) {
		int f = INF, l, r, k, t = MAXT;
		cin >> l >> r >> k;
		while (t--) {
			int x = A[rng() % (r - l + 1) + l];
			if (cnt(l, r, x, (r - l + 1) / k)) f = min(f, x);	
		}

		cout << (f == INF ? -1 : f) << endl;
	}
	return 0;
}