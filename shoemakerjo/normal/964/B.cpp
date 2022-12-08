#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	ll A, B, C, T;
	cin >> n >> A >> B >> C >> T;
	ll cur;
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		ll o1 = A;
		ll diff = T-cur;
		ll ccur = diff*C + A-B*diff;
		// cout << "current increase " << max(o1, ccur) << endl;
		ans += max(o1, ccur);
	}
	cout << ans << endl;
	cin >> n;
}