#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll t;
	cin>>t;
	while(t--){
		bool fin = false;
		ll n , l , r , x = 0 , u;
		cin>>n>>l>>r;
		for(ll i = 1 ; i < n ; i++){
			if(l > x + (n - i) * 2){
				x += (n - i) * 2;
			} else {
				fin = true;
				u = l - x;
				u = (u + 1) / 2;
				u += i;
				for(ll c = l ; c <= r ; c++){
					if(c == n * (n - 1) + 1){
						cout<<1<<" ";
						break;
					}
					if(u == n + 1){
						x += (n - i) * 2;
						i++;
						u = i + 1;
					}
					if(c % 2 == 1){
						cout<<i<<" ";
					} else {
						cout<<u<<" ";
						u++;
					}
				}
			}
			if(fin == true){
				cout<<endl;
				break;
			}
		}
		if(l == n * (n - 1) + 1){
			cout<<1<<endl;
		}
	}
	return 0;
}