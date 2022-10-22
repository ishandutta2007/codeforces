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

int B[MAXN], A[MAXN], T[MAXN], n, deg[MAXN];
vector<int> vec[MAXN];

inline void solve() {
	for (int i = 0; i < n + 10; i++)
		A[i] = T[i] = B[i] = deg[i] = 0, vec[i].clear();

	cin >> n;
	vector<int> tvec, ans;
	for (int i = 1; i <= n; i++) {
		cin >> B[i];
		if (B[i] == 0) {
			T[i] = 1;
			tvec.push_back(i);
		} else if (B[i] == n + 1) {
			T[i] = 0;
			tvec.push_back(i);
		}

		vec[B[i]].push_back(i);
		deg[B[i]]++;
	}

	while (!tvec.empty()) {
		sort(all(tvec), [] (int x, int y) {
			return deg[x] < deg[y];
		});

		for (int e : tvec) ans.push_back(e);
		int x = tvec.back();
		tvec.clear();

		for (int e : vec[x]) {
			T[e] = (T[x] ^ 1);
			tvec.push_back(e);
		}
	}

	cout << count(T + 1, T + n + 1, 0) << endl;
	for (int e : ans)
		cout << e << sep;
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}