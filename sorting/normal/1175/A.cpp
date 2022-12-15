#include <bits/stdc++.h>

using namespace std;

long long n, k;

void solve(){
	cin >> n >> k;

	long long ans = 0;

	while(n != 0){
		if(n % k == 0){
			n /= k;
			ans ++;
		}
		else{
			ans += n % k;
			n -= n % k;
		}
	}

	cout << ans << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long t;

	cin >> t;

	while(t--){
		solve();
	}

	return 0;
}