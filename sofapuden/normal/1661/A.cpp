#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
	int n; cin >> n;
	vector<ll> a(n), b(n);
	for(auto &x : a)cin >> x;
	for(auto &x : b)cin >> x;
	for(int i = 0; i < n; ++i){
		if(a[i] > b[i])swap(a[i],b[i]);
	}
	ll ans = 0;
	for(int i = 1; i < n; ++i)ans+=abs(a[i]-a[i-1])+abs(b[i]-b[i-1]);
	cout << ans << '\n';
}

int main(){
	int t; cin >> t;
	while(t--)solve();
}