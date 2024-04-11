#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

vector<ll> v;
set<ll> s;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll t , n;
	cin>>t;
	while(t--){
		ll h;
		cin>>n;
		for(int i = 0 ; i <= n ; i++){
			v.push_back(i);
		}
		for(int i = 0 ; i < n ; i++){
			cin>>h;
			s.insert(h);
			v[h] += 1e6;
		}
		sort(v.begin() , v.end());
		reverse(v.begin() , v.end());
		ll si = s.size() - 1;
		cout<<max(min(si , v[0] / 1000000) , min(si + 1 , v[0] / 1000000 - 1))<<endl;
		s.clear();
		v.clear();
	}
	return 0;
}