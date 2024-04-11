#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll t , n;
	cin>>t;
	while(t--){
		vector<ll> v;
		set<ll> s;
		ll h , k , ans[10000];
		cin>>n>>k;
		for(int i = 0 ; i < n ; i++){
			cin>>h;
			if(s.find(h) == s.end()){
				v.push_back(h);
				s.insert(h);
			}
		}
		if(s.size() > k){
			cout<<-1<<endl;
		} else {
			if(v.size() < k){
				for(int i = v.size() ; i < k ; i++){
					v.push_back(v[0]);
				}
			}
			cout<<10000<<endl;
			for(int i = 0 ; i < v.size() ; i++){
				for(int j = i ; j < 10000 ; j += k){
					ans[j] = v[i];
				}
			}
			for(int i = 0 ; i < 10000 ; i++){
				cout<<ans[i]<<" ";
			}
			cout<<endl;
		}
		v.clear();
		s.clear();
	}
	return 0;
}