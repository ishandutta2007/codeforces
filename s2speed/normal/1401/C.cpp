#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

vector<ll> v , im;
ll a[100000];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll t;
	cin>>t;
	while(t--){
		bool ans = true;
		ll n , ims;
		cin>>n;
		for(int i = 0 ; i < n ; i++){
			cin>>a[i];
			v.push_back(a[i]);
		}
		sort(v.begin() , v.end());
		for(int i = 0 ; i < n ; i++){
			if(a[i] % v[0] != 0) im.push_back(i);
		}
		ims = im.size();
		for(int i = 0 ; i < ims ; i++){
			if(a[im[i]] != v[im[i]]){
				ans = false;
				break;
			}
		}
		if(ans == true){
			cout<<"YES\n";
		} else {
			cout<<"NO\n";
		}
		v.clear(); im.clear();
	}
	return 0;
}