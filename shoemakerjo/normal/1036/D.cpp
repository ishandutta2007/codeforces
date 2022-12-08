#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define maxn 300010
int n, m;

ll a[maxn];
ll b[maxn];
ll asum = 0LL, bsum = 0LL;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		asum += a[i];
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> b[i];
		bsum += b[i];
	}
	if (asum != bsum) {
		cout << -1 << endl;
		return 0;
	}
	int ans = 0;
	int p1 = 0;
	int p2 = 0;
	ll sum1 = a[0];
	ll sum2 = b[0];
	while (p1 < n && p2 < m) {
		if (sum1 == sum2) {
			ans++;
			p1++;
			p2++;
			sum1 = 0LL;
			sum2 = 0LL;
			if (p1 == n || p2 == m) break;
			sum1 += a[p1];
			sum2 += b[p2];
		}
		else {
			if (sum1 < sum2) {
				sum1 += a[++p1];
			}
			else sum2 += b[++p2];
		}
	}
	// cout << sum1<< ": " << sum2 << endl;
	cout << ans << endl;
}