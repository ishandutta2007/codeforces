#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll t;
	cin>>t;
	while(t--){
		ll n , x , h , sum = 0 , ans;
		vector<ll> v;
		cin>>n>>x;
		for(int i = 0 ; i < n ; i++){
			cin>>h;
			v.push_back(h);
		}
		sort(v.begin() , v.end());
		reverse(v.begin() , v.end());
		for(int i = 0 ; i < n ; i++){
			sum += v[i];
			if(sum / (i + 1) < x){
				ans = i;
				break;
			}
			if(i == n - 1){
				ans = n;
			}
		}
		cout<<ans<<endl;
		v.clear();
	}
	return 0;
}