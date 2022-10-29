#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

void solve(){
	int n; cin >> n;
	vector<array<int,2>> in(n), ta(n);
	for(auto &x : in)cin >> x[0];
	for(auto &x : in)cin >> x[1];
	for(auto &x : ta)cin >> x[0];
	for(auto &x : ta)cin >> x[1];
	ll ans = 0;
	ll a = 0, b = 0;
	for(int i = 0; i < n; ++i){
		a+=in[i][0];
		b+=in[i][1];
		a-=ta[i][0];
		b-=ta[i][1];
		if(a > 0 && b < 0){
			ll mn = min(a,-b);
			a-=mn;
			b+=mn;
			ans+=mn;
		}
		else if(a < 0 && b > 0){
			ll mn = min(-a,b);
			a+=mn;
			b-=mn;
			ans+=mn;
		}
		ans += abs(a) + abs(b);
	}
	if(a || b){
		cout << -1 << '\n';
	}
	else{
		cout << ans << '\n';

	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solve();

}