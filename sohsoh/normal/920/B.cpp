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

const ll MAXN = 5e3 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, ans[MAXN];
vector<int> L[MAXN], R[MAXN], q;

inline int solve() {
	q.clear();
	for (int i = 0; i < MAXN; i++) L[i].clear(), R[i].clear();
	memset(ans, 0, sizeof ans);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int l, r;
		cin >> l >> r;
		L[l].push_back(i);
		R[r].push_back(i);
	}

	for (int i = 1; i < MAXN; i++) {
		sort(all(L[i]));
		for (int e : L[i]) q.push_back(e);
		if (!q.empty()) {
			ans[q.front()] = i;
			q.erase(q.begin());	
		}

		for (int e : R[i]) {
			auto it = find(all(q), e);
			if (it != q.end()) q.erase(it);
		}
	}

	for (int i = 1; i <= n; i++) cout << ans[i] << sep;
	cout << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}