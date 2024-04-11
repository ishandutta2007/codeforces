#include <bits/stdc++.h>

using namespace std;

void solve(){
	long long n, m;
	cin >> n >> m;

	if(m == 0){
		cout << "0\n";
		return;
	}

	long long ans = n * (n + 1ll) / 2ll;
	long long t = n - m;
	long long d = (t / (m + 1ll));
	long long rem = (t % (m + 1ll));
	ans -=  d * (d + 1ll) / 2ll * (m + 1ll - rem);
	ans -= (d + 1ll) * (d + 2ll) / 2ll * rem;

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