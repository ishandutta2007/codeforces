#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	int t;
	cin >> t;
	while (t --) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i ++) cin >> a[i];
		ll ans = a[0] + a[n-1];
		for (int i = 1; i < n; i ++) {
			ans += abs(a[i] - a[i-1]);
		}
		//cout << ans << endl;
		for (int i = 0; i < n; i ++) {
			int l = (i>0?a[i-1]:0), r = (i<n-1?a[i+1]:0);
 			if (a[i] > l && a[i] > r) {
				ans -= a[i] - max(l,r); a[i] = max(l,r);
			}
			//printf("a[%d] = %d\n", i, a[i]);
		}
		cout << ans << endl;
	}
}