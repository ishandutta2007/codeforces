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

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int cnt[MAXN];

inline int solve() {
	int n;
	cin >> n;
	n *= 2;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(all(v));
	for (int i = 0; i < n - 1; i++) {
		for (int e : v) cnt[e]++;
		vector<int> ans = {v[n - 1], v[i]};
		int s = v[n - 1];
		cnt[v[n - 1]]--;
		cnt[v[i]]--;
		int p = n - 1;
		int t = n - 2;
		while (t) {
			while (cnt[v[p]] == 0 && p > 0) p--;
			int x = v[p];
			int y = s - x;	
			cnt[x]--;
			if (cnt[y]) cnt[y]--;
			else break;
			
			s = x;
			ans.push_back(x);
			ans.push_back(y);

			t -= 2;
		}	

		for (int e : v) cnt[e] = 0;
		if (t == 0) {
			cout << "YES" << endl;
			cout << ans[0] + ans[1] << endl;
			for (int i = 0; i < n; i += 2) cout << ans[i] << sep << ans[i + 1] << endl;
			return 0;
		}
	}

	cout << "NO" << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}