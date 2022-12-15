#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;

int a[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	int mn = 0, sum = 0, ans = 0;

	for(int i = 0; i < n; i++){
		sum += a[i];

		ans = max(ans, sum - mn);

		mn = min(mn, sum);
	}

	cout << -sum + 2 * ans << "\n";

	return 0;
}