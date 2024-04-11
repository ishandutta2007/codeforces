#include<bits/stdc++.h>
#include<algorithm>

typedef long long ll;

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll t;
	cin>>t;
	while(t--){
		set<ll> s;
		ll n , a , h;
		cin>>n;
		for(int i = 0 ; i < n ; i++){
			cin>>a;
			h = ((a % n) + n) % n;
			s.insert((i + h) % n);
		}
		if(s.size() == n){
			cout<<"YES"<<endl;
		} else {
			cout<<"NO"<<endl;
		}
		s.clear();
	}
	return 0;
}