#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll t , n , a[29] , o = 4;
	a[0] = 3;
	for(int i = 1 ; i < 29 ; i++ , o *= 2){
		a[i] = a[i - 1] + o;
	}
	cin>>t;
	while(t--){
		cin>>n;
		for(int i = 0 ; i < n ; i++){
			if(n % a[i] == 0){
				cout<<n / a[i]<<endl;
				break;
			}
		}
	}
	return 0;
}