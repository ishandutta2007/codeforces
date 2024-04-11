#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
	ll n; cin >> n;
	vector<ll> val;
	string s; cin >> s;
	ll ans = 0;
	for(int i = 0; i < n; ++i){
		if(s[i] == 'L'){
			ans+=i;
			val.push_back(n-i-1-i);
		}else{
			ans+=n-i-1;
			val.push_back(i-(n-i-1));
		}
	}
	sort(val.rbegin(),val.rend());
	for(int i = 0; i < n; ++i){
		ans+=max(0ll,val[i]);
		cout << ans << ' ';
	}
	cout << '\n';
}

int main(){
	int t; cin >> t;
	while(t--)solve();

}