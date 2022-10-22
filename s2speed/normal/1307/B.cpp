#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	
	ll t;
	cin>>t;
	while(t--){
		bool one = false;
		ll n , x , m = 0;
		cin>>n>>x;
		for(int i = 0 ; i < n ; i++){
			ll inp;
			cin>>inp;
			if(inp == x){
				one = true;
			}
			m = max(m , inp);
		}
		ll q = (x + m - 1) / m;
		if(one == true){
			cout<<"1\n";
			continue;
		} else if(q == 1){
			q++;
		}
		cout<<q<<"\n";
	}
	return 0;
}