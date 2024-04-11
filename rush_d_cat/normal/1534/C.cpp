#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	int t;
	cin >> t;
	while (t --) {
		int n; cin >> n;
		vector<int> nex(n+1,0), vis(n+1,0);
		vector<int> a(n), b(n);
		for (int i = 0; i < n; i ++) cin >> a[i];
		for (int i = 0; i < n; i ++) cin >> b[i];
		for (int i = 0; i < n; i ++)
			nex[a[i]] = b[i];
		ll ans = 1;
		for (int i = 1; i <= n; i ++) {
			if (vis[i] == 0) {
				ans = ans * 2 % mod;
				int now = i;
				while (! vis[now]) {
					vis[now] = 1; now = nex[now];
				}
			}
		}
		cout << ans << endl;
	}
}