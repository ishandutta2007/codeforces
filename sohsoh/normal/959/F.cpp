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

const ll MAXN = 2e6 + 10;
const ll MOD = 1e9 + 7;

int n, q, A[MAXN], ans[MAXN], T[MAXN], F[MAXN];
vector<pll> Q[MAXN];
ll pw[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	pw[0] = 1;
	for (int i = 1; i <= n; i++)
		pw[i] = pw[i - 1] * 2 % MOD;

	for (int i = 1; i <= n; i++) cin >> A[i];
	for (int i = 1; i <= q; i++) {
		int l, x;
		cin >> l >> x;
		Q[l].push_back({i, x});
	}

	vector<int> vec = {0};
	fill(T, T + MAXN, -1);
	T[0] = 0;

	for (int i = 1; i <= n; i++) {
		int x = A[i];
		F[i] = F[i - 1];

		if (T[x] < 0) {
			int sz = vec.size();
			for (int i = 0; i < sz; i++) {
				vec.push_back(vec[i] ^ x);
				T[vec[i] ^ x] = i;
			}
		} else F[i]++;

		for (pll e : Q[i]) {
			int ind = e.X, x = e.Y;
			if (T[x] < 0) continue;
			
			int p = F[i];
		//	if (T[x]) p -= F[T[x] - 1];

			ans[ind] = pw[p];
		}
	}

	for (int i = 1; i <= q; i++)
		cout << ans[i] << endl;
	return 0;
}