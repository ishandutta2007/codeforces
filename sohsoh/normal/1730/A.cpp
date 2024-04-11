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

const ll MAXN = 1e2 + 10;

int cnt[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		memset(cnt, 0, sizeof cnt);

		int n, c;
		cin >> n >> c;
		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			cnt[x]++;
		}

		int ans = 0;
		for (int i = 0; i < MAXN; i++)
			ans += min(cnt[i], c);

		cout << ans << endl;
	}
	return 0;
}