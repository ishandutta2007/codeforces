#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

ll tav(ll n , ll k){
	if(k == 0){
		return 1;
	}
	ll x = tav(n , k / 2);
	if(k % 2 == 0){
		return x * x;
	} else {
		return x * x * n;
	}
}

const ll z = 0;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll n , x = 1 , y = 1;
	cin>>n;
	cout<<n * 3 + 4<<"\n";
	cout<<"0 0\n1 0\n0 1\n1 1\n";
	for(int i = 0 ; i < n ; i++){
		cout<<x + 1<<" "<<y<<"\n"<<x<<" "<<y + 1<<"\n"<<x + 1<<" "<<y + 1<<"\n";
		x++;
		y++;
	}
	return 0;
}