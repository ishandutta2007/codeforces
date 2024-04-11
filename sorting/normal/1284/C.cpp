#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3e5 + 7;

long long fact[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n, m;
	cin >> n >> m;

	fact[0] = 1;
	for(int i = 1; i <= n; ++i)
		fact[i] = (fact[i - 1] * i) % m;

	long long ans = 0;
	for(long long i = 0; i < n; ++i){
		long long curr =  (fact[n - i] * (n - i)) % m;
		curr *= fact[i + 1];
		curr %= m;
		ans += curr;
		ans %= m;
	}

	cout << ans << endl;

	return 0;
}