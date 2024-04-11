#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll t , n;
	cin>>t;
	while(t--){
		cin>>n;
		ll h;
		vector<ll> v , ans;
		for(int i = 0 ; i < n ; i++){
			cin>>h;
			v.push_back(h);
			ans.push_back(0);
		}
		sort(v.begin() , v.end());
		for(int i = 0 ; i < (n + 1) / 2 ; i++){
			ans[i * 2] = v[i];
		}
		for(int i = (n + 1) / 2 , j = n - 1 ; i < n ; i++ , j--){
			ans[(i - (n + 1) / 2) * 2 + 1] = v[j];
		}
		reverse(ans.begin() , ans.end());
		for(int i = 0 ; i < n ; i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
		v.clear();
		ans.clear();
	}
	return 0;
}