#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 5;
int a[MAXN], b[MAXN], n, m, ta, tb, k, ans = 0;

int main() {
	cin >> n >> m >> ta >> tb >> k;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		a[i] += ta;
	}
	for(int i = 0; i < m; i++) {
		cin >> b[i];
	}
	if(k >= n || k >= m) {
		cout << -1 << '\n';
		return 0;
	}
	for(int j = 0; j <= k; j++) {
		// cancel k
		int arriv = a[j];
		if(arriv > b[m - 1]) {
			cout << -1 << '\n';
			return 0;
		}
		int lo = 0, hi = m - 1;
		while(lo < hi) {
			int mi = (lo + hi)/2;
			if(b[mi] >= arriv)
				hi = mi;
			else
				lo = mi + 1;
		}
		if(lo + k - j >= m) {
		    cout << -1 << '\n';
		    return 0;
		}
		ans = max(ans, b[lo + k - j] + tb);
	}
	cout << ans << '\n';
}