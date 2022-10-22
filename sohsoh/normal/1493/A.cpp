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
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> ans;
		for (int i = k + 1; i <= n; i++) ans.push_back(i);
		for (int i = k - 1; i > 0; i--)
			if (k - i <= i) ans.push_back(i);

		cout << ans.size() << endl;
		for (int e : ans) cout << e << sep;
		cout << endl;
	}
	return 0;
}