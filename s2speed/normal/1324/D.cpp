#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll n , a[200000] , b , counter = 0 , ans = 0 , vize;
	vector<ll> v , m; 
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	for(int i = 0 ; i < n ; i++){
		cin>>b;
		ll h = a[i] - b;
		if(h > 0){
			v.push_back(h);
		} else if(h < 0){
			m.push_back(0 - h);
		} else {
			counter++;
		}
	}
	vize = v.size();
	ans += vize * (vize - 1) / 2 + counter * vize;
	sort(v.begin() , v.end());
	sort(m.begin() , m.end());
	ll j = 0;
	for(int i = 0 ; i < v.size() ; i++){
		for( ; j < m.size() ; j++){
			if(v[i] <= m[j]){
				break;
			}
		}
		ans += j;
	}
	cout<<ans<<endl;
	return 0;
}