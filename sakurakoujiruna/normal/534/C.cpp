#include <bits/stdc++.h>
using namespace std;

const int N = 200011;
typedef long long ll;

ll d[N];

int main() {
	ios :: sync_with_stdio(false);
	int n; ll a; cin >> n >> a;
	for(int i = 0; i < n; i ++)
		cin >> d[i];
	ll sum = accumulate(d, d + n, 0LL);
	for(int i = 0; i < n; i ++) {
		ll l = max(1LL, a - sum + d[i]);
		ll r = min(d[i], a - n + 1);
		cout << d[i] - (l <= r ? r - l + 1 : 0) << ' ';
	}
	cout << '\n';
	return 0;
}