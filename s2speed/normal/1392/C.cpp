#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll z = 0;

ll tav(ll n , ll k){
	if(k == 0){
		return 1;
	}
	ll x = tav(n , k / 2);
	if(k % 2 == 0){
		return x * x;
	} else {
		return x * x * n;
	}
}

stack<ll> m , g;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll t;
	cin>>t;
	while(t--){
		ll n , ans = 0 , h;
		cin>>n;
		for(int i = 0 ; i < n ; i++){
			cin>>h;
			if(g.size() == 0){
				g.push(h);
				m.push(h);
			}
			if(h >= g.top() && h >= m.top()){
				ans += g.top() - m.top();
				g.pop(); g.push(h);
				m.pop(); m.push(h);
			} else if(h >= m.top()){
				g.push(h);
				m.push(h);
			} else {
				m.pop(); m.push(h);
			}
		}
		while(g.size() > 0){
			ans += g.top() - m.top();
			g.pop(); m.pop();
		}
		cout<<ans<<"\n";
	}
	return 0;
}