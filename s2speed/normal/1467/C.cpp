#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define gcd __gcd 
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
struct piii {
	int first , second , third;
};

const ll MAX_N = 5e3 + 20 , md = 1e9 + 7;
 
ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n;
		}
		n *= n;
		k /= 2;
	}
	return res;
}

int main(){ // check MAX_N
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll n1 , n2 , n3 , sum1 = 0 , sum2 = 0 , sum3 = 0 , min1 = 1e9 , min2 = 1e9 , min3 = 1e9 , sum = 0 , k = 1e9;
	cin>>n1>>n2>>n3;
	for(int i = 0 ; i < n1 ; i++){
		ll h;
		cin>>h;
		min1 = min(min1 , h);
		sum1 += h;
	}
	sum += sum1;
	for(int i = 0 ; i < n2 ; i++){
		ll h;
		cin>>h;
		min2 = min(min2 , h);
		sum2 += h;
	}
	sum += sum2;
	for(int i = 0 ; i < n3 ; i++){
		ll h;
		cin>>h;
		min3 = min(min3 , h);
		sum3 += h;
	}
	sum += sum3;
	k = min(k , sum1);
	k = min(k , sum2);
	k = min(k , sum3);
	k = min(k , min1 + min2);
	k = min(k , min1 + min3);
	k = min(k , min2 + min3);
	sum -= 2ll * k;
	cout<<sum<<'\n';
	return 0;
}