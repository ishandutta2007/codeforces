#include <bits/stdc++.h>
using namespace std;

const int N = 100011;
typedef long long ll;

int a[N];

int main() {
	ios :: sync_with_stdio(false);
	int n; cin >> n;
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	ll ans = 0;
	int last = 0;
	for(int i = 1; i <= n; i ++)
		if(i == n || a[i] != a[i + 1]) {
			ll l = i - last;
			ans += l * (l + 1) / 2;
			last = i;
		}
	cout << ans << '\n';
	return 0;
}