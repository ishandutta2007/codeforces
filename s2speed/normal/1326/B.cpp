#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll n , h , a;
	cin>>n>>h;
	cout<<h<<" ";
	a = h;
	for(int i = 1 ; i < n ; i++){
		cin>>h;
		cout<<a + h<<" ";
		a = max(a , a + h);
	}
	return 0;
}