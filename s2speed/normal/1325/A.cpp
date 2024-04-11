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
		cout<<1<<" "<<n - 1<<endl;
		t--;
	}
	return 0;
}