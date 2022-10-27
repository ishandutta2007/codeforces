#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100 + 10;

int main() {
	int t;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;

    while (t --) {
    	int n; cin >> n;
    	vector<int> c(n+1, 0);
    	for (int i = 1; i <= n; i ++)
    		cin >> c[i];

    	vector<LL> mn(n+1, 0), sum(n+1, 0);
    	mn[1] = c[1]; sum[1] = c[1];
    	mn[2] = c[2]; sum[2] = c[2];

    	for (int i = 3; i <= n; i ++) {
    		mn[i] = min(mn[i-2], c[i] * 1LL);
    		sum[i] = sum[i-2] + c[i];
    	}

    	LL ans = 2e18;
    	for (int i = 2; i <= n; i ++) {
    		LL tmp = (sum[i] - mn[i]) + mn[i] * (n - ((i+1)/2 - 1)) +
    			(sum[i-1] - mn[i-1]) + mn[i-1] * (n - (i/2-1));
    		ans = min(ans, tmp);
    	}
    	cout << ans << endl;
	}
}