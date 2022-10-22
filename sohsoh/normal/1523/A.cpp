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

string S[2];
int n, m;

inline int solve() {
	cin >> n >> m;	
	cin >> S[0];

	m = min(n + 3, m);
	for (int i = 1; i <= m; i++) {
		int ind = i & 1;
		S[ind] = S[ind ^ 1];
		for (int j = 0; j < n; j++) {
			S[ind][j] = '1';
			if (S[ind ^ 1][j] == '1') continue;
			int x = 0;
			if (j) x ^= (S[ind ^ 1][j - 1] == '1');
			if (j < n - 1) x ^= (S[ind ^ 1][j + 1] == '1');
			S[ind][j] = (x == 1) + '0';
		}

	}

	cout << S[m & 1] << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}