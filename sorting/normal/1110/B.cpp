#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;

int a[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;

	cin >> n >> m >> k;

	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	int res = a[n-1] - a[0] + 1;

	for(int i = 0; i < n - 1; i++){
		a[i] = a[i+1] - a[i] - 1;
	}

	sort(a, a + n -1);

	for(int i = 1; i <= k-1; i++){
		res -= a[n - 1 -i];
	}

	cout << res << "\n";

	return 0;
}