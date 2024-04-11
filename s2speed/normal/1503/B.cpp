#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<ll , pll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 2e5 + 16 , md = 1e9 + 7 , inf = 2e18;

int main(){ // check MAXN
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll j , q , n , lm;
	pll a = {1 , 1} , b = {1 , 2};
	bool k = false;
	cin>>n;
	lm = n * n; j = lm;
	for(ll i = 0 ; i < lm ; i++){
		cin>>q;
		if(q % 2){
			cout<<"2 "<<b.first<<' '<<b.second<<endl;
			if(b.second == n){
				b.first++;
				b.second = n % 2 + 1;
			} else if(b.second == n - 1){
				b.first++;
				b.second = (n + 1) % 2 + 1;
			} else {
				b.second += 2;
			}
		} else {
			cout<<"1 "<<a.first<<' '<<a.second<<endl;
			if(a.second == n){
				a.first++;
				a.second = n % 2 + 1;
			} else if(a.second == n - 1){
				a.first++;
				a.second = (n + 1) % 2 + 1;
			} else {
				a.second += 2;
			}
		}
		if(a.first > n){
			j = i + 1;
			k = true;
			break;
		}
		if(b.first > n){
			j = i + 1;
			break;
		}
	}
	for(; j < lm ; j++){
		cin>>q;
		if(k){
			if(q == 2){
				cout<<"3 "<<b.first<<' '<<b.second<<endl;
			} else {
				cout<<"2 "<<b.first<<' '<<b.second<<endl;
			}
			if(b.second == n){
				b.first++;
				b.second = n % 2 + 1;
			} else if(b.second == n - 1){
				b.first++;
				b.second = (n + 1) % 2 + 1;
			} else {
				b.second += 2;
			}
		} else {
			if(q == 1){
				cout<<"3 "<<a.first<<' '<<a.second<<endl;
			} else {
				cout<<"1 "<<a.first<<' '<<a.second<<endl;
			}
			if(a.second == n){
				a.first++;
				a.second = n % 2 + 1;
			} else if(a.second == n - 1){
				a.first++;
				a.second = (n + 1) % 2 + 1;
			} else {
				a.second += 2;
			}
		}
	}
	return 0;
}