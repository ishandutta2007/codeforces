#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
	int n; cin >> n;
	if(n&1){
		cout << 0 << '\n';
		return;
	}
	ll ans = 1;
	for(int i = 1; i <= n/2; ++i){
		ans*=i*i;
		ans%=998244353;
	}
	cout << ans << '\n';

}

int main(){
	int t; cin >> t;
	while(t--)solve();
}