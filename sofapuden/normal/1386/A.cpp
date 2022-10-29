#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll fS(ll x){
	ll lo = 1, hi = x-1, cn = 0, ans = -1, out = 1;
	while(cn <= 80){
		if(cn&1)ans-=(lo+hi)/2;
		else ans +=(lo+hi)/2;
		lo = (lo+hi)/2+1;
		out = min(out, ans);
		cn++;
	}
	return out;
}
		
		

int main(){
    int t; cin >> t;
    while(t--){
    	ll n; cin >> n;
    	ll start = -fS(n);
    	cout << "? " << start << endl;
    	ll tr; cin >> tr;
    	ll lo = 1LL, hi = n-1LL, cn = 0LL, best = n, ans = start, x;
    	while(lo <= hi){
    		ll mid =(lo+hi)/2LL;
    		if(cn&1)ans-=mid;
    		else ans+=mid;
    		cout << "? " << ans << endl;
    		cin >> x;
    		if(x){
    			hi = mid-1LL;
    			best = mid;
    		}
    		else{
    			lo = mid+1LL;
    		}
    		cn++;
    	}
    	cout << "= " << best << endl;
    }
}