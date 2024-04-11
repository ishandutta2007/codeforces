#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll _, n, h, cur, ans, cnt2, cnt3, a[200005];

int main() {
	cin.tie(0)->ios::sync_with_stdio(false);
	cin >> _;
	while (_ --) {
		cin >> n >> h;
		for (int i = 1; i <= n; i ++) cin >> a[i];
		sort(a + 1, a + n + 1);
		ans = 0;
		for (int j = 0; j < 3; j ++) {
			cur = h, cnt2 = 2, cnt3 = 1;
			for (int i = 1; i <= n; i ++) {
				while (cur <= a[i]) {
					if (cnt2 == j && cnt3) cnt3--, cur *= 3;
					else if (cnt2) cnt2--, cur *= 2;
					else break;
				}
				if (cur <= a[i]) break;
				cur += a[i] / 2;
				ans = max(ans, 1ll * i);
			}
		}
		cout << ans << "\n";
	}
	return 0;	
}