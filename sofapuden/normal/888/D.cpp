#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
	int n, k; cin >> n >> k;
	ll ans = 1;
	for(int i = 2; i <= k; ++i){
		ll ret = 1;
		for(int j = 0; j < i; ++j)ret*=n-j;
		for(int j = 0; j < i; ++j)ret/=i-j;
		ret *= vector<int>{1,2,9}[i-2];
		ans+=ret;
	}
	cout << ans << '\n';
}

int main(){
	solve();
}