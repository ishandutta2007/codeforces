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
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if (n & 1) cout << "NO" << endl;
		else {
			n /= 2;
			int sq = sqrt(n);
			if (sq * sq == n) cout << "YES" << endl;
			else {
				if (n & 1) cout << "NO" << endl;
				else {
					n /= 2;
					int sq = sqrt(n);
					if (sq * sq == n) cout << "YES" << endl;
					else cout << "NO" << endl;
				}
			}
		}
	}
	return 0;
}