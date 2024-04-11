#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

void solve(){
	int n; cin >> n;
	vector<ll> v(n);
	for(auto &x : v)cin >> x;
	ll mn = min(v[0],0ll);
	ll pre = 0;
	ll ans = 0;
	for(int i = 1; i < n; ++i){
		if(v[i] > v[i-1]){
			pre+=v[i]-v[i-1];
			ans+=v[i]-v[i-1];
		}
		mn = min(mn,v[i]-pre);
	}
	ans+=v[0];
	ans-=2*mn;
	cout << ans << '\n';
}

int main(){
	int t; cin >> t;
	while(t--)solve();

}