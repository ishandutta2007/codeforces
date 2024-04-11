#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 7;

long long a[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n, m, k;

	cin >> n >> m >> k;

	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	sort(a, a+n);

	long long sum = k * a[n-1] + a[n-2], res;

	res = sum * (m / (k+1));
	res += (m % (k+1)) * a[n-1];

	cout << res << "\n";

	return 0; 
}