#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	ll t , n;
	cin>>t;
	while(t > 0){
		ll m , a , h;
		cin>>n>>m>>a;
		for(int i = 1 ; i < n ; i++){
			cin>>h;
			a += h;
		}
		cout<<min(a , m)<<endl;
		t--;
	}
	return 0;
}