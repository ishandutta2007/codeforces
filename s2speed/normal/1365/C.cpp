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

ll sm2(ll n){
	ll counter = 0 , h = 1;
	while(h <= n){
		counter++;
		h *= 2;
	}
	counter--;
	return counter;
}

const ll z = 0;
ll a[200000][2];
vector<ll> v;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll n , h;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		v.push_back(0);
	}
	for(int i = 0 ; i < n ; i++){
		cin>>h;
		a[h - 1][0] = i;
	}
	for(int i = 0 ; i < n ; i++){
		cin>>h;
		a[h - 1][1] = i;
	}
	for(int i = 0 ; i < n ; i++){
		h = (a[i][0] - a[i][1] + n) % n;
		v[h]++;
	}
	sort(v.begin() , v.end());
	cout<<v[n - 1]<<endl;
	return 0;
}