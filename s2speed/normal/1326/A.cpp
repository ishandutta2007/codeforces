#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll t , n;
	cin>>t;
	while(t > 0){
		cin>>n;
		if(n == 1){
			cout<<-1<<endl;
		} else {
			cout<<"2";
			for(int i = 1 ; i < n ; i++){
				cout<<"3";
			}
			cout<<endl;
		}
		t--;
	}
	return 0;
}