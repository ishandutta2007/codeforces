#include <bits/stdc++.h>

using namespace std;

const long long N = 1e6 + 7;

long long a[N], pr[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n, k;

	cin >> n >> k;

	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	pr[0] = a[0];
	for(int i = 1; i < n; i++){
		pr[i] = pr[i - 1] + a[i];
	}

	sort(pr, pr + n - 1);

	long long ans = 0;

	for(int i = 0; i < k - 1; i++){
		ans -= pr[i];
	}
	ans += k * pr[n - 1];

	cout << ans << "\n";

	return 0;
}