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

const ll MAXN = 5e2 + 15 , md = 1e9 + 7 , inf = 2e15;

ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n; res %= md;
		}
		n *= n; n %= md;
		k >>= 1;
	}
	return res;
}

vector<piii> v;
ll k[MAXN];

int main(){ // check MAXN
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>k[i];
	}
	for(ll i = 0 ; i < n ; i++){
		for(ll j = i + 1 ; j < n ; j++){
			pll p = {i , j};
			if(k[i] < k[j]) p = {j , i};
			v.push_back({abs(k[i] - k[j]) , p});
		}
	}
	string s;
	sort(all(v) , greater<piii>());
	for(auto q : v){
		ll i = q.second.first , j = q.second.second;
		cout<<"? "<<i + 1<<' '<<j + 1<<endl;
		cin>>s;
		if(s[0] == 'Y'){
			cout<<"! "<<i + 1<<' '<<j + 1<<'\n';
			return 0;
		}
	}
	cout<<"! 0 0\n";
	return 0;
}