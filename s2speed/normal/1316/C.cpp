#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n , m , p , h , a , b;
	cin>>n>>m>>p;
	bool f = true;
	for(int i = 0 ; i < n ; i++){
		cin>>h;
		if(h % p != 0 && f == true){
			a = i;
			f = false;
		}
	}
	f = true;
	for(int i = 0 ; i < m ; i++){
		cin>>h;
		if(h % p != 0 && f == true){
			b = i;
			f = false;
		}
	}
	cout<<a + b<<endl;
	return 0;
}