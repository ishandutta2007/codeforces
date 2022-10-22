#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

ll a[300000] , b[300000];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll t;
	cin>>t;
	while(t--){
		ll n , suma , sumb = 0 , ans = 0;
		vector<ll> v;
		cin>>n;
		cin>>a[0]>>b[0];
		suma= a[0];
		for(int i = 1 ; i < n ; i++){
			cin>>a[i]>>b[i];
			suma += a[i];
			b[i - 1] = min(a[i] , b[i - 1]);
			v.push_back(b[i - 1]);
			sumb += b[i - 1];
		}
		b[n - 1] = min(b[n - 1] , a[0]);
		v.push_back(b[n - 1]);
		sort(v.begin() , v.end());
		sumb += b[n - 1];
		ans = suma - sumb + v[0];
		cout<<ans<<endl;
		v.clear();
	}
	return 0;
}