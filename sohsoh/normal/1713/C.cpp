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

const ll MAXN = 1e5 + 10;

pair<int, bool> dp[MAXN];
vector<int> vec;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	for (int i = 0; i * i < MAXN * 2; i++)
		vec.push_back(i * i);

	dp[0] = {0, true};
	for (int i = 1; i < MAXN; i++) {
		for (int e : vec) {
			int x = e - (i - 1);
			if (x < 0 || x > i - 1) continue;
			
			if (dp[x].Y)
				dp[i] = {x, true};
		}
	}

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if (!dp[n].Y) {
			cout << -1 << endl;
			continue;
		}

		vector<int> vec;
		while (n > 0) {
			int x = dp[n].X;
			for (int i = x; i < n; i++)
				vec.push_back(i);

			n = x;
		}

		reverse(all(vec));
		for (int e : vec)
			cout << e << sep;
		cout << endl;
	}
	return 0;
}