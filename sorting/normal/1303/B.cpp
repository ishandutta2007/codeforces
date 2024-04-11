#include <bits/stdc++.h>

using namespace std;

void solve(){
	long long n, g, b;
	cin >> n >> g >> b;

	if(g >= b){
		cout << n << "\n";
		return; 
	}
	long long ng = ((n + 1ll) / 2ll);
	long long ans = ((ng / g) * (b + g)) + (ng % g);
	if(ng % g == 0){
		ans -= b;
		long long need =  n - ng;
		ans += max(need - b * (ng / g - 1ll), 0ll);
	}
	else{
		long long need = n - ng;
		long long done = (ng / g) * b;

		if(done < need)
			ans += need - done;
	}
	cout << ans << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while(t--)
		solve();
}