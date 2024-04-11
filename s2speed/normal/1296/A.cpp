#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	ll t , n , a , z , f;
	cin>>t;
	while(t > 0){
		z = 0;
		f = 0;
		cin>>n;
		for(int i = 0 ; i < n ; i++){
			cin>>a;
			if(a % 2 == 0){
				z++;
			} else {
				f++;
			}
		}
		if(z > 0 && f > 0){
			cout<<"YES"<<endl;
		} else if(f % 2 == 1){
			cout<<"YES"<<endl;
		} else {
			cout<<"NO"<<endl;
		}
		t--;
	}
	return 0;
}