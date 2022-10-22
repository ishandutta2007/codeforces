#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll t;
	cin>>t;
	while(t--){
		ll a , b , aa , bb;
		cin>>a>>b>>aa>>bb;
		if(max(a , b) == max(aa , bb) && min(a , b) + min(aa , bb) == max(a , b)){
			cout<<"YES"<<endl;
		} else {
			cout<<"NO"<<endl;
		}
	}
	return 0;
}