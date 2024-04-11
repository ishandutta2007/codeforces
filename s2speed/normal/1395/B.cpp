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
	
	ll n , m , x , y;
	cin>>n>>m>>x>>y;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			cout<<x<<" "<<y<<"\n";
			y++;
			if(y == m + 1) y = 1;
		}
		y--;
		if(y == 0) y = m;
		x++;
		if(x == n + 1) x = 1;
	}
	return 0;
}