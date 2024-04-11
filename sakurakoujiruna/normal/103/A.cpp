#include <bits/stdc++.h>
using namespace std;

const int N = 111;
typedef long long ll;

int a[N];

int main() {
	ios :: sync_with_stdio(false);
	int n; cin >> n;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	ll ans = n;
	for(int i = 1; i <= n; i ++)
		ans += (ll)i * (a[i] - 1);
	cout << ans << '\n';
	return 0;
}