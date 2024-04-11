#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	ll t;
	cin>>t;
	while(t > 0){
		string a , b , c;
		bool ans = true;
		cin>>a>>b>>c;
		for(int i = 0 ; i < a.size() ; i++){
			if(c[i] != b[i] && c[i] != a[i]){
				ans = false;
				break;
			}
		}
		if(ans == true){
			cout<<"YES"<<endl;
		} else {
			cout<<"NO"<<endl;
		}
		t--;
	}
	return 0;
}