#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int t; cin >> t;
	while(t--){
		ll a, b; cin >> a >> b;
		ll sa, wa; cin >> sa >> wa;
		ll s, w; cin >> s >> w;
		if(s > w){
			swap(s,w);
			swap(sa,wa);
		}
		ll ans = 0;
		for(ll i = 0; i <= sa; ++i){
			ll ancu = 0;
			ll cu = a;
			ll x = min(i,a/s);
			cu-=x*s;
			ancu+=x;	
			ll cuw = wa;
			x = min(cuw,cu/w);
			ancu+=x;
			cuw-=x;
			cu = b;
			x = min(sa-i,cu/s);
			cu-=x*s;
			ancu+=x;
			x = min(cuw,cu/w);
			ancu+=x;
			cuw-=x;
			ans = max(ans,ancu);
		}
		cout << ans << '\n';
	}
}