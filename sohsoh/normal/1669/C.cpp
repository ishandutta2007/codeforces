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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	
	while (t--) {		
		int cnt[2][2] = {{0, 0}, {0, 0}}, n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			cnt[i & 1][x & 1]++;
		}

		cout << ((cnt[0][0] && cnt[0][1]) || (cnt[1][0] && cnt[1][1]) ? "NO" : "YES") << endl;
	}
	return 0;
}