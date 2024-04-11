#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	ll t , a , b , x , y , ans , hx , hy;
	cin>>t;
	while(t > 0){
		cin>>a>>b>>x>>y;
		hx = max(a - 1 - x , x - 0);
		hy = max(b - 1 - y , y - 0);
		ans = max(hy * a , hx * b);
		cout<<ans<<endl;
		t--;
	}
	return 0;
}