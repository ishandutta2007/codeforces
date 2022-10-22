// Sohsoh84 :)))))
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

ll n, A[MAXN];

inline void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];

	ll ans = 0;
	for (int s = 1; s <= n; s++) {
		for (int e = s; e <= n; e++) {
			bool flag = true;
			for (int i = s; i < e; i++) {
				for (int j = i + 1; j < e; j++) {
					if (e - j + j - i + abs(A[e] - A[j]) + abs(A[j] - A[i]) == e - i + abs(A[e] - A[i])) {
						flag = false;
						break;
					}
				}
			}

			ans += flag;
			if (!flag) break;
		}
	}

	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}