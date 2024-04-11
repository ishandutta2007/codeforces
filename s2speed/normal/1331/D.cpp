#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll n;
	string s;
	cin>>s;
	n = s[6] - '0';
	cout<<n % 2<<endl;
	return 0;
}