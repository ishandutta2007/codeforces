#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using db = double;
#define pb push_back
#define fir first
#define sec second

const int N = 2e6L + 11;
int cnt[N + 10], sum[N + 10];
ll vsum[N + 10];

int main() {
	int n; cin >> n; ll x, y; cin >> x >> y;
	for(int i = 1; i <= n; i ++) {
		int x; scanf("%d", &x);
		cnt[x] ++;
	}
	for(int i = 1; i < N; i ++) {
		sum[i] = sum[i - 1] + cnt[i];
		vsum[i] = vsum[i - 1] + cnt[i] * ll(i);
	}
	
	ll ans = 8e18L;
	for(int d = 2; d < int(1e6L); d ++) {
		int elim = x / y;
		
		ll tmp = 0; db dtmp = 0;
		for(int ed = d; ed < N; ed += d) {
			ll ux = 0, uy = 0;
			if(elim == 0) {
				ux = sum[ed - 1] - sum[ed - d];
			} else if(elim >= d - 1) {
				uy = (sum[ed - 1] - sum[ed - d]) * ll(ed) - (vsum[ed - 1] - vsum[ed - d]);
			} else {
				ux = sum[ed - elim - 1] - sum[ed - d];
				uy = (sum[ed - 1] - sum[ed - elim - 1]) * ll(ed) - (vsum[ed - 1] - vsum[ed - elim - 1]);
			}
			tmp += ux * x + uy * y;
			dtmp += ux * x + uy * y;
		}
		
		//if(d <= 5) cout << d << ' ' << tmp << '\n';
		
		if(dtmp < 1e18L)
			ans = min(ans, tmp);
	}
	cout << ans << '\n';
	
	return 0;
}