#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	ll t , a , b;
	cin>>t;
	while(t > 0){
		cin>>a>>b;
		if(b == a){
			cout<<0<<endl;
		}
		else if(a < b){
			if(a % 2 != b % 2){
				cout<<1<<endl;
			} else {
				cout<<2<<endl;
			}
		} else {
			if(a % 2 == b % 2){
				cout<<1<<endl;
			} else {
				cout<<2<<endl;
			}
		}
		t--;
	}
	return 0;
}