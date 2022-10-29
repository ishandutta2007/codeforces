#include<bits/stdc++.h>
 
using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	multiset<ll> ms;
	ll ans = 0;
	for(int i = 0; i < n; ++i){
		ll x; cin >> x;
		ans-=x;
		ms.insert(x);
		ms.insert(x);
		ms.erase(ms.begin());
	}
	for(auto y : ms){ans+=y;}
	cout << ans << '\n';
}