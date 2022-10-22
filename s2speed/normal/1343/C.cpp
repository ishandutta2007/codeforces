#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll t , n;
	cin>>t;
	while(t--){
		ll sum = 0 , m , h;
		cin>>n;
		cin>>h;
		m = h;
		for(int i = 1 ; i < n ; i++){
			cin>>h;
			if((h > 0 && m > 0) || (h < 0 && m < 0)){
				m = max(m , h);
			} else {
				sum += m;
				m = h;
			}
		}
		sum += m;
		cout<<sum<<endl;
	}
	return 0;
}