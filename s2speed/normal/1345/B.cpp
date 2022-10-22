#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

ll h[100000] , o;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	h[0] = 2;
	for(int i = 1 ; i < 1000000 ; i++){
		h[i] = h[i - 1] + i * 3 + 2;
		if(h[i] > 1e9){
			o = i - 1;
			break;
		}
	}
	ll t , n;
	cin>>t;
	while(t--){
		ll counter = 0;
		cin>>n;
		for(int i = o ; i >= 0 ; i--){
			while(n >= h[i]){
				counter++;
				n -= h[i];
			}
		}
		cout<<counter<<endl;
	}
	return 0;
}