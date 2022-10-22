#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll n , m , t;
	cin>>t;
	while(t > 0){
		cin>>n>>m;
		if(n % m == 0){
			cout<<"YES"<<endl;
		} else {
			cout<<"NO"<<endl;
		}
		t--;
	}
	return 0;
}