// \_()_/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;
const ll SQ = 316;

int n, q, A[MAXN];
pll dp[MAXN];

void Update(int i) {
	int tar = i + A[i], lst = min((i / SQ + 1) * SQ - 1, 1ll * n);
	if (tar > lst) dp[i] = {1, i};
	else dp[i] = {dp[tar].X + 1, dp[tar].Y};
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> A[i];
	for (int i = n; i > 0; i--) Update(i);
	
	while (q--) {
		int c, a;
		cin >> c >> a;
		if (c == 0) {
			int lst = min(1ll * n, (a / SQ + 1) * SQ - 1), b;
			cin >> b;
			A[a] = b;
			for (int i = lst; i > max(lst - SQ, 0ll); i--) Update(i);
		} else {
			pll ans = {0, a};
			while (a <= n) {	
				ans.Y = a;
				if (dp[a].Y == a) {
					ans.X++;
					a += A[a];
					continue;
				}
				
				ans.X += dp[a].X;
				a = dp[a].Y;
				
				ans.Y = a;
				a += A[a];
			}
			
			cout << ans.Y << sep << ans.X << endl;
		}
		
	}

	return 0;
}