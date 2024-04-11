#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	ll n , k , m;
	cin>>n>>m>>k;
	if(n <= m && n <= k){
		cout<<"YES"<<endl;
	} else {
		cout<<"NO"<<endl;
	}
	return 0;
}