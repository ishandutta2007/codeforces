#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	ll t;
	cin>>t;
	while(t > 0){
		ll n , a , b , ans , m , d;
		cin>>n>>a;
		if(a == 0){
			cout<<0<<endl;
			t--;
			continue;
		}
		b = n - a;
		ans = n * (n + 1) / 2;
		m = b % (a + 1);
		d = b / (a + 1);
		ans -= ((d + 1) * (d + 2) / 2) * m;
		ans -= (d * (d + 1) / 2) * (a - m + 1);
		cout<<ans<<endl;
		t--;
	}
	return 0;
}