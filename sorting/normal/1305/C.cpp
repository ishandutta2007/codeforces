#include <bits/stdc++.h>

using namespace std;

const long long kMax = 1007;

long long cnt[kMax];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n, m;
	cin >> n >> m;

	vector<long long> a(n);
	for(long long i = 0; i < n; ++i){
		cin >> a[i];

		++cnt[a[i] % m];
		if(cnt[a[i] % m] >= 2){
			cout << "0\n";
			return 0;
		}
	}

	sort(a.begin(), a.end());
	long long ans = 1;
	for(int i = 0; i < n; ++i){
		for(int j = i + 1; j < n; ++j){
			ans *= (a[j] - a[i]);
			ans %= m;
		}
	}

	cout << ans << "\n";
}