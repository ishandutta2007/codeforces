#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	ll q;
	cin>>q;
	while(q > 0){
		ll n , m , a , b , x;
		bool ch = true;
		cin>>n>>m;
		a = m;
		b = m;
		x = 0;
		while(n > 0){
			ll t , l , h;
			cin>>t>>l>>h;
			if(l - b > t - x || a - h > t - x){
				ch = false;
			}
			a = max(a - (t - x) , l);
			b = min(b + (t - x) , h);
			x = t;
			n--;
		}
		if(ch == true){
			cout<<"YES"<<endl;
		} else {
			cout<<"NO"<<endl;
		}
		q--;
	}
}