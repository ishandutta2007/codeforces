#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll N;
	int K;
	cin >> N >> K;
	ll bestleft = 2*N;
	int ans = 1;
	ll a[K+1];
	for (int i = 1; i <= K; i++) {
		cin >> a[i];
		ll rem = N - a[i] * (N/a[i]);
		if (rem < bestleft) {
			bestleft = rem;
			ans = i;
		}
	}
	cout << ans << " " << N/a[ans] << endl;
	cin >> N;
}