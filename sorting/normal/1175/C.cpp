#include <bits/stdc++.h>

using namespace std;

const long long N = 2e5 + 7;
const long long R = 1e9;

long long a[N];
long long n, k;

void solve(){
	cin >> n >> k;

	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	long long l = 1, r = R;
	long long ans = R, x = 1;

	for(int i = 0; i < n - k; i++){
		long long d = a[k + i] - a[i];

		if((d / 2) + (d % 2) < ans){
			ans = (d / 2) + (d % 2);
			x = (d / 2) + a[i];
		}
	}

	cout << x << "\n";

	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;

	cin >> t;

	while(t--){
		solve();
	}

	return 0;
}