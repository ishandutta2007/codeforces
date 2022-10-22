#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll t , n , a[100000];
	cin>>t;
	while(t--){
		cin>>n;
		if(n % 4 == 2){
			cout<<"NO"<<endl;
			continue;
		} else {
			cout<<"YES\n";
		}
		for(int i = 0 ; i < n / 2 ; i++){
			a[i] = i * 2 + 2;
			cout<<a[i]<<" ";
		}
		for(int i = 0 ; i < n / 4 ; i++){
			cout<<a[i] - 1<<" ";
		}
		for(int i = n / 4 ; i < n / 2 ; i++){
			cout<<a[i] + 1<<" ";
		}
		cout<<endl;
	}
	return 0;
}