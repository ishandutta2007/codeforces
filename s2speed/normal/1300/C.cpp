#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

ll tav(ll a){
	ll t = 1;
	while(a > 0){
		t *= 2;
		a--;
	}
	return t;
}

int main(){
	bool b = false;
	ll n , h , s = 0 , v[100000];
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		cin>>h;
		v[i] = h;
	}
	for(int j = 31 ; j >= 0 ; j--){
		for(int i = 0 ; i < n ; i++){
			if((v[i] / tav(j)) % 2 == 1){
				if(b == true){
					b = false;
					break;
				}
				b = true;
				s = i;
			}
		}
		if(b == true){
			break;
		}
	}
	cout<<v[s]<<" ";
	for(int i = 0 ; i < n ; i++){
		if(i != s){
			cout<<v[i]<<" ";
		}
	}
	cout<<endl;
	return 0;
}